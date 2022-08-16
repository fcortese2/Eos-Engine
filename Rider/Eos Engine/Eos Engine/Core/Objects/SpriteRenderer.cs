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

        public Vector2 SpriteNativeSize = new Vector2();
        public Vector2 Position = new Vector2();
        public Vector2 Scale = new Vector2(1f, 1f);
        private Matrix4 ModelMatrix = Matrix4.Identity;

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

            /*verts = new[]
            {
                new VertexPositionTexture(new Vector2(x, y + h), new Vector2(0, 1)),
                new VertexPositionTexture(new Vector2(x + w, y + h), new Vector2(1, 1)),
                new VertexPositionTexture(new Vector2(x + w, y), new Vector2(1, 0)),
                new VertexPositionTexture(new Vector2(x, y), new Vector2(0, 0))
            };*/
            
            verts = new[]
            {
                new VertexPositionTexture(new Vector2(0, h), new Vector2(0, 1)),
                new VertexPositionTexture(new Vector2(w, h), new Vector2(1, 1)),
                new VertexPositionTexture(new Vector2(w, 0), new Vector2(1, 0)),
                new VertexPositionTexture(new Vector2(0, 0), new Vector2(0, 0))
            };
            
            vertexBuffer = new VertexBuffer(VertexPositionTexture.VertexInfo, verts.Length, true);
            vertexBuffer.SetData(verts, verts.Length);

            indexBuffer = new IndexBuffer(indices.Length, true);
            indexBuffer.SetData(indices, indices.Length);

            vertexArray = new VertexArray(vertexBuffer);

            
        }


        public void Draw()
        {
            Matrix4 projection =
                Matrix4.CreateOrthographic(RenderedWindow.ScreenSize.X, RenderedWindow.ScreenSize.Y, -1, 1);
            GL.UniformMatrix4(ShaderProgram.GetUniform("projection"), true, ref projection);
            
            Console.WriteLine(projection);
            
            ModelMatrix = Matrix4.Identity;
            ModelMatrix *= Matrix4.CreateTranslation(Position.X, Position.Y, 0);
            GL.UniformMatrix4(ShaderProgram.GetUniform("model"), true, ref ModelMatrix);
            
            GL.UseProgram(ShaderProgram.ShaderProgramHandle);
            
            Scale = new Vector2(1, 1);
            Position = new Vector2(1f,1f);
            SpriteNativeSize = new Vector2(200, 200);


            /*GL.Uniform2(ShaderProgram.GetUniform("scale"), Scale);
            GL.Uniform2(ShaderProgram.GetUniform("position"), Position);
            GL.Uniform2(ShaderProgram.GetUniform("spriteSize"), SpriteNativeSize);*/

            
            
            //GL.BindVertexArray(vertexArray.VertexArrayHandle);
            //GL.BindBuffer(BufferTarget.ElementArrayBuffer, indexBuffer.IndexBufferHandle);

            GL.ActiveTexture(TextureUnit.Texture0);
            GL.BindTexture(TextureTarget.Texture2D, ShaderProgram.TextureID);

            //gl_Position = mvp * vec4(1.0, 1.0, 1.0);
            
            /*
             * float nx = (aPosition.x / ViewportSize.x) * 2 - 1;
               float ny = (aPosition.y / ViewportSize.y) * 2 - 1;
               gl_Position = vec4(nx, ny, 0.0 , 1.0);
               f_texcoord = TexCoord;
             */
            
            GL.BindVertexArray(vertexArray.VertexArrayHandle);
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, indexBuffer.IndexBufferHandle);

            
            
            GL.DrawElements(BeginMode.Triangles, 6, DrawElementsType.UnsignedInt, 0);
            
            GL.BindTexture(TextureTarget.Texture2D,0);

            GL.UseProgram(0);


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