#include <iostream>
#include <fstream>

int main(){

    int outVal = 20;
    int inval;
    std::string nameFile, text;

    std::cout << "Write a name for your file: ";
    getline(std::cin, nameFile);
    std::ofstream WriteFile(nameFile+".txt"); //("MyText.txt");

    std::cout << "Write text for your file: ";
    getline(std::cin, text);
    WriteFile << outVal << "\n";
    WriteFile << text << "\n";

    WriteFile.close();

    
    std::ifstream ReadFile(nameFile+".txt");
    if(ReadFile.fail()){
        std::cout << "File not found";
        ReadFile.close();
    }
    else{
        ReadFile >> inval;
        ReadFile.close();
        std::cout << "The value inside of the txt is: " << inval << std::endl;
        std::cout << "The text in the file is " << text << std::endl ;
    }
    return 0;
}