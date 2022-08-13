using OpenTK.Mathematics;

namespace Eos_Engine.Structures
{
    public readonly struct VertexAttribute
    {
        public readonly string Name;
        public readonly int Index;
        public readonly int ComponentCount;
        public readonly int Offset;

        public VertexAttribute(int offset, int componentCount, int index, string name)
        {
            Offset = offset;
            ComponentCount = componentCount;
            Index = index;
            Name = name;
        }
    }
    
    public sealed class VertexInfo
    {
        public readonly Type Type;
        public readonly int SizeBytes;
        public readonly VertexAttribute[] VertexAttributes;

        public VertexInfo( Type type, VertexAttribute[] vertexAttributes)
        {
            Type = type;
            SizeBytes = 0;
            VertexAttributes = vertexAttributes;

            for (int i = 0; i < VertexAttributes.Length; i++)
            {
                SizeBytes += VertexAttributes[i].ComponentCount * sizeof(float);
            }
        }
    }
    
    public readonly struct VertexPositionColor
    {
        public readonly Vector2 Position;
        public readonly Color4 Color;

        public static readonly VertexInfo VertexInfo = new VertexInfo(
            typeof(VertexPositionColor),
            new[]
            {
                new VertexAttribute(0, 2, 0, "Position"),
                new VertexAttribute(2 * sizeof(float), 4, 1, "Color")
            }
        );

        public VertexPositionColor(Vector2 position, Color4 color)
        {
            Position = position;
            Color = color;
        }
    }

    public readonly struct VertexPositionTexture
    {
        public readonly Vector2 Position;
        public readonly Vector2 TexCoord;

        public static readonly VertexInfo VertexInfo = new VertexInfo(
            typeof(VertexPositionTexture),
            new[]
            {
                new VertexAttribute(0, 2, 0, "Position"),
                new VertexAttribute(2 * sizeof(float), 2, 1, "TexCoord")
            });

        public VertexPositionTexture(Vector2 position, Vector2 texCoord)
        {
            Position = position;
            TexCoord = texCoord;
        }
    }
}