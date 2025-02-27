#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Data{
    string Name;
    int Age;
};

void insertData(Data *student, Data aptDataArray[]);
void showData(Data aptDataArray[]);
void writeData(ofstream& file, Data aptDataArray[]);
void loadData(ifstream& file);


int main(){

    system("clear");
    Data *aptData = new Data();
    Data *aptDataArray = new Data[5]();

    string fileName = "students.txt";

    if(std::ifstream(fileName)){
        std::cout << "File already exists" << std::endl;
    }

    std::ifstream read; 

    std::ofstream fout(fileName, std::ios::app); 
    if(!fout){
        std::cout << "File could not be created" << std:: endl;
    }

    insertData(aptData, aptDataArray);
    showData(aptDataArray);

    writeData(fout, aptDataArray);
    
    loadData(read);

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

void writeData(ofstream& fout, Data aptDataArray[]){

    for (size_t i = 0; i < 4; i++){
        fout << "Student number " << i << endl;
        fout << "Student's name " << aptDataArray[i].Name << endl;   
        fout << "Student's age " << aptDataArray[i].Age << endl;     
        fout << endl;
    }
    fout.flush();
    fout.close();
}

void loadData(ifstream& read){
    
    read.open("students.txt");

    string content;

    while(getline(read, content)){
        cout << content << endl;
    }

    read.close();
}