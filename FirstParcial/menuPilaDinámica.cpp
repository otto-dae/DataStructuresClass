#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertUnique(int value);
void pop();
void showStack();
void removeMultiple(int count);
void removeUntilValue(int value);
void reverseStack();
void clearStack();

Node* top = nullptr;

int main() {
    int option, value;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert value (no duplicates)\n";
        cout << "2. Show stack\n";
        cout << "3. Remove top element\n";
        cout << "4. Remove multiple elements\n";
        cout << "5. Remove until a value\n";
        cout << "6. Reverse stack\n";
        cout << "7. Clear stack\n";
        cout << "8. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertUnique(value);
            break;
        case 2:
            showStack();
            break;
        case 3:
            pop();
            break;
        case 4:
            cout << "How many elements to remove? ";
            cin >> value;
            removeMultiple(value);
            break;
        case 5:
            cout << "Remove until reaching number: ";
            cin >> value;
            removeUntilValue(value);
            break;
        case 6:
            reverseStack();
            cout << "Stack reversed.\n";
            break;
        case 7:
            clearStack();
            cout << "Stack cleared.\n";
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option.\n";
        }

    } while (option != 8);

    return 0;
}


void insertUnique(int value) {
    Node* temp = top;
    while (temp) {
        if (temp->data == value) {
            cout << "Value " << value << " already exists. Not inserted.\n";
            return;
        }
        temp = temp->next;
    }
    Node* newNode = new Node{value, top};
    top = newNode;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

void showStack() {
    cout << "\nThe stack contains:\n";
    Node* temp = top;
    cout << "TOP\n";
    while (temp) {
        cout << "|" << temp->data << "|\n";
        temp = temp->next;
    }
    cout << endl;
}

void removeMultiple(int count) {
    for (int i = 0; i < count && top != nullptr; i++) {
        pop();
    }
}

void removeUntilValue(int value) {
    while (top && top->data != value) {
        pop();
    }
}

void reverseStack() {
    Node* prev = nullptr;
    Node* current = top;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top = prev;
}

void clearStack() {
    while (top) {
        pop();
    }
}
