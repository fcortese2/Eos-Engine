#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_glfw.h"
#include "IMGUI/imgui_impl_opengl3.h"

#include "Eos_editor.h"
#include "../Eos_core.h"
#include "../IO/texture_loader.h"

void Eos_Editor::Render(Eos_Core* core, GLFWwindow* window)
{
    ImGui::Begin("Test Window");
    if (ImGui::Button("Spawn Sprite"))
    {
        ShaderProgram* sP = core->CreateShader("BaseShader", "BaseShader");

        SpriteRenderer r = core->AssetManager.LoadSpriteAsset(R"(\ImageData\Test.png)", sP);

        core->CurrentScene()->AddAssetToSceneAssets(r);
    }
    ImGui::End();
}
