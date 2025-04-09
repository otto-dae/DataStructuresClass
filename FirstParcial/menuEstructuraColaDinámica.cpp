#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void menu();
void addToTail(Node *&, Node *&, int);
void deleteFromTail(Node *&, Node *&);
void showList();
bool searchElement(Node *, int);

int main() {
    menu();
    return 0;
}

void menu() {
    int option, value;
    bool running = true;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add to tail" << endl;
        cout << "2. Show elements" << endl;
        cout << "3. Delete from tail" << endl;
        cout << "4. Exit" << endl;
        cout << "5. Search an element" << endl;
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                addToTail(head, tail, value);
                break;

            case 2:
                showList();
                break;

            case 3:
                deleteFromTail(head, tail);
                break;

            case 4:
                running = false;
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchElement(head, value)) {
                    cout << "Value " << value << " was found in the list." << endl;
                } else {
                    cout << "Value " << value << " was NOT found in the list." << endl;
                }
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }

    } while (running);
}

void addToTail(Node *&head, Node *&tail, int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }

    tail = newNode;
    cout << "Element has been added to the tail." << endl;
}

void deleteFromTail(Node *&head, Node *&tail) {
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }

    Node *toDelete = head;

    if (head != tail) {
        head = head->next;
        delete toDelete;
    } else {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    cout << "Element has been deleted from the tail." << endl;
}

void showList() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node *current = head;
    int index = 0;

    while (current != nullptr) {
        cout << index++ << ": " << current->data << endl;
        current = current->next;
    }
}

bool searchElement(Node *head, int value) {
    Node *current = head;

    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}
