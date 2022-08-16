#pragma once
#include <string>

class ShaderLoader
{
public:
	static std::string LoadInternalVertShader(std::string shaderName);
	static std::string LoadInternalFragShader(std::string shaderName);

private:
	static std::string ReadFileAsText(std::string path);
};
