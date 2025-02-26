#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



struct Data{
    string Name;
    int Age;
};

void insertData(Data *student, Data aptDataArray[]);
void showData(Data aptDataArray[]);


int main(){

    system("clear");
    Data *aptData = new Data();
    Data *aptDataArray = new Data[5]();

    insertData(aptData, aptDataArray);

    showData(aptDataArray);

    delete aptData;
    delete[] aptDataArray;
    
    return 0;
}

 void insertData(Data *aptData, Data aptDataArray[] ){
   
    if(aptData != NULL){
        aptData -> Name = "Otto";
        aptData -> Age = 20;
        cout << "Student's name " << aptData->Name << endl;
        cout << "Student's age " << aptData->Age << endl;
    }

    if(aptDataArray != NULL){
        aptDataArray[0].Name = aptData->Name;
        aptDataArray[0].Age = aptData->Age;

        for(size_t i = 1; i < 4; i++){
            cout << "New student's name: ";
            cin >> aptDataArray[i].Name;
            cout << "New student's age: ";
            cin >> aptDataArray[i].Age;
            cout << endl;
        }

    }
 };


void showData(Data aptDataArray[]){
    cout << "gathered info" << endl;
    for (size_t i = 0; i < 4; i++)
    {
        cout << "Student number " << i << endl;
        cout << "Student's name " << aptDataArray[i].Name << endl;   
        cout << "Student's age " << aptDataArray[i].Age << endl;     
        cout << endl;
  
    }
}