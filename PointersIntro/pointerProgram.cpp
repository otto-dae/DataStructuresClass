#include <iostream>
#include <cstdlib>

int main(){
    int num1 = 10;
    int x;

    int *ptrNum1;
    int *ptrNum2;
    float *ptrNum3;
    
    ptrNum1 = &num1;

    std::cout << "First program with pointers" << std::endl;
    std::cout << "The memory address of num1 is: " << &num1 << std::endl;
    std::cout << "The memory address of num1 through de pointer is: " << ptrNum1 << std::endl;
    std::cout << "The value of num1 is: " << *ptrNum1 << std::endl;

    ptrNum2 = ptrNum1;

    return 0;
}