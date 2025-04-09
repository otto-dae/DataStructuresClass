#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* fileName = "data.bin";
    int numbers[5] = {10, 20, 30, 40, 50};

    ofstream writeFile(fileName, ios::binary);
    if (!writeFile) {
        cout << "Failed to create the file." << endl;
        return 1;
    }

    writeFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    writeFile.close();

    ifstream readFile(fileName, ios::binary);
    if (!readFile) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int readNumbers[5];
    readFile.read(reinterpret_cast<char*>(readNumbers), sizeof(readNumbers));
    readFile.close();

    cout << "Numbers read from the binary file:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << readNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}
