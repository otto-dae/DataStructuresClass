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
void deleteFromList(Node *&, int);


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
        cout << "\n 4.- Delete from the list" << endl;
        cout << "\n 2.- Exit" << endl;

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
                cout << "Element " << n << "is in the list" <<endl;
            }
            else{
                cout << "Element " << n << "is not in the list" <<endl;

            }
            break;
        case 6:
            cout << "Delete a value: ";
            cin >> n;
            deleteFromList(head, n);
        break; 
        
        case 7:
        deleteWholeList(head);
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

void deleteFromList(Node *& head, int n){

    if(head!=nullptr){
        Node *aux_delete = head;
        Node * prev = nullptr;

        while ((aux_delete != nullptr) && (aux_delete -> data != n))
        {
            prev = aux_delete;
            aux_delete = aux_delete -> next;
            cout << "kjsadds";
        }

        if(aux_delete == nullptr){
            cout << "Element doesnt exist" << endl;
        }
        else if(prev == nullptr){
            head = head ->next;
            delete aux_delete;
        }
        else{
            prev ->next = aux_delete -> next;
            delete aux_delete;
        }

    }




    
}

void deleteWholeList(Node *& head){

        Node *aux_delete = head;
        Node *next_node = nullptr;
        while ((aux_delete != nullptr))
        {
            next_node = aux_delete -> next; 
            delete aux_delete;
            aux_delete = next_node;

        }

        head = nullptr;

}