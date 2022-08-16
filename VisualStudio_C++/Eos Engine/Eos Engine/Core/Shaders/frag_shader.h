#pragma once
#include <string>


class FragShader
{
public:
	FragShader(std::string shaderName);
	~FragShader();
	void Destroy();

	unsigned int FragShaderHandle;
private:
	void Build(const char* source);
	bool destroyed;
};
