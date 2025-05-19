#include <cstdlib>
#include <iostream>

using namespace std;

struct Node{
    int key;
    int value;
    Node *next;
};

const int HashTable_SIZE = 10;
Node *HashTable[HashTable_SIZE] = {nullptr};

void menu();
int hashFunction(int);
void insertToTable(Node *[], int, int);
void showTable(Node *[]);
int searchTable(Node *[], int);
void deleteFromTable(Node *[], int);

int main(){
    system("clear");
    menu();
}

void menu(){
    int option, key, value;
    bool flag = true;

    do
    {
        cout << "Hash Table Menu" << endl;
        cout << "1.- Insert element to table" << endl;  
        cout << "2.- Show table" << endl; 
        cout << "3.- Search element in table" << endl; 
        cout << "4.- Delete element from the table" << endl; 
        cout << "5.- Exit" << endl;     
        cin >> option;
        cout << endl;  

        switch (option)
        {
        case 1:
            cout << "Insert the key: " << endl;
            cin >> key;
            cout << "Insert the value: " << endl;
            cin >> value;
            insertToTable(HashTable, key, value);
            break;
        
        case 2:
            showTable(HashTable);
        break;
        case 3:
            cout << "Insert key to search: " << endl;
            cin >> key;
            value = searchTable(HashTable, key);
            if(value != 1){
                cout << "The key's value is : " << value << endl;
            }else{
                cout << "The key doesnt exist" << endl;
            }
        break;
        case 4:
            cout << "Insert key to delete: " << endl;
            cin >> key;
            deleteFromTable(HashTable, key);
        break;
        default:
            break;
        }
    } while (flag);
    
}

int hashFunction(int key){
    return key % HashTable_SIZE;
}

void insertToTable(Node *HashTable[], int key, int value){
    int index = hashFunction(key);
    Node *newNode  =new Node();
    newNode->key = key;
    newNode->value=value;
    newNode->next=nullptr;
    int opt;

    if(HashTable[index] == nullptr){
        HashTable[index] = newNode;
    }else{
        Node *current = HashTable[index];
        while (current != nullptr){
            if(current->key == key){
                cout << "You wish to override the current value? 1.- Y 2.- N " << endl;
                cin >> opt;
                if(opt == 1){
                    current->value = value;
                    delete newNode;
                    return;
                }else if(opt == 2){
                    cout << "Please select another index " << endl;
                    current = nullptr;
                    return;
                }

            }
            current = current->next;
        }
        current = HashTable[index];
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        
    }
}

void showTable(Node *HashTable[]){
    for (int i = 0; i < HashTable_SIZE; i++){
        cout << i << ": ";
        Node *current = HashTable[i];
        while (current != nullptr){
            cout << current->value;
            current = current->next;
        }
        cout << endl;   
    }
}

int searchTable(Node *HashTable[], int key){
    int index = hashFunction(key);
    Node *current = HashTable[index];

    while (current != nullptr){
        if(current->key == key){
            return current->value;
        }
    }
    return -1;
}

void deleteFromTable(Node *HashTable[], int key){
    int index = hashFunction(key);
    Node *current = HashTable[index];
    Node *previous = nullptr;

    while (current != nullptr){
        if(current->key == key){
            if(previous == nullptr){
                HashTable[index] = current->next;
            }else{
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "El elemento no se encontro" << endl;
    
}