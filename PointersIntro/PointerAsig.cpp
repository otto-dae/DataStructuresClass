#include <iostream>

int main(){
    
    int i = 5;
    int *p, *q;
    p = &i; // Se le asigna a ’p’ la direccion de ’i’
    q = p; // Se le asigna a ’q’ la direccion almacenada en ’p’ (la misma de ’i’)

    std::cout << "int i = " << i << std::endl;
    std::cout << "int *p = " << p << std::endl;
    std::cout << "int *q = " << q << std::endl;

    return 0;

}