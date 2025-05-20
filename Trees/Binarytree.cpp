#include <cstdlib>
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
    Node *father;
};

void menu();
Node *createNode(int, Node *);
void insertNode(Node *&, int, Node *);
void showTree(Node *, int);
bool searchNode(Node *, int);
void showPreOrder(Node *);
void showInOrder(Node *);
void showPosOrder(Node *);
void deleteNode(Node *, int);
void deleteFoundedNode(Node *, int);
Node *minimumNode(Node *);
void replaceNode(Node *, Node *);
void destroyNode(Node *);

Node *tree = NULL;

int main(){
    system("clear");
    menu();
    return 0;
}

void menu(){
    int data, option, count = 0;
    bool loop = true;

    do{
        cout << "Menu" << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Show entire tree" << endl;
        cout << "3. Search Node" << endl;
        cout << "4. Show PreOrder" << endl;
        cout << "5. Show InOrder" << endl;
        cout << "6. Show PosOrder" << endl;
        cout << "7. Delete node from tree" << endl;
        cout << "8. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Insert a number" << endl;
            cin >> data;
            insertNode(tree, data, NULL);
            cout << endl;
            break;
        case 2:
            cout << "Show the entire tree" << endl;
            showTree(tree, 0);
            cout << endl;
            break;  
        case 3:
            cout << "Insert the node to search" << endl;
            cin >> data;
            if(searchNode(tree, data) == true){
                cout << "Element " << data << " found" << endl;
            }else{
                cout << "Element " << data << " not found" << endl;
            }
            break;
        case 4:
            cout << "Show PreOrder" << endl;
            showPreOrder(tree);
            cout << endl;
            break;  
        case 5:
            cout << "Show InOrder" << endl;
            showInOrder(tree);
            cout << endl;
            break;
        case 6:
            cout << "Show PosOrder" << endl;
            showPosOrder(tree);
            cout << endl;
            break;    
        case 7:
            cout << "Insert element to delete" << endl;
            deleteNode(tree, data);
            cout << endl;
            break;    
            case 8:
                loop = false;
            break;
        default:
            cout << "Select an acceptable option" << endl;
            break;
        }

    }while(loop = true);



}

Node *createNode(int n, Node *father){
    Node *newNode = new Node();

    newNode->data=n;
    newNode->right=NULL;
    newNode->left=NULL;
    newNode->father=father;

    return newNode;
}

void insertNode(Node *&tree, int n, Node* father){
    if(tree = NULL){
        Node *newNode = createNode(n, father);
        tree = newNode;
    }else{
        int rootValue = tree->data;
    
        if(n < rootValue){
            insertNode(tree->left, n , tree);
        }else{
            insertNode(tree->right, n , tree);
        }
    }
}

