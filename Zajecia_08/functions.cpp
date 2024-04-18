#include <iostream>
#include <vector>
#include <functional>

float two_args(float a, float b){
   return a + b;
}

float three_args(float a, float b, float c){
   return a + b - c;
}

float wrapped_two_args(float x, std::vector<float> params){
   return x * two_args(params[0], params[1]);
}

float wrapped_three_args(float x, std::vector<float> params){
   return x * three_args(params[0], params[1], params[2]);
}

void func_arg( float(*func_as_arg)(float, std::vector<float>),
                   float a, std::vector<float> params, float h = 0.0001){

    float c = func_as_arg(a, params) - func_as_arg(a + h, params);
    std::cout << "                   " << c << '\n';
}

void func_arg_functional( std::function<float(float, std::vector<float>)> func_as_arg,
                   float a, std::vector<float> params, float h = 0.0001){

    float c = func_as_arg(a, params) - func_as_arg(a + h, params);
    std::cout << "                   " << c << '\n';
}

int main(){

   func_arg_functional( wrapped_two_args, 1.0, {0, 1});
   func_arg_functional( wrapped_three_args, 2.0, {1, 0, 2});

}