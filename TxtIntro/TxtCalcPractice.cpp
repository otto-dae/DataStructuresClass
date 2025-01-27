#include <iostream>
#include <fstream>

int main(){

    int value1, value2, operation, result;
    std:: string fileName = "Calculator.txt";
    
    
    if(std::ifstream(fileName)){
        std::cout << "File already exists" << std::endl;
    }
    std::ofstream WriteFile(fileName); 
    if(!WriteFile){
        std::cout << "File could not be created" << std:: endl;
    }

    do{

        std::cout << "Insert the first number: " << std::endl;
        std:: cin >> value1;
        std::cout << "Insert the second number: " << std::endl;
        std:: cin >> value2;

        WriteFile << "Your numbers are: " << value1 << " and " << value2 << std::endl;
 
        std::cout << "Please choose an operation \n 1.- '+' \n 2.- '-' \n 3.- '*' \n 4.- '/' \n 5.- Exit \n" << std::endl;
        std::cin >> operation;    

        switch (operation){
    case 1:
            result = value1 + value2;
            WriteFile << "Your sum of " << value1 << " + " << value2 << " = " << result << "\n";
            std::cout << "Your sum of " << value1 << " + " << value2 << " = " << result << std::endl;

        break;
    case 2:
            result = value1 - value2;
            WriteFile << "Your sum of " << value1 << " - " << value2 << " = " << result << "\n";
            std::cout << "Your sum of " << value1 << " - " << value2 << " = " << result << std::endl;
        break;
    case 3:
            result = value1 * value2;
            WriteFile << "Your sum of " << value1 << " * " << value2 << " = " << result << "\n";
            std::cout << "Your sum of " << value1 << " * " << value2 << " = " << result << std::endl;
        break;
    case 4:
            result = value1 / value2;
            WriteFile << "Your sum of " << value1 << " / " << value2 << " = " << result << "\n";
            std::cout << "Your sum of " << value1 << " / " << value2 << " = " << result << std::endl;
        break;
    case 5: 
            std::cout << "Closing . . . " << std::endl;
            WriteFile.close();
        break;
    default:
            std::cout << "Please choose a correct operation" <<std::endl;
        break;
    }
    } while (operation != 5);
    



    
    std::ifstream ReadFile(fileName);
    if(ReadFile.fail()){
        std::cout << "File not found";
        ReadFile.close();
    }

    return 0;
}