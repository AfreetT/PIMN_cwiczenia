#include <iostream>
#include <string>

void print_triangle(int h){
	int n = 2*h - 1;	//Długość podstawy piramidy wylicozna na podstawie jej wysokości h

	for (int i = 0; i < h - 1; i++)
	{
		std::string str = std::string(n ,' '); //Utwórz string długości n wypełniony spacjami
		str[h - 1 + i] = '*'; //Przypisz w miejscach względem środka '*' zamiast spacji
		str[h - 1 - i] = '*';
		std::cout << str << '\n';  //Wypisz string i przejdź do nowej linii
	}

	std::cout << std::string(n, '*') << std::endl; //Na sam koniec wypisz podstawę piramidy
}

int main(){

	int n;
	std::cout << "Give pyramid height" << '\n';
	std::cin >> n;
	print_triangle(n);

	return 0;
}