#pragma once
#include <string>

class VertShader
{
public:
	VertShader(std::string shaderName);
	~VertShader();
	void Destroy();

	unsigned int VertShaderHandle = -1;
private:
	void Build(const char* source);
	bool destroyed;
};
