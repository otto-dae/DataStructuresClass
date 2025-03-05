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

    while (actual != NULL)
    {
        cout << actual -> data << endl;
        actual = actual -> next;
    }
    
}

