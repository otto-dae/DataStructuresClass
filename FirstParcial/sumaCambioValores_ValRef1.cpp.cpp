#include <iostream>

using namespace std;

int selfSum(int, int);
void interchange(int &, int &);

int main(){

    bool flag = true;
    int a,b;

    do{
        cout << "Insert full number a: " << endl;
        cin >> a;
        cout << "Insert full number b: " << endl;
        cin >> b;

        cout << "The sum of a + b = " << selfSum(a,b) <<endl;


        cout << "a: " << a << endl;
        cout << "b: " << b << endl;

        cout << "Changing . . . " << endl;
        interchange(a, b);

        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    } while (flag == true);
    
    return 0;
}

int selfSum(int a, int b){
    return a + b;
}

void interchange(int& a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;

}