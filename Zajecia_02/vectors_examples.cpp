#include <iostream>
#include <vector> //Biblioteka zawierająca implementację std::vector

//auto pozwala na automatyczne wybranie typu zmiennej, więcej o tym później
void print_vector(std::vector<auto>& vec){
	//Metoda .size() pozwala na poznanie rozmiaru wektora w każdym miejscu w kodzie
	std::cout << "[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";
}

//Prosta funkcja podnosząca wartość każdego elementu w wektorze typu int o 1
void incriment_vector(std::vector<int>& vec){
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] += 1;
    }
}

//Funkcja zwracająca wektor typu float
std::vector<float> linspace(float start, float end, int num){
	float step = (end-start)/num;
	std::vector<float> l_space(num);

	for(int i = 0; i < num; i++){
		l_space[i] = start;
		start += step;
	}

	return l_space;
}


int main(){

	std::vector<float> a {0, 1}; //Konstrukcja wektora zawierającego dwa elementy, 0 i 1, typu float
	std::vector<int> b(20); //Konstrukcja wektora typu int o długości 20, domyślnie wypełniony 0
	std::vector<float> c;  //Deklaracja wektora typu float, długości 0


	//Można dodać element do końca wektora korzystając z metody push_back
	for (int i = 0; i < 10; i++)
	{
		c.push_back(i);
	}

	std::cout << "Wektor a:\n";
	print_vector(a);
	std::cout << "Wektor b:\n";
	print_vector(b);
	std::cout << "Wektor c:\n";
	print_vector(c);

	//Można tworzyć wektory dowolnych elementów, w szczególności innych wektorów, co daje nam tablicę 2D
	std::vector< std::vector<float> > vect_2D {{0, 1, 3},
						 			           {3, 4, 4}};

	//Pierwszym elementem jest wektor [0, 1, 3], a drugim wektor [3, 4, 4]
	//Elementy można pozyskać korzystając z podwójnego indeksu, vect_2D[0][0] zwróci 0

	std::cout << "Wektor wektorów:\n";			 			           
	for (int i = 0; i < vect_2D.size(); i++){
		std::cout << "[ ";
	 	for (int j = 0; j < vect_2D[i].size(); j++){
	 		std::cout << vect_2D[i][j] << " ";
	 	}
	 	std::cout << "]\n";
	}					 			 


	std::vector<int> dynamic_vec;
	//Wektor jest tak naprawdę wskaźnikiem do tablicy z dodatkowymi ułatwieniami
	//Podobnie jak tablica, wektor jest niezmienny i dodanie elementów wymusza wykonanie kopii tablicy
	//Widać to śledząc pozycję pierwszego elementu w pamięci
	for (int i = 0; i < 32; i++)
	{	
		dynamic_vec.push_back(i);
		std::cout << "Iteration number: " << i << '\t';
		std::cout << "Adress of dynamic_vec: " << &dynamic_vec << '\t';
		std::cout << "Adress of first element: " << &(dynamic_vec[0]) << '\n';
		
	}

	std::cout << "Wynik funckji:\n";	
	std::vector<float> l_vec = linspace(0.0f, 10.0f, 100);
	print_vector(l_vec);
	
}