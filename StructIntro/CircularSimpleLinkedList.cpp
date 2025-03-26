#include <cstdlib>
#include <iostream>
#include "colors.h"

using namespace std;

struct Node {
    int data;
    Node *next;
};

void insertList(Node *&, int);
void showList();
bool searchList(Node *, int);
int addListValues();
double averageListValues(int);
void deleteFromList(Node *&, int);
void deleteWholeList(Node *&);

Node *head = NULL;

int main() {
    system("clear");

    int option, n;
    bool loop = true;

    do {
        cout << "\t DYNAMIC CIRCULAR LINKED LIST MENU" << endl;
        cout << "\n 1.- Insert list" << endl;
        cout << "\n 2.- Show list" << endl;
        cout << "\n 3.- Search in list" << endl;
        cout << "\n 4.- Add all values in list" << endl;
        cout << "\n 5.- Average all values in list" << endl;
        cout << "\n 6.- Delete from the list" << endl;
        cout << "\n 7.- Delete whole list" << endl;

        cout << "Select an option " << endl;
        cin >> option;

        switch (option) {
        case 1:
            cout << "Insert a number: " << endl;
            cin >> n;
            insertList(head, n);
            break;

        case 2:
            showList();
            break;

        case 3:
            cout << "Insert element to search: ";
            cin >> n;
            if (searchList(head, n)) {
                cout << "Element " << n << " is in the list" << endl;
            } else {
                cout << "Element " << n << " is not in the list" << endl;
            }
            break;

        case 4:
            cout << "The sum of all values is: " << addListValues() << endl;
            break;

        case 5:
            cout << "The average of all values is: " << averageListValues(addListValues()) << endl;
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

void insertList(Node *&head, int n) {
    Node *new_node = new Node();
    new_node->data = n;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        Node *actual = head;
        while (actual->next != head && actual->data < n) {
            actual = actual->next;
        }

        if (actual->data >= n) {
            new_node->next = actual;
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            head = new_node;
        } else {
            new_node->next = actual->next;
            actual->next = new_node;
        }
    }

    cout << "Element added to list" << endl;
}

void showList() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *actual = head;
    int element = 0;
    do {
        cout << element++ << ": " << actual->data << endl;
        actual = actual->next;
    } while (actual != head);  
}

bool searchList(Node *head, int n) {
    if (head == NULL) return false;

    Node *actual = head;
    do {
        if (actual->data == n) {
            return true;
        }
        actual = actual->next;
    } while (actual != head); 
    return false;
}

int addListValues() {
    if (head == NULL) return 0;

    Node *actual = head;
    int sum = 0;
    do {
        sum += actual->data;
        actual = actual->next;
    } while (actual != head);

    return sum;
}

double averageListValues(int totalSum) {
    if (head == NULL) return 0.0;

    Node *actual = head;
    int totalElements = 0;
    do {
        totalElements++;
        actual = actual->next;
    } while (actual != head); 

    return totalElements == 0 ? 0.0 : static_cast<double>(totalSum) / totalElements;
}

void deleteFromList(Node *&head, int n) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *actual = head;
    Node *prev = NULL;

    do {
        if (actual->data == n) {
            if (prev == NULL) { 
                if (actual->next == head) {  
                    delete actual;
                    head = NULL;
                    return;
                } else {
                    Node *last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = actual->next;
                    last->next = head;
                    delete actual;
                    return;
                }
            } else { 
                prev->next = actual->next;
                delete actual;
                return;
            }
        }
        prev = actual;
        actual = actual->next;
    } while (actual != head);  
    cout << "Element " << n << " not found" << endl;
}

void deleteWholeList(Node *&head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *actual = head;
    Node *next_node = NULL;
    do {
        next_node = actual->next;
        delete actual;
        actual = next_node;
    } while (actual != head);  

    head = NULL;
    cout << "All elements deleted from list" << endl;
}
