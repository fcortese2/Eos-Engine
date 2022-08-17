#include <future>

#include "Core/Eos_core.h"


int main(void)
{
    Eos_Core engine(1000, 700);
    
    engine.Renderer_Init();

    /*VertShader vShader(std::string("BaseShader"));
    FragShader fShader(std::string("BaseShader"));
    ShaderProgram pShader(&vShader, &fShader);

    Texture2D texture(TextureLoader::LoadTexture(R"(\ImageData\Test.png)"));
    engine.CurrentScene()->AddSprite(&pShader, &texture);*/

    //GLFWwindow* window;
  
    //if (!glfwInit())
    //    return -1;
    //
    //window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    //if (!window)
    //{
    //    glfwTerminate();
    //    return -1;
    //}
    //glfwMakeContextCurrent(window);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSetKeyCallback(window, key_callback);

    //glewExperimental = true;
    //if (glewInit() != GLEW_OK)
    //{
    //    std::cout << "ERROR::GLEW::INIT::FAILED_TO_INITIALIZE_GLEW" << std::endl;
    //    return -1;
    //}

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //VertShader vShader(std::string("BaseShader"));
    //FragShader fShader(std::string("BaseShader"));
    //ShaderProgram pShader(&vShader, &fShader);

    //Texture2D tex(TextureLoader::LoadTexture(R"(\ImageData\Test.png)"));
    //std::cout << tex.Width << "x" << tex.Height << std::endl;

    //scene.AddSprite(&pShader, &tex);
    //
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    //IMGUI_CHECKVERSION();
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO(); (void)io;
    //ImGui::StyleColorsDark();
    //ImGui_ImplGlfw_InitForOpenGL(window, true);
    //ImGui_ImplOpenGL3_Init("#version 330");

    ///* Loop until the user closes the window */
    //while (!glfwWindowShouldClose(window))
    //{
    //    float currentFrame = static_cast<float>(glfwGetTime());
    //    deltaTime = currentFrame - lastFrame;
    //    lastFrame = currentFrame;

    //    processInput(window);

    //    /* Render here */
    //    glClear(GL_COLOR_BUFFER_BIT);

    //    ImGui_ImplOpenGL3_NewFrame();
    //    ImGui_ImplGlfw_NewFrame();
    //    ImGui::NewFrame();

    //    //renderer.Scale = glm::vec2(300, 300);
    //    scene.RenderScene();

    //    ImGui::Begin("Test Window");
    //    ImGui::Text("Example text");
    //    ImGui::End();

    //    ImGui::Render();
    //    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    //    /* Swap front and back buffers */
    //    glfwSwapBuffers(window);

    //    /* Poll for and process events */
    //    glfwPollEvents();
    //}

    //ImGui_ImplOpenGL3_Shutdown();
    //ImGui_ImplGlfw_Shutdown();
    //ImGui::DestroyContext();

    //glfwTerminate();
    //return 0;
}

//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//    glm::vec3 motion = glm::vec3(0);
//
//    float speed = static_cast<float>(2.5 * deltaTime);
//
//    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//    {
//        motion = motion + glm::vec3(-scene.Camera.CameraRight.x * speed, 0, 0);
//    }
//    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//    {
//        motion = motion + glm::vec3(scene.Camera.CameraRight.x * speed, 0, 0);
//    }
//    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//    {
//        motion = motion + glm::vec3(0, scene.Camera.CameraUp.y * speed, 0);
//    }
//    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//    {
//        motion = motion + glm::vec3(0, -scene.Camera.CameraUp.y * speed, 0);
//    }
//
//    if (motion != glm::vec3(0))
//    {
//        motion = glm::normalize(motion);
//        std::cout << "(" << motion.x << ":" << motion.y << ":" << motion.z << ")" << std::endl;
//        scene.Camera.Move(motion);
//    }
//}
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    
//    
//
//
//
//}