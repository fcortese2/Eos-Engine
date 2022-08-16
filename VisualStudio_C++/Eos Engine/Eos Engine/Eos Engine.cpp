#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include "Core/Shaders/rendering_lowlevel.h"
#include "Core/Objects/Texture2D/texture_2D.h"
#include "Core/IO/texture_loader.h"
#include "Core/Objects/SpriteRenderer/sprite_renderer.h"

int main(void)
{
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR::GLEW::INIT::FAILED_TO_INITIALIZE_GLEW" << std::endl;
        return -1;
    }

    VertShader vShader(std::string("BaseShader"));
    FragShader fShader(std::string("BaseShader"));
    ShaderProgram pShader(&vShader, &fShader);

    glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);

    pShader.SetMatrix4("projection", projection);

    Texture2D tex(TextureLoader::LoadTexture(R"(\ImageData\Test.png)"));

    SpriteRenderer renderer(&pShader);


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        renderer.DrawSprite(tex,
            glm::vec2(10, 10));


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}