#include <iostream>

void size_of_array(int* arr){
    std::cout << "Rozmiar tablicy (func) " << sizeof(arr)/sizeof(arr[0]) << '\n';
}

// Zapis arr_print(int* arr, int size) jest równoważny, gdyż tablice dekomponują do wskaźników
void arr_print(int arr[], int size){
    std::cout << "[ ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}

int main() {

    //int test_array[5]; //Deklaracja tablicy typu int o rozmiarze 5 (przechowującej 5 elementów)
    //int test_array[5] = {1, 2, 3, 4, 5}; //Deklaracja tablicy typu int o rozmiarze 5 i przypisanie wartości kolejnym elementom
    int test_array[] = {1, 2, 3, 4, 5}; //Przy podaniu wartości elementów, podanie rozmiaru nie jest konieczne

    int arr_size = sizeof(test_array)/sizeof(test_array[0]); //Rozmiar tablicy jest znany, jeśli jesteśmy w tym samym zakresie funkcji
    //Ilośc elementów mozemy określić, dzieląc całkowity rozmiar tablicy przez rozmiar pojedynczego elementu

    std::cout << "Rozmiar tablicy (main) " << arr_size << '\n';
    size_of_array(test_array);

    //Jeśli wykorzystujemy tablice jako argument funkcji, warto podać jej rozmiar jako argument
    arr_print(test_array, 5);

    return 0;
}