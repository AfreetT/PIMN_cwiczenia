#include "context_setup.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>

std::vector<float> linspace(float start, float end, int num ){
    std::vector <float> x(num);
    float step = (end - start) / (num - 1);
    x[0] = start;
    for (int i = 1; i < num; i++){
        x[i] = x[i - 1] + step;
    }
    return x;
}

void calc_sin(std::vector<float> &x, std::vector<float> &y,
             float ampl, float freq, float phase, float y0){

    for (int i = 0; i < x.size(); ++i)
    {
        y[i] = ampl * std::sin( freq * x[i] - phase ) + y0;
    }

}

void plot_line(std::vector<float> &x, std::vector<float> &y){
    float width = ImGui::GetWindowWidth();
    float height = ImGui::GetWindowHeight();

    static float amplitude = 0;
    ImGui::SliderFloat("Amplitude", &amplitude, -1.0f, 1.0f);
    calc_sin(x, y, amplitude, 2.0, 0, 0);

    ImPlot::BeginPlot("First plot", ImVec2(0.9f*width, 0.9f*height));
    ImPlot::SetNextLineStyle(ImVec4( 66.0f / 255.0f, 135.0f / 255.0f, 245.0f/ 255.0f, 1.0f), 4);
    ImPlot::PlotLine("Parabl", &(x[0]), &(y[0]), x.size() );
    ImPlot::EndPlot();
}

int main()
{

    std::vector<float> x = linspace(-1.52, 1.52, 512);
    std::vector<float> y(512);
    calc_sin(x, y, 1.0, 2.0, 0, 0);


    ImGuiContext_OGL context;
    context.setup_and_show();

    while (!glfwWindowShouldClose(context.window))
    {
        context.new_frame();

        ImGui::Begin("First window");
        plot_line(x, y);
        ImGui::End();

        context.render_frame();
    }

    return 0;
}