#include <iostream>
#include <fstream>


using namespace std;

int main(){
    
    string fileName = "Nombres.txt";
    
    
    if(ifstream(fileName)){
        cout << "File already exists" << endl;
    }
    ofstream WriteFile(fileName); 
    if(!WriteFile){
        cout << "File could not be created" << endl;
    }

    WriteFile << "Students in Data Structure Class: " << endl;        
    WriteFile << "          - Juan Garcia" << endl;        
    WriteFile << "          - Maria Trejo" << endl;        
    WriteFile << "          - Pedro Lopez" << endl;        
    WriteFile << "          - Luiz Diaz" << endl;        

    WriteFile.close();
    
    ifstream Readfile("Nombres.txt");
    string line;
    while (getline(Readfile, line)) {
        cout << line << endl;
    }
    
    Readfile.close();


    return 0;
}