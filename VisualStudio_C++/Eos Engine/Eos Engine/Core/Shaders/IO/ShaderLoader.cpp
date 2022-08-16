#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>

#include "shader_loader.h"

std::string ShaderLoader::LoadInternalFragShader(std::string shaderName)
{
	char path[255];
	GetCurrentDirectoryA(255, path);

	std::string completePath = std::string(path) + R"(\Internal\Shaders\)" + shaderName + R"(.frag)";

	return ReadFileAsText(completePath);
}

std::string ShaderLoader::LoadInternalVertShader(std::string shaderName)
{
	char path[255];
	GetCurrentDirectoryA(255, path);

	std::string completePath = std::string(path) + R"(\Internal\Shaders\)" + shaderName + R"(.vert)";

	return ReadFileAsText(completePath);
}

std::string ShaderLoader::ReadFileAsText(std::string path)
{
	std::string source;
	std::ifstream sourceFile;

	sourceFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);

	try
	{
		sourceFile.open(path);

		std::stringstream shaderStream;

		shaderStream << sourceFile.rdbuf();
		sourceFile.close();

		source = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	return source;
}