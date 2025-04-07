#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void menu();
void addToTail(Node *&, Node *&, int);
void deleteFromTail(Node *&, Node *&);
void showList();

int main(){
    menu();
    return 0;
}

void menu(){
    int option, n;
    bool flag = true;

    do
    {
        cout << "1.- Add to tail" << endl;
        cout << "2.- Show elements" << endl;
        cout << "3.- Delete from tail" << endl;
        cout << "4.- Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Insert value to insert: " << endl;
            cin >>n;
            addToTail(head, tail, n);
            break;

        case 2:
            showList();
            break;
            
        case 3:
            deleteFromTail(head, tail);
        break;

        case 4:
        flag = false;
        default:
            break;
        }

    } while (flag == true);
    
}

void addToTail(Node *& head, Node *& tail, int n){
    
    Node *new_node = new Node();
    new_node ->data=n;
    new_node->next=nullptr;
    if(head==nullptr){
        head=new_node;
    }else{
        tail->next = new_node;
    }

    tail=new_node;
    cout << "Element has been added" << endl;
}

void deleteFromTail(Node *& head, Node *& tail){

    Node *aux_delete = head;

    if(head!=tail){
        head=head->next;
        delete aux_delete;
    }else{
        head=nullptr;
        tail=nullptr;

    }
    cout << "Element has been deleted from tail" << endl;

}

void showList(){
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *actual = head;
    int element = 0;
    while (actual != nullptr){
        cout << element++ << ": " << actual->data << endl;
        actual = actual->next;
    } 
}
