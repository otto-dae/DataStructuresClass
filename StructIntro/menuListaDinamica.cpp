#include <cstdlib>
#include <iostream>
#include "colors.h"

using namespace std;

struct Node{
    int data;
    Node *next;
};

void insertList(Node *&, int);
void showList();
bool searchList(Node *, int);
int addListValues();
double averageListValues(int);

Node *head=NULL;

int main(){

    system("clear");

    int option, n;
    bool loop = true;

    do
    {
        cout << "\t DYNAMIC SYMPLE LINKED LIST MENU" << endl;
        cout << "\n 1.- Insert list" << endl;
        cout << "\n 2.- Show list" << endl;
        cout << "\n 3.- Search in list" << endl;
        cout << "\n 4.- Add all values in list" << endl;
        cout << "\n 5.- Average all values in list" << endl;



        cout << "Select an option " <<endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Insert an full number " << endl;
            cin >> n;

            insertList(head, n);
            break;

        case 2:
            
            showList();
            break;

        case 3:
            
            cout << "Insert element to search";
            cin >> n;

            if(searchList(head, n) == true){
                cout << "Element is in the list" <<endl;
            }
            else{
                cout << "Element is not in the list" <<endl;

            }
            break;
            
        case 4:
            
            cout << "All the values added is: " << addListValues() << endl;
            break;

        case 5:

            
            cout << "All the values averaged is: " << averageListValues(addListValues()) << endl;
            break;
           
        default:
        loop = false;
            break;
        }

    } while (loop);

}

void insertList (Node *&head, int n){
    Node * new_node = new Node();
    new_node -> data = n;
    Node *actual=head;
    Node *aux;

    if(searchList(head, n) == true){
        cout << "unable to insert value";
        return;
    };


    while ((actual!=NULL) && (actual->data<n)){
        aux = actual;
        actual = actual -> next;
    }
    if(head==actual){
        head=new_node;
    }else{
        aux->next = new_node;
    }
    new_node -> next = actual;
    cout << "Element added to list" << endl;
}

void showList(){

    Node *actual=head;
    int element = 0;
    while (actual != NULL)
    {
        cout << element++ << ": "<< actual -> data << endl;
        actual = actual -> next;
    }
    
}

bool searchList(Node * head, int n){

    bool flag = false;
    Node *actual = head;
    Node *address = nullptr;

    while ((actual != nullptr) && (actual-> data <= n)){

        if(actual -> data == n){
            flag = true;
            address = actual;
        }

        actual = actual -> next;
    }

    if(flag==true){
        return true;

    }
    else{
        return false;

    }
    
}

int addListValues(){

    Node *actual=head;
    int addition = 0;
    while (actual != NULL)
    {
        addition += actual -> data;
        actual = actual -> next;
    }

    return addition;
}

double averageListValues(int x){


    Node *actual=head;
    int totalElements = 0;
    while (actual != NULL)
    {
        totalElements++;
        actual = actual -> next;
    }

    return x/totalElements;
}



