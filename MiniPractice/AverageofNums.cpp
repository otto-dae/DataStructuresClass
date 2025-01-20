#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int SumNumbers(int x, int y, int z){
    return x + y + z;
}

double AverageNumbers(int total){
    return (double)total / 3;
}

int main(){

    system("clear");

    int x,y,z;

    cout << "Insert the first value: " << endl;
    cin >> x;

    cout << "Insert the second value: " << endl;
    cin >> y;
    
    cout << "Insert the third value: " << endl;
    cin >> z;

    cout << "The average of your numbers is: " << AverageNumbers(SumNumbers(x,y,z)) << endl;

    return 0; 
}

