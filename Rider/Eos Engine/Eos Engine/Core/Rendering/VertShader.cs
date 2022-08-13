using OpenTK.Graphics.OpenGL;

namespace Eos_Engine.Rendering
{

    public class VertShader: IDisposable
    {
        private bool disposed;
        
        public readonly int VertShaderHandle;

        private string source;
        
        public VertShader(string shaderSource)
        {
            if (shaderSource is null)
            {
                throw new ArgumentNullException(nameof(shaderSource));
            }

            disposed = false;

            source = shaderSource;
            
            VertShaderHandle = GL.CreateShader(ShaderType.VertexShader);
            GL.ShaderSource(VertShaderHandle, source);
            GL.CompileShader(VertShaderHandle);

            string errorMsg = GL.GetShaderInfoLog(VertShaderHandle);
            if (!string.IsNullOrEmpty(errorMsg))
            {
                throw new FormatException(errorMsg);
            }
        }

        ~VertShader()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (disposed)
            {
                return;
            }
            
            GL.DeleteShader(VertShaderHandle);

            disposed = true;
            GC.SuppressFinalize(this);
        }
    }
}