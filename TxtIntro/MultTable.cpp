#include <iostream>
#include <fstream>

int main(){

    int value1, result;
    std:: string fileName = "MultTable.txt";
    
    if(std::ifstream(fileName)){
        std::cout << "File already exists" << std::endl;
    }
    std::ofstream fout(fileName, std::ios::app); 
    if(!fout){
        std::cout << "File could not be created" << std:: endl;
    }

    std::cout << "Insert a number to calculate its multiplacation table from 1-10: " << std::endl;
    std::cin >> value1;
    fout << std::endl;
    fout << "Multiplication table of: " << value1 << std::endl;
    for(int i = 1; i <= 10; i++){
        fout << value1 << " * " << i << " = " << value1*i << std::endl;
    } 
    
    fout.close();
}