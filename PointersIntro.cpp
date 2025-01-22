#include <iostream>

int main(){

    int val = 20;

    int* pointer;

    pointer = &val;

    std::cout << "Value at val: " << val << std::endl;
    std::cout << "Value at pointer: " << pointer << std::endl;
    std::cout << "Value at *pointer: " << *pointer << std::endl;


    return 0;
}