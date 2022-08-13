using OpenTK.Graphics.OpenGL;

namespace Eos_Engine.Structures
{
    public sealed class VertexBuffer : IDisposable
    {
        private bool disposed;

        
        public readonly int MaxVertexCount = 100000;
        public readonly int MinVertexCount = 1;
        
        public readonly int VertexBufferHandle;
        public readonly VertexInfo VertexInfo;
        public readonly int VertexCount;
        public readonly bool IsStatic;

        public VertexBuffer(VertexInfo vertexInfo, int vertexCount, bool isStatic = true)
        {
            disposed = false;

            if (vertexCount<MinVertexCount || vertexCount>MaxVertexCount)
            {
                throw new IndexOutOfRangeException(nameof(vertexCount));
            }

            VertexCount = vertexCount;
            VertexInfo = vertexInfo;
            IsStatic = isStatic;
            
            VertexBufferHandle = GL.GenBuffer();

            GL.BindBuffer(BufferTarget.ArrayBuffer, VertexBufferHandle);
            GL.BufferData(BufferTarget.ArrayBuffer, VertexCount * VertexInfo.SizeBytes, IntPtr.Zero,
                IsStatic ? BufferUsageHint.StaticDraw : BufferUsageHint.StreamDraw);
            GL.BindBuffer(BufferTarget.ArrayBuffer, 0);
        }

        public void SetData<T>(T[] data, int count) where T : struct
        {
            if (typeof(T) != VertexInfo.Type)
            {
                throw new ArgumentException("Generic Type 'T' does not match the vertex type of the vertex buffer");
            }

            if (data == null)
            {
                throw new ArgumentNullException(nameof(data));
            }

            if (count < 0)
            {
                throw new ArgumentOutOfRangeException(nameof(count));
            }

            if (data.Length <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(data));
            }

            GL.BindBuffer(BufferTarget.ArrayBuffer, VertexBufferHandle);
            GL.BufferSubData(BufferTarget.ArrayBuffer, IntPtr.Zero, count * VertexInfo.SizeBytes, data);
            GL.BindBuffer(BufferTarget.ArrayBuffer, 0);
        }

        ~VertexBuffer()
        {
            this.Dispose();
        }

        public void Dispose()
        {
            if (this.disposed)
            {
                return;
            }

            GL.BindBuffer(BufferTarget.ArrayBuffer, 0);
            GL.DeleteBuffer(VertexBufferHandle);
            
            disposed = true;
            GC.SuppressFinalize(this);
        }
    }
}