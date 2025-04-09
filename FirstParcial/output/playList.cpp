#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Node {
    string data;
    Node *next;
};

Node *head = NULL;
Node *currentSong = NULL; // Keeps track of currently playing song

void insertList(Node *&, const string &);
void showList();
void playSong();
void nextSong();
void deleteFromList(Node *&, const string &);

int main() {
    system("clear"); // Use "cls" on Windows

    int option;
    string song;
    bool loop = true;

    do {
        cout << "\n\t--- Playlist Menu ---\n";
        cout << "1. Insert song\n";
        cout << "2. Show playlist\n";
        cout << "3. Play current song\n";
        cout << "4. Delete a song\n";
        cout << "5. Next song\n";
        cout << "6. Exit\n";
        cout << "Select an option: ";
        cin >> option;
        cin.ignore();

        switch (option) {
        case 1:
            cout << "Enter song title: ";
            getline(cin, song);
            insertList(head, song);
            break;
        case 2:
            showList();
            break;
        case 3:
            playSong();
            break;
        case 4:
            cout << "Enter song title to delete: ";
            getline(cin, song);
            deleteFromList(head, song);
            break;
        case 5:
            nextSong();
            break;
        case 6:
            loop = false;
            break;
        default:
            cout << "Invalid option.\n";
            break;
        }

    } while (loop);

    return 0;
}

void insertList(Node *&head, const string &song) {
    Node *new_node = new Node();
    new_node->data = song;

    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
        currentSong = new_node;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }

    cout << "Song \"" << song << "\" added to playlist.\n";
}

void showList() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node *current = head;
    int index = 1;
    do {
        cout << index++ << ". " << current->data << endl;
        current = current->next;
    } while (current != head);
}

void playSong() {
    if (currentSong == NULL) {
        cout << "Playlist is empty. Nothing to play.\n";
    } else {
        cout << "Now playing: " << currentSong->data << endl;
        cout << "Playing . . .\n";
    }
}

void nextSong() {
    if (currentSong == NULL) {
        cout << "Playlist is empty. Nothing to skip.\n";
    } else {
        currentSong = currentSong->next;
        cout << "Now playing: " << currentSong->data << endl;
        cout << "Playing . . .\n";
    }
}

void deleteFromList(Node *&head, const string &song) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node *current = head;
    Node *prev = NULL;

    do {
        if (current->data == song) {
            if (current == head) {
                if (head->next == head) {
                    delete head;
                    head = NULL;
                    currentSong = NULL;
                    cout << "Song \"" << song << "\" deleted. Playlist is now empty.\n";
                    return;
                } else {
                    Node *last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                    if (currentSong == current) currentSong = head;
                    delete current;
                    cout << "Song \"" << song << "\" deleted.\n";
                    return;
                }
            } else {
                prev->next = current->next;
                if (currentSong == current) currentSong = current->next;
                delete current;
                cout << "Song \"" << song << "\" deleted.\n";
                return;
            }
        }

        prev = current;
        current = current->next;
    } while (current != head);

    cout << "Song \"" << song << "\" not found.\n";
}
