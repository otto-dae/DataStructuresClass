#include <iostream>

using namespace std; //I hate using this

int functionVal(int a, int b);
int functionRef(int& a, int& b);

int main(){

    system("clear");

    int a = 10;
    int b = 20;

    cout << "Value itself" << endl;
    cout << "The values of A and B are respectively: " << a << " and " << b << endl;

    cout << "functionVal(a,b) ->" << functionVal(a,b) << endl;

    cout << "The new values of A and B now are: " << a << " and " << b << "\n"<< endl; 

    cout << "Reference" << endl;
    cout << "The values of A and B are respectively: " << a << " and " << b << endl;

    cout << "functionRef(a,b) ->" << functionRef(a,b) << endl;

    cout << "The new values of A and B now are: " << a << " and " << b << endl; 




    return 0;
}

int functionRef(int& a, int& b){
    a+=2;
    b-=5;

    return (a+b);
}

int functionVal(int a, int b){
    a+=2;
    b-=5;

    return (a+b);
}


