using OpenTK.Graphics.OpenGL;

namespace Eos_Engine.Rendering
{

    public class FragShader: IDisposable
    {
        private bool disposed;
        
        public readonly int FragShaderHandle;

        private string source;
        
        public FragShader(string shaderSource)
        {
            if (shaderSource is null)
            {
                throw new ArgumentNullException(nameof(shaderSource));
            }

            disposed = false;

            source = shaderSource;
            
            FragShaderHandle = GL.CreateShader(ShaderType.FragmentShader);
            GL.ShaderSource(FragShaderHandle, source);
            GL.CompileShader(FragShaderHandle);

            string errorMsg = GL.GetShaderInfoLog(FragShaderHandle);
            if (!string.IsNullOrEmpty(errorMsg))
            {
                throw new FormatException(errorMsg);
            }
        }
        
        ~FragShader()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (disposed)
            {
                return;
            }
            
            GL.DeleteShader(FragShaderHandle);

            disposed = true;
            GC.SuppressFinalize(this);
        }
    }
}