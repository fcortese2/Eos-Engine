#pragma once
#include <GLFW/glfw3.h>

class Eos_Core;

class Eos_Editor
{
public:
	static void Render(Eos_Core* core, GLFWwindow* window);
};
