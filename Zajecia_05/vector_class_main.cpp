#include "vector_class.h"
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cmath>

int main(){

	ND_Vector<float> custom_X(20);
	ND_Vector<float> custom_Y(20);
	ND_Vector<float> custom_Z{0, 1, 2, 3, 4, 5};

	std::iota(custom_X.begin(), custom_X.end(), -4);

	std::transform(custom_X.begin(), custom_X.end(), custom_Y.begin(),
				  [](float x){ return std::sinh(x);}); 


	float sum = std::accumulate(custom_X.begin(), custom_X.end(), 0);
    float product = std::accumulate(custom_X.begin(), custom_X.end(), 1, std::multiplies<float>());

	std::cout << "Wektor X: " << custom_X;
	std::cout << std::setprecision(4) << "Wektor Y: " << custom_Y;
	std::cout << "Suma: " << sum << '\n';
	std::cout << "Iloczyn: " << product << '\n';
	std::cout << "Wektor Z: " << custom_Z;
	
	return 0;
}