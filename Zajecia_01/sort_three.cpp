#include <iostream>

void sort_three(float a, float b, float c){

	float temp;

	if(a <= b){
		temp = a;
		a = b;
		b = temp;
	}

	if(b <= c){
		temp = b;
		b = c;
		c = temp;
	}

	if(a <= b){
		temp = a;
		a = b;
		b = temp;
	}

	std::cout<< a <<" " << b <<" "<< c <<'\n';

}

int main(int argc, char* argv[]){
	
	//Testy czy mamy odpowiednią liczbę argumentów wejścia
	if(argc < 4){
		std::cout<<"Not enough arguments were provided\n";
		return 0;
	}

	if(argc > 4){
		std::cout<<"Too many arguments, only first three will be used\n";
	}

	float a, b, c;
	//Wartości w argv są typu char*, trzeba je zamienić na wartości liczbowe, tutaj na float
	a = std::stof(argv[1]);
	b = std::stof(argv[2]);
	c = std::stof(argv[3]);
	
	sort_three(a, b, c);

	return 0;
}

