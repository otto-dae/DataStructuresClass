#include <iostream>
#include <string>

int main(){

    system("clear");

    int num1, num2, num3;

    int *pointerNum1;
    int *pointerNum2;
    int *pointerNum3;


    std::cout << "Insert number 1: ";
    std::cin >> num1;
    pointerNum1 = &num1;


    std::cout << "Insert number 2: ";
    std::cin >> num2;
    pointerNum2 = &num2;

    std::cout << "Insert number 3: ";
    std::cin >> num3;
    pointerNum3 = &num3;

    if(*pointerNum1 > *pointerNum2 && *pointerNum1 > *pointerNum3){
        std::cout << *pointerNum1 << " is the biggest" << std::endl;
    }
    if(*pointerNum2 > *pointerNum1 && *pointerNum2 > *pointerNum3){
        std::cout << *pointerNum2 << " is the biggest" << std::endl;
    }    
    if(*pointerNum3 > *pointerNum1 && *pointerNum3 > *pointerNum2){
        std::cout << *pointerNum3 << " is the biggest" << std::endl;
    }

    int flagNum1 = 0;
    for (int i = 1; i <= *pointerNum1; i++ ){
        if(*pointerNum1 % i == 0){
            flagNum1++;
        }
    }
    if(flagNum1 > 2){
        std::cout << *pointerNum1 << " is not a prime"<< std::endl;
    }    
    else{
        std::cout << *pointerNum1 << " is a prime"<< std::endl;
    }

    int flagNum2 = 0;
    for (int i = 1; i <= *pointerNum2; i++ ){
        if(*pointerNum2 % i == 0){
            flagNum2++;
        }
    }
    if(flagNum2 > 2){
        std::cout << *pointerNum2 << " is not a prime"<< std::endl;
    }    
    else{
        std::cout << *pointerNum2 << " is a prime"<< std::endl;
    }



    int flagNum3 = 0;
    for (int i = 1; i <= *pointerNum3; i++ ){
        if(*pointerNum3 % i == 0){
            flagNum3++;
        }
    }
    if(flagNum3 > 2){
        std::cout << *pointerNum3 << " is not a prime"<< std::endl;
    }    
    else{
        std::cout << *pointerNum3 << " is a prime"<< std::endl;
    }

    return 0;
}