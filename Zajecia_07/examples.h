#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>

std::vector<float> linspace(float start, float end, int num );
void calc_sin(std::vector<float> &x, std::vector<float> &y,
             float ampl, float freq, float phase, float y0);

void plot_line(std::vector<float> &x, std::vector<float> &y);


class SineClass{
	float amplitude, frequency, phase, intercept;
	std::vector<float> x;
	std::vector<float> y;
	size_t size;
	
public:
	SineClass();
	void Recalculate();
	void Plot();
};
