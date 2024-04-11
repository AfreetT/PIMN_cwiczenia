#include "examples.h"
#include "imgui.h"
#include "implot.h"

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
    static float frequency = 0;
    static float phase = 0;
    static float y0 = 0;

    ImGui::SliderFloat("Amplitude", &amplitude, -1.0f, 1.0f);
    ImGui::SliderFloat("Frequency", &frequency, 0.0f, 10.0f);
    ImGui::SliderFloat("Phase", &phase, -1.57f, 1.57f);
    ImGui::SliderFloat("Intercept", &y0, -1.0f, 1.0f);
    
    calc_sin(x, y, amplitude, frequency, phase, y0);

    // Zamknięcie BeginPlot w bloku 'if' daje nam margines bezpieczeństwa gdyby coś było nie tak z rysowaniem okna

    if(ImPlot::BeginPlot("Static plot", ImVec2(0.9f*width, 0.9f*height))){
    ImPlot::SetNextLineStyle(ImVec4( 66.0f / 255.0f, 135.0f / 255.0f, 245.0f/ 255.0f, 1.0f), 4);
    ImPlot::PlotLine("Static sine", &(x[0]), &(y[0]), x.size() );
    ImPlot::EndPlot();
    }
}

SineClass::SineClass(){
	amplitude = 1.0f;
	frequency = 1.0f;
	phase = 0.0f;
	intercept = 0.0f;

	size = 1024;

	x = linspace(0.0f, 1.0f, size);
	y = std::vector<float>(size);

}

void SineClass::Recalculate(){
	for (int i = 0; i < size; ++i)
    {
        y[i] = amplitude * std::sin( frequency * x[i] - phase ) + intercept;
    }
}

void SineClass::Plot(){
	float width = ImGui::GetWindowWidth();
    float height = ImGui::GetWindowHeight();

    ImGui::PushItemWidth(width * 0.25f); //Determinuje szerokość następngo widgetu
    ImGui::SliderFloat("##amp", &amplitude, -1.0f, 1.0f, "Amplitude: %.2f");
    // Nadanie nazwy zaczynając od ## zapobeignie jej wyświetalniu na ekranie, ale dalej będzie rozpoznawalna dla ImGui
    // Dodanie "Amplitude: %.2f" jako kolejnego argumentu prowadzi do wyświetlenia się tytułu oraz wartości slidera
    // na środku slidera. %.2f determinuje, w którym miejscu tekstu ma się pojawić wartość, 
    // f dotyczy typu float, .2 powoduje wyświetlenie tylko wdóch miejsc po przecinku

    ImGui::PushItemWidth(width * 0.25f);
    ImGui::SameLine(); //Kolejny slider w tej samej linii
    ImGui::SliderFloat("##freq", &frequency, 0.0f, 10.0f, "Frequency: %.2f");

    ImGui::PushItemWidth(width * 0.25f); ImGui::SameLine();
    ImGui::SliderFloat("##phase", &phase, -3.14f, 3.14f, "Phase: %.2f");

    ImGui::PushItemWidth(width * 0.25f); ImGui::SameLine();
    ImGui::SliderFloat("##inter", &intercept, 0.0f, 1.0f, "Intercept: %.2f");

    if (ImPlot::BeginPlot("Class sine", ImVec2(0.9f*width, 0.9f*height)) ) {
        ImPlot::SetupAxes("X axis title", "Y axis title"); //Możemy tutułować nasze osie
        ImPlot::SetNextLineStyle(ImVec4(0.0f, 102.0f / 255.0f, 1.0f, 1.0f), 4);
        ImPlot::PlotLine("Sine plot", &(x[0]), &(y[0]), size );
        ImPlot::EndPlot();
    }

    Recalculate();

}