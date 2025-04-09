#include <iostream>

using namespace std;

float Grades[10];

void requestGrades();
float averageOfGrades(float[]);
int higherThanAverage(float[]);
void showResults(float[]);

int main(){

    requestGrades();

    showResults(Grades);

    return 0;
    
}

void requestGrades(){
    int studentnum = 0;
    for (int i = 1; i <= 10; i++){
        studentnum ++;
        cout << "Insert grade for student " << studentnum << ": " << endl;
        cin >> Grades[i];
        cin.clear();
    }
    
}

float averageOfGrades(float Grades[]){

    float sumGrades = 0;
    for (int i = 1; i <= 10; i++){
        sumGrades += Grades[i];
    }

    return sumGrades /10;
}

int higherThanAverage(float Grades[]){
    int higherThan = 0;
    for (int i = 1; i <= 10; i++){
        if(Grades[i] > averageOfGrades(Grades)){
            higherThan++;
        }
    }
    return higherThan;
}

void showResults(float Grades[]){
    cout << "--------------------------------------------------------" << endl;
    cout << "Grades from the students in Data Structure class" << endl;
    cout << "--------------------------------------------------------" << endl;

    int numStudent = 0;
    for (int i = 1; i <= 10; i++){
        numStudent++;
        cout << "Grade of student " << numStudent << ": " << Grades[i] << endl;
    }

    cout << "Average grade in class: " << averageOfGrades(Grades) << endl;

    cout << "Grades higher than the average: " << higherThanAverage(Grades) << endl;

}
