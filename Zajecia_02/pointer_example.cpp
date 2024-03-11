#include <iostream>

void function_using_pointers(float* pntr){
	std::cout << "Wartość wskaźnika/adres zmiennej: " << pntr << '\n';
	std::cout << "Wartość zmiennej: " << *pntr << '\n';
}

void function_using_reference(float &ref_val){
	std::cout << "Adres zmiennej: " << &ref_val << '\n';
	std::cout << "Wartość zmiennej: " << ref_val << '\n';
}


void pointer_vs_reference_vs_copy(float* pntr, float &ref_val, float val){

	std::cout << "Wartość wskaźnika/adres zmiennej: " << pntr << '\n';
	std::cout << "Wartość zmiennej: " << *pntr << '\n';

	std::cout << "Adres zmiennej: " << &ref_val << '\n';
	std::cout << "Wartość zmiennej: " << ref_val << '\n';

	std::cout << "Adres kopii: " << &val << '\n';
	std::cout << "Wartość kopii: " << val << '\n';

}


int main(){
	
	float example = 5; //Typowa definicja zmiennej
	float* pointer_to_example = &example;  //Definicja wskaźnika do zmiennej
	//Gdzie float* mówi nam, że to będzie wskanik do zmiennej typu float, &example przypisuje adress zmiennej example

	std::cout << "Wartość zmiennej: " << example  << '\n';
	std::cout << "Adres zmiennej: "   << &example << '\n';
	std::cout << "Wartość wskaźnika: " << pointer_to_example  << '\n';
	std::cout << "Adres wskaźnika: " << &pointer_to_example  << '\n';

	std::cout << "====================\n"; //Very professional separator

	function_using_pointers(&example); //Jeśli funkcja przyjmuje wskaźnik jako argument, należy korzystać z &
	function_using_pointers(pointer_to_example); //Albo z uprzednio zdefiniowanego wskaźnika
	function_using_reference(example); //Funkcje oparte na referencji nie wymagają dodatkwych symboli

	std::cout << "====================\n";
	pointer_vs_reference_vs_copy(&example, example, example);

	return 0;	
}