#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <vector>

void PrintVect(std::vector<auto> &Vect){
	std::cout << "[ ";
	for(auto &x : Vect){
		std::cout << x << ", ";
	}
	std::cout << "]";
}

void PrintMat(std::vector<std::vector<auto>> &Mat){
	for(auto &Row : Mat){
		PrintVect(Row);
		std::cout << '\n';
	}
}

std::vector<std::vector<int>> DataFromFile(std::string FileName){

	std::ifstream FileStream(FileName);                        // #include <fstream>
	if (!FileStream) {
		std::cerr << "File not found\n";                       // #include <iostream>
		return {};
	}
	std::vector<std::vector<int>> Output;                      // #include <vector>
	std::string SingleLine; 								   // #include <string>
	int Temp;
	while(std::getline(FileStream, SingleLine)){
		std::stringstream SStream(SingleLine);                  // #include <sstream>
		std::vector<int> Row;
		while(SStream >> Temp){Row.push_back(Temp);}
		Output.push_back(Row);
	}
	FileStream.close();
	return Output;
}

void SaveFile(std::string FileName){
	std::ofstream FileStream(FileName);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 2; ++j){
			FileStream << i << ' ' << j <<'\n';
		}
	}
	

	FileStream.close();
}

int main(){
	
	std::string FileName = "./TestFile.dat";
	SaveFile(FileName);
	std::vector<std::vector<int>> Output = DataFromFile(FileName);
	PrintMat(Output);

	return 0;
}