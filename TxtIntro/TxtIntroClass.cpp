#include <iostream>
#include <fstream>

int main(){
    int outVal = 20;

    std::ofstream WriteFile("MyText.txt");

    WriteFile << outVal << "\n";

    WriteFile.close();

    int inval;
    std::ifstream ReadFile ("MyText.txt");

    ReadFile >> inval;

    ReadFile.close();

    std::cout << "The value inside of the txt is: " << inval << std::endl;

    return 0;
}