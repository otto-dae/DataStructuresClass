#include <cstdlib>
#include <iostream>
#include "colors.h"

using namespace std;

struct Node{
    int data;
    Node *next;
};

void menu();
void insertList(Node *&, int);

Node *head=NULL;

int main(){

    system("clear");

    int option, n;
    bool loop = true;

    do
    {
        cout << "\t DYNAMIC SYMPLY LINKED LIST MENU" << endl;
        cout << "\n 1.- Insert list" << endl;
        cout << "Select an option " <<endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Insert an full number " << endl;
            cin >> n;
            insertList(head, n);
            break;
        
        default:
        loop = false;
            break;
        }

    } while (loop);

}

void iinsertList (Node *& head, int n){
    Node * new_node = new Node();
    new_node -> data = n;
    Node *tail=head;
    Node *aux;

    while ((tail!=NULL) && (tail->data<n)){
        aux = tail;
        tail = tail -> next;
    }
    if(head==tail){
        head=new_node;
    }else{
        aux = new_node;
    }
    new_node -> next = tail;
    cout << "Element added to list" << endl;
}