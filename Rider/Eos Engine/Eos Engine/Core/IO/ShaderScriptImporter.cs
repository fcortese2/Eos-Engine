namespace Eos_Engine.Core.IO;

public static class ShaderScriptImporter
{

    public static string ReadVertShader(string pathInProject)
    {
        string path = @$"{Environment.CurrentDirectory}\{pathInProject}.vert";
        Console.WriteLine(path);
        string source = File.ReadAllText(path);
        return source;
    }
    
    public static string ReadInternalVertShader(string shaderName)
    {
        string path = @$"{Environment.CurrentDirectory}\Internal\Shaders\{shaderName}.vert";
        Console.WriteLine(path);
        string source = File.ReadAllText(path);
        return source;
    }

    public static string ReadFragShader(string pathInProject)
    {
        string path = @$"{Environment.CurrentDirectory}\{pathInProject}.frag";
        Console.WriteLine(path);
        string source = File.ReadAllText(path);
        return source;
    }

    public static string ReadInternalFragShader(string shaderName)
    {
        string path = @$"{Environment.CurrentDirectory}\Internal\Shaders\{shaderName}.frag";
        Console.WriteLine(path);
        string source = File.ReadAllText(path);
        return source;
    }
}