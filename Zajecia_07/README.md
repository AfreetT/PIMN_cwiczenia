Przykład wykorzystania ImGui oraz ImPlot do stworzenia interaktywnego wykresu funkcji sinus.
Funkcja 'plot_line' opiera się na zastosowaniu zmiennych statycznych, z kolei SineClass osiąga ten sam rezultat
opierając się na metodach i członkach klasy.

Funkcja 'main' zawiera przykład wykorzytania tych dwóch metod. Implementacje są zawarte w pliku źródłowym.
Plik źródłówy 'example.cpp' powinien być dodany do CMakeLists pod 'OTHER_SOURCES', np:

set(OTHER_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/examples.cpp
)
