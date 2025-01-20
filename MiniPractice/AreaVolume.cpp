#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){

    system("clear");

    const float PI = 3.14159;
    float radio, area, volume;

    cout << "Area and volume of a sphere in cms" << endl;
    cout << "What is the radius?" << endl;
    cin >> radio;

    area = PI * pow(radio, 2);
    cout << "The area of the circle is " << area << endl;

    volume  = ((float)4 / (float)3) * PI * pow(radio,3);
    cout << "The volume of the sphere is: " << volume << endl;

    return 0;
}