#pragma once
#include <GLFW/glfw3.h>
#include "Structure/scene.h"
#include "../Core/Structure/asset_manager.h"

#define EOS_EDITOR

class Eos_Core
{
public:
	Eos_Core(int windowWidth, int windowHeight);

	void Renderer_Init();

	Scene* CurrentScene() { return &scene; }
	float DeltaTime() { return deltaTime; }

	ShaderProgram* CreateShader(const char* vertShaderPath, const char* fragShaderPath);

	TextureLoader TextureLoader;
	AssetManager AssetManager;

private:
	GLFWwindow* window;
	int win_width, win_height;
	float lastFrame = 0, deltaTime = 0;

	std::list<ShaderProgram> shadersList;

	Scene scene;

	void processInput(GLFWwindow* window);

	void GUI_Init();
	void gameLoop();
	void DrawEditor();
	void EndIMGUIFrame();

	void Cleanup();
};
