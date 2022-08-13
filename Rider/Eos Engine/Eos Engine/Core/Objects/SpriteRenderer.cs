using Eos_Engine.Rendering;
using Eos_Engine.Structures;
using OpenTK.Graphics.OpenGL;
using OpenTK.Mathematics;
using GL = OpenTK.Graphics.OpenGL.GL;

namespace Eos_Engine.Objects
{
    public class SpriteRenderer: IDisposable
    {
        private bool disposed;
        
        private float x;
        private float y;
        private float w;
        private float h;

        private VertexPositionTexture[] verts;
        
        public readonly VertexBuffer vertexBuffer;
        public readonly VertexArray vertexArray;
        public readonly IndexBuffer indexBuffer;
        
        public readonly ShaderProgram ShaderProgram;
        
        int[] indices = new[]
        {
            0, 1, 2,
            0, 2, 3
        };

        public SpriteRenderer(float x, float y, float w, float h, ShaderProgram shaderProgram)
        {
            disposed = false;
            
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;

            ShaderProgram = shaderProgram;
            
            /*verts = new []
            {
                new VertexPositionColor(new Vector2(x, y + h), new Color4(255, 0, 0, 255)),
                new VertexPositionColor(new Vector2(x + w, y + h), new Color4(0, 255, 0, 255)),
                new VertexPositionColor(new Vector2(x + w, y), new Color4(0, 0, 255, 255)),
                new VertexPositionColor(new Vector2(x, y), new Color4(255, 0, 255, 255))
            };*/

            verts = new[]
            {
                new VertexPositionTexture(new Vector2(x, y + h), new Vector2(0, 1)),
                new VertexPositionTexture(new Vector2(x + w, y + h), new Vector2(1, 1)),
                new VertexPositionTexture(new Vector2(x + w, y), new Vector2(1, 0)),
                new VertexPositionTexture(new Vector2(x, y), new Vector2(0, 0))
            };
            
            vertexBuffer = new VertexBuffer(VertexPositionTexture.VertexInfo, verts.Length, true);
            vertexBuffer.SetData(verts, verts.Length);

            indexBuffer = new IndexBuffer(indices.Length, true);
            indexBuffer.SetData(indices, indices.Length);

            vertexArray = new VertexArray(vertexBuffer);
        }

        public void Draw()
        {
            GL.UseProgram(ShaderProgram.ShaderProgramHandle);
            
            //GL.BindVertexArray(vertexArray.VertexArrayHandle);
            //GL.BindBuffer(BufferTarget.ElementArrayBuffer, indexBuffer.IndexBufferHandle);

            GL.ActiveTexture(TextureUnit.Texture0);
            GL.BindTexture(TextureTarget.Texture2D, ShaderProgram.TextureID);

            GL.BindVertexArray(vertexArray.VertexArrayHandle);
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, indexBuffer.IndexBufferHandle);

            GL.DrawElements(BeginMode.Triangles, 6, DrawElementsType.UnsignedInt, 0);
            
            GL.BindTexture(TextureTarget.Texture2D,0);
            
            
        }

        ~SpriteRenderer()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (disposed)
            {
                return;
            }
            
            vertexArray.Dispose();
            indexBuffer.Dispose();
            vertexBuffer.Dispose();

            disposed = true;
            GC.SuppressFinalize(this);
        }

    }
}