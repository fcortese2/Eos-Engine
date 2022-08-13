using OpenTK.Graphics.OpenGL;

namespace Eos_Engine.Rendering
{
    public class ShaderProgram: IDisposable
    {
        private bool disposed;

        public readonly VertShader VertShader;
        public readonly FragShader FragShader;

        public int TextureID;
        
        public readonly int ShaderProgramHandle;

        public ShaderProgram(VertShader vertShader, FragShader fragShader, int textureId)
        {
            if (vertShader is null)
            {
                throw new ArgumentNullException(nameof(vertShader));
            }
            
            if (fragShader is null)
            {
                throw new ArgumentNullException(nameof(fragShader));
            }

            TextureID = textureId;
            
            VertShader = vertShader;
            FragShader = fragShader;
            
            ShaderProgramHandle = GL.CreateProgram();
            
            GL.AttachShader(ShaderProgramHandle, vertShader.VertShaderHandle);
            GL.AttachShader(ShaderProgramHandle, fragShader.FragShaderHandle);
            GL.LinkProgram(ShaderProgramHandle);
            
            
        }

        public int GetUniform(string uniformName)
        {
            GL.UseProgram(ShaderProgramHandle);
            int id = GL.GetUniformLocation(ShaderProgramHandle, uniformName);
            GL.UseProgram(0);
            return id;
        }
        
        ~ShaderProgram()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (disposed)
            {
                return;
            }
            
            GL.DetachShader(ShaderProgramHandle, VertShader.VertShaderHandle);
            GL.DetachShader(ShaderProgramHandle, FragShader.FragShaderHandle);

            disposed = true;
            GC.SuppressFinalize(this);
        }
    }
}