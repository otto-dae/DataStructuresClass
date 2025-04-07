#include <iostream>

using namespace std;

int selfSum(int, int);
int interchange();

int main(){

    bool flag = true;
    int a,b;

    do{
        cout << "Insert full number a: " << endl;
        cin >> a;
        cout << "Insert full number b: " << endl;
        cin >> b;

        cout << &a;
        cout << "The sum of a + b = " << selfSum(a,b) <<endl;
    } while (flag == true);
    
}

int selfSum(int a, int b){
    return a + b;
}