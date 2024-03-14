#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>
#include <vector>
#include <cmath>
#include <map>

const float my_PI = 3.141592653;

void vector_print(std::vector<auto> &vec, bool print_type = false){
	std::cout << "[ ";
	for(auto x : vec){
		std::cout << x;
		if(print_type){std::cout << "(" << typeid(x).name() << ")";}
		std::cout << ", ";
	}
	std::cout << "]\n";
}

template<typename T>
std::vector<T> linspace(T start, T end, int num){
	T step = (end-start)/num;
	std::vector<T> l_space(num);

	for(int i = 0; i < num; i++){
		l_space[i] = start;
		start += step;
	}

	return l_space;
}

template<typename T>
std::vector<T> vector_statistics(std::vector<T> &in_vec){

	std::cout << "Deduced type: " << typeid(T).name() << "\n";

	T max = in_vec[0];
	T min = in_vec[0];
	T sum = 0.0f;

	for(int i = 0; i < in_vec.size(); i++){
		if(in_vec[i] > max){max = in_vec[i];}
		if(in_vec[i] < min){min = in_vec[i];}
		sum += in_vec[i];
	}

	T average = sum / T( in_vec.size() );
	T std_dev = 0.0f;
	T temp = 0.0f;

	for(int i = 0; i < in_vec.size(); i++){
		temp = in_vec[i] - average;
		//std_dev += std::pow(temp, 2);
		std_dev += (temp*temp);
	}

	std_dev = std::sqrt( std_dev / in_vec.size());

	return {sum, average, std_dev, min, max};
}

template<typename T>
T chi_squared(std::vector<T> &observed, std::vector<T> &expected, float err = 1e-12){

	//assert((observed.size() == expected.size()) && "Input vectors are of different size");
	if( !(observed.size() == expected.size()) ){
		std::string size_x = std::to_string(observed.size());
		std::string size_y = std::to_string(expected.size());
		const std::string msg = "Input vectors are of different size: " + size_x + " and " + size_y;
		throw std::length_error(msg);
	}
	
	T chi = 0;
	T temp = 0;
	for (int i = 0; i < observed.size(); i++)
	{	
		if( std::abs(expected[i]) < err ){continue;}
		temp = observed[i] - expected[i];
		chi += (temp * temp / expected[i]);
	}

	return chi;
}

void cast_x(float &x){
	int num = int(x/(2*my_PI));
	if(x > 0){x = (x - 2*num*my_PI);}
	if(x < 0){x = (x + 2*num*my_PI);}
}

float custom_sin(float &x, float err = 1e-6){

	cast_x(x);
	float s = x;
	float n_th_term = x;
	float n = 1;

	while ( std::abs(n_th_term) > err) {
		n_th_term = (-1 * n_th_term * x * x) / ((n+1)*(n+2));
		s += n_th_term;
		n += 2;
	}

	return s;
}

std::vector<float> sin_vect(std::vector<float> &x, float err = 1e-6){
	std::vector<float> y(x.size());
	for (int i = 0; i < x.size(); ++i)
	{
		y[i] = custom_sin(x[i], err);
	}
	
	return y;
}

std::vector<float> cmath_sin_vect(std::vector<float> &x){
	std::vector<float> y(x.size());
	for (int i = 0; i < x.size(); ++i)
	{
		y[i] = std::sin(x[i]);
	}
	
	return y;
}

template <typename T>
std::vector< std::vector<T> > add_matrix(std::vector< std::vector<T> > &a, 
									     std::vector< std::vector<T> > &b){

	int row_a = a.size();
	int col_a = a[0].size();
	int row_b = b.size();
	int col_b = b[0].size();

	if(col_a != col_b || row_a != row_b){
		std::string size_x = std::to_string(col_a) + "x" + std::to_string(row_a);
		std::string size_y = std::to_string(col_b) + "x" + std::to_string(row_b);
		const std::string msg = "Input matrices are of different size: " + size_x + " and " + size_y;
		throw std::length_error(msg);
	}

	std::vector< std::vector<T> > mat(col_a, std::vector<T>(row_a));

	for(int i = 0; i < row_a; i++){
		for (int j = 0; j < col_a; j++){
			mat[i][j] = a[i][j] + b[i][j];
		}
	}

	return mat;
}

void print_map(const std::map<std::string, float>& in_map){
    for (const auto& [key, value] : in_map)
        std::cout << key << " = " << value << "\n";
}

template <typename T>
std::map<std::string, T> vector_statistics_map(std::vector<T> &in_vec){

	std::cout << "Deduced type: " << typeid(T).name() << "\n";

	T max = in_vec[0];
	T min = in_vec[0];
	T sum = 0.0f;

	for(int i = 0; i < in_vec.size(); i++){
		if(in_vec[i] > max){max = in_vec[i];}
		if(in_vec[i] < min){min = in_vec[i];}
		sum += in_vec[i];
	}

	T average = sum / T( in_vec.size() );
	T std_dev = 0.0f;
	T temp = 0.0f;

	for(int i = 0; i < in_vec.size(); i++){
		temp = in_vec[i] - average;
		//std_dev += std::pow(temp, 2);
		std_dev += (temp*temp);
	}

	std_dev = std::sqrt( std_dev / in_vec.size());

	return { {"Sum", sum}, {"Average", average}, {"Standard deviation", std_dev},
			 {"Minimal value", min}, {"Maximal value", max} };
}

void print_separator(const char sep = '='){
	std::cout << '\n';
	std::cout << std::setfill(sep) << std::setw(99) << sep;
	std::cout << std::setfill(' ') << ' ';
	std::cout << '\n';
}

void pretty_print_sine_results(std::vector<float> &x, 
							   std::vector<float> &cus_sin,
							   std::vector<float> &std_sin) {

    std::cout << std::left << std::setw(20) << "| x values:" 
						   << std::setw(20) << "| custom_sin(x):" 
						   << std::setw(20) << "| std::sin(x):" 
						   << std::setw(20) << "| Difference (abs):\n";


	std::cout << std::setfill('_') << std::setw(79) << "_";		
	std::cout << std::setfill(' ') << '\n';		   
    float diff = 0;

    for(int i = 0; i < x.size(); i++){
    	diff = std::abs(cus_sin[i]-std_sin[i]);
	    std::cout << std::left << "| " << std::setw(18) << x[i] 
							   << "| " << std::setw(18) << cus_sin[i] 
							   << "| " << std::setw(18) << std_sin[i]
							   << "| " << std::setw(18) << diff << '\n';
    }

    std::cout << std::endl;
}

void calculate_statistics(){
	std::vector<float> vec = {2.04f, 2.18f, 0.7f, 0.73f, 1.9f, 2.5f, 0.66f, 1.13f, 1.55f, 3.1f};
	//std::vector<float> statistics = vector_statistics(vec);
	auto stat_map = vector_statistics_map(vec);

	std::cout<< "Input vector:\n";
	vector_print(vec);
	// std::cout<< "Statistics: sum, average, std_dev, min, max\n";
	// vector_print(statistics, true);
	print_map(stat_map);
}

void calculate_sine(){
	std::vector<float> x = linspace(-3.14f, 3.14f, 10);
	std::vector<float> y = sin_vect(x);
	std::vector<float> y_math = cmath_sin_vect(x);

	// std::cout<< "Values of x:\n";
	// vector_print(x);
	// std::cout<< "Values of sin(x):\n";
	// vector_print(y);
	// std::cout<< "Values of std::sin(x):\n";
	// vector_print(y_math);
	// std::cout << "Chi squared of sin vs std::sin" << chi_squared(y, y_math) << '\n';

	pretty_print_sine_results(x, y, y_math);
}

void write_matrix_to_str_vec(std::vector<std::vector<float>> &mat_a, std::vector<std::string> &output_print,
							int stride_x, int stride_y, int num_symbols){

	//std::cout << "Stride x: " << stride_x << ", stride y: " << stride_y << '\n';
	for (int i = 0; i < mat_a.size(); i++)
    {	
    	output_print[i + stride_x][stride_y - 1] = '|';
    	output_print[i + stride_x][stride_y + mat_a[0].size()*num_symbols - 1] = '|';
    	for (int j = 0; j < mat_a[0].size(); j++)
	    {
	    	std::string temp = std::to_string(mat_a[i][j]);
	    	int iter = std::min( int(temp.size()), num_symbols) - 1;
	    	for (int k = 0; k < iter; k++)
	    	{
	    		output_print[i + stride_x][j*num_symbols + stride_y + k] = temp[k];
	    	}
	    }
    }
}

void pretty_print_matrix_operation(std::vector<std::vector<float>> &mat_a, 
							       std::vector<std::vector<float>> &mat_b,
							   	   std::vector<std::vector<float>> &mat_c, 
							   	   const char oper = '+', const int num_symbols = 4) {

	int columns_a = mat_a.size();
	int rows_a = mat_a[0].size();

	int columns_b = mat_b.size();
	int rows_b = mat_b[0].size();

	int columns_c = mat_c.size();
	int rows_c = mat_c[0].size();

	int max_row = std::max( std::max(rows_a, rows_b), rows_c) + 2;
	int max_colum = num_symbols * (columns_a + columns_b + columns_c) + 5;

    std::vector< std::string > output_print(max_row, std::string(max_colum, ' ') );

    output_print[0] = std::string(max_colum, '=');
    output_print[max_row - 1] = std::string(max_colum, '=');

    int skip_a = num_symbols * columns_a;
    int skip_b = num_symbols * columns_b;
    int skip_c = num_symbols * columns_c;

    write_matrix_to_str_vec(mat_a, output_print, max_row - rows_a - 1, 1,                   num_symbols);
    write_matrix_to_str_vec(mat_b, output_print, max_row - rows_b - 1, skip_a + 3,          num_symbols);
    write_matrix_to_str_vec(mat_c, output_print, max_row - rows_c - 1, max_colum -  skip_c, num_symbols);

    int mid = max_row / 2;
    output_print[mid][skip_a + 1] = oper;
    output_print[mid][skip_a + skip_b + 3] = '=';

    for(auto &row : output_print){
    	std::cout << row << '\n';
    }
    
}

void calculate_matrix(){
	std::vector<std::vector<float>> matrix_a = { {1, 1, 3},
												 {2, 2, 1},
												 {2, 2, 1}, };

	std::vector<std::vector<float>> matrix_b = { {0, 0, 1},
												 {2, 2, 1},
												 {2, 1, 3} };

	std::vector<std::vector<float>> matrix_c = add_matrix(matrix_a, matrix_b);
	pretty_print_matrix_operation(matrix_a, matrix_b, matrix_c);
}


int main(){

	calculate_statistics();
	print_separator();
	calculate_sine();
	print_separator();
	calculate_matrix();

	return 0;
}