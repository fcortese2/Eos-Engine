#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include "Eos_core.h"
#include <../Eos Engine/Core/Editor/Eos_editor.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
#ifdef EOS_EDITOR
    glViewport(0, 0, width, height);
#else
    glViewport(0, 0, width, height);
#endif
    
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

Eos_Core::Eos_Core(int windowWidth, int windowHeight): scene(glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f))
{
    win_width = windowWidth;
    win_height = windowHeight;

	if (!glfwInit())
		throw "ERROR:GLFWINIT:FAILED_TO_INITIALIZE_GLFW";

    window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "ERROR:GLFWCREATEWINDOW:FAILED_TO_CREATE_WINDOW";
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
}

void Eos_Core::Renderer_Init()
{
	#ifdef EOS_EDITOR
    std::cout << "INITIALIZING IMGUI" << std::endl;
    GUI_Init();
	#endif


    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR::GLEW::INIT::FAILED_TO_INITIALIZE_GLEW" << std::endl;
        throw "ERROR::GLEWINIT:FAILED_TO_INITIALIZE_GLEW";
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    gameLoop();
}

void Eos_Core::GUI_Init()
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}


void Eos_Core::gameLoop()
{
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);
        
        glClear(GL_COLOR_BUFFER_BIT);

		#ifdef EOS_EDITOR
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
		#endif

        scene.RenderScene();

		#ifdef EOS_EDITOR
        DrawEditor();
        EndIMGUIFrame();
		#endif

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    Cleanup();
}

void Eos_Core::DrawEditor()
{
    Eos_Editor::Render(this, window);
}

void Eos_Core::EndIMGUIFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Eos_Core::Cleanup()
{
    //other GL cleanup here...

	#ifdef EOS_EDITOR
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
	#endif

    glfwTerminate();
}


void Eos_Core::processInput(GLFWwindow* window)
{
    glm::vec3 motion = glm::vec3(0);

    float speed = static_cast<float>(2.5 * deltaTime);

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        motion = motion + glm::vec3(-scene.Camera.CameraRight.x * speed, 0, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        motion = motion + glm::vec3(scene.Camera.CameraRight.x * speed, 0, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        motion = motion + glm::vec3(0, scene.Camera.CameraUp.y * speed, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        motion = motion + glm::vec3(0, -scene.Camera.CameraUp.y * speed, 0);
    }

    if (motion != glm::vec3(0))
    {
        motion = glm::normalize(motion);
        std::cout << "(" << motion.x << ":" << motion.y << ":" << motion.z << ")" << std::endl;
        scene.Camera.Move(motion);
    }
}


ShaderProgram* Eos_Core::CreateShader(const char* vertShaderPath, const char* fragShaderPath)
{
    VertShader vShader(vertShaderPath);
    
    FragShader fShader(fragShaderPath);

    ShaderProgram pShader(&vShader, &fShader);
    shadersList.push_back(pShader);
    return &shadersList.back();
}

