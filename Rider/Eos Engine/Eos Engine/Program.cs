using Eos_Engine.Rendering;
using OpenTK.Mathematics;
using OpenTK.Windowing.Desktop;

namespace Eos_Engine
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            using (RenderedWindow window = new RenderedWindow(1280, 768, "Rendered Window"))
            {
                window.Run();
            }
        }
    }
}