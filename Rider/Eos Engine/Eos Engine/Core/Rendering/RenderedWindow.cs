using Eos_Engine;
using Eos_Engine.Core.IO;
using Eos_Engine.Objects;
using Eos_Engine.Structures;
using Eos_Engine.Structures.Scenes;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.Desktop;
using OpenTK.Windowing.GraphicsLibraryFramework;
using OpenTK.Graphics.OpenGL;
using OpenTK.Mathematics;

namespace Eos_Engine.Rendering
{
    public class RenderedWindow: GameWindow
    {
        private static readonly Color4 FrameClearColor = new Color4(0, 180, 0, 255);

        public static Vector2 ScreenSize; 
        private Scene? scene;

        
        public RenderedWindow(int width, int height, string title)
            : base(
                GameWindowSettings.Default,
                new NativeWindowSettings()
                {
                    Title = title,
                    Size = new Vector2i(width, height),
                    WindowBorder = WindowBorder.Fixed,
                    StartVisible = true,
                    StartFocused = true,
                    API = ContextAPI.OpenGL,
                    Profile = ContextProfile.Core,
                    APIVersion = new Version(3, 3)
                })
        {
            GL.Enable(EnableCap.Texture2D);
            GL.Enable(EnableCap.Blend);
            GL.BlendFunc(BlendingFactor.SrcAlpha, BlendingFactor.OneMinusSrcAlpha);
            ScreenSize = new Vector2(width, height);
            CenterWindow();
        }

        protected override void OnResize(ResizeEventArgs e)
        {
            GL.Viewport(0, 0, e.Width, e.Height);
            ScreenSize = e.Size;
            base.OnResize(e);
        }

        protected override void OnLoad()
        {
            GL.ClearColor(FrameClearColor);

            scene = new Scene();

            VertShader vertShader = scene.GenerateInternalVertShader("TextureShader");
            FragShader fragShader = scene.GenerateInternalFragShader("TextureShader");

            int texture = TextureImporter.Loadtexture2D(@"Internal\Textures\Test.png");
            ShaderProgram shaderProgram = scene.GenerateShaderProgram(vertShader, fragShader, texture);
            
            int[] viewport = new int[4];
            GL.GetInteger(GetPName.Viewport, viewport);
            
            GL.UseProgram(shaderProgram.ShaderProgramHandle);
            int viewportSizeUniformLocation = GL.GetUniformLocation(shaderProgram.ShaderProgramHandle, "ViewportSize");
            GL.Uniform2(viewportSizeUniformLocation, (float)viewport[2], (float)viewport[3]);
            GL.UseProgram(0);
            
            scene.CreateSprite(200, 200, 300, 300, shaderProgram);
            scene.CreateSprite(500, 400, 100, 100, shaderProgram);
            scene.CreateSprite(700, 100, 64, 64, shaderProgram);

            scene.CreateSprite(20, 20, 50, 50, shaderProgram);

            base.OnLoad();
        }

        protected override void OnUnload()
        {
            scene?.Dispose();
            
            base.OnUnload();
        }

        protected override void OnUpdateFrame(FrameEventArgs args)
        {
            base.OnUpdateFrame(args);

            KeyboardState inputState = KeyboardState.GetSnapshot();

            if (inputState.IsKeyDown(Keys.Escape))
            {
                Close();
            }

        }

        protected override void OnRenderFrame(FrameEventArgs args)
        {
            GL.Clear(ClearBufferMask.ColorBufferBit);
            
            scene?.Draw();
            
            Context.SwapBuffers();
            base.OnRenderFrame(args);
        }
    }
}