using Eos_Engine.Core.IO;
using Eos_Engine.Objects;
using Eos_Engine.Rendering;

namespace Eos_Engine.Structures.Scenes
{
    public class Scene: IDisposable
    {
        private bool disposed;
        
        private List<SpriteRenderer> Sprites = new List<SpriteRenderer>();

        private List<ShaderProgram> ShaderPrograms = new List<ShaderProgram>();

        private List<VertShader> VertShaders = new List<VertShader>();

        private List<FragShader> FragShaders = new List<FragShader>();

        public Scene()
        {
            disposed = false;
        }
        
        public SpriteRenderer CreateSprite(float x, float y, float w, float h, ShaderProgram shaderProgramHandle)
        {
            SpriteRenderer newRenderer = new SpriteRenderer(x, y, w, h, shaderProgramHandle); 
            Sprites.Add(newRenderer);
            return newRenderer;
        }
        
        public VertShader GenerateInternalVertShader(string shaderName)
        {
            VertShader newShader = new VertShader(ShaderScriptImporter.ReadInternalVertShader(shaderName));
            VertShaders.Add(newShader);
            return newShader;
        }
        
        public VertShader GenerateVertShader(string shaderPath)
        {
            VertShader newShader = new VertShader(ShaderScriptImporter.ReadVertShader(shaderPath));
            VertShaders.Add(newShader);
            return newShader;
        }

        public FragShader GenerateInternalFragShader(string shaderName)
        {
            FragShader newShader = new FragShader(ShaderScriptImporter.ReadInternalFragShader(shaderName));
            FragShaders.Add(newShader);
            return newShader;
        }
        
        public FragShader GenerateFragShader(string shaderPath)
        {
            FragShader newShader = new FragShader(ShaderScriptImporter.ReadFragShader(shaderPath));
            FragShaders.Add(newShader);
            return newShader;
        }

        public ShaderProgram GenerateShaderProgram(VertShader vertShader, FragShader fragShader, int textureID)
        {
            ShaderProgram newProg = new ShaderProgram(vertShader, fragShader, textureID);
            ShaderPrograms.Add(newProg);
            return newProg;
        }
        

        public void Draw()
        {
            for (int i = 0; i < Sprites.Count; i++)
            {
                Sprites[i].Draw();
            }
        }

        ~Scene()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (disposed)
            {
                return;
            }

            for (int i = 0; i < ShaderPrograms.Count; i++)
            {
                ShaderPrograms[i].Dispose();
            }

            for (int i = 0; i < VertShaders.Count; i++)
            {
                VertShaders[i].Dispose();
            }

            for (int i = 0; i < FragShaders.Count; i++)
            {
                FragShaders[i].Dispose();
            }

            for (int i = 0; i < Sprites.Count; i++)
            {
                Sprites[i].Dispose();
            }

            disposed = true;
            GC.SuppressFinalize(this);
        }
    }
}