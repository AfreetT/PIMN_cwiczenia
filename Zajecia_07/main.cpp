#include "context_setup.h"
#include "examples.h"

int main()
{

    std::vector<float> static_x = linspace(-1.52, 1.52, 512);
    std::vector<float> static_y(512);
    SineClass SinePlot;

    ImGuiContext_OGL context;
    context.setup_and_show();

    while (!glfwWindowShouldClose(context.window))
    {
        context.new_frame();

        ImGui::Begin("Static example");
        plot_line(static_x, static_y);
        ImGui::End();

        ImGui::Begin("Class example");
        SinePlot.Plot();
        ImGui::End();

        context.render_frame();
    }

    return 0;
}