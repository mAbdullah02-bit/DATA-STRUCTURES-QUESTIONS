#include <iostream>
using namespace std;

void initializeHashTable(int hashTable[], int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }
}

void insertValue(int hashTable[], int tableSize, int value) {
    int hashIndex = value % tableSize;

    while (hashTable[hashIndex] != -1) {
        hashIndex = (hashIndex + 1) % tableSize;
    }

    hashTable[hashIndex] = value;
}

void displayHashTable(int hashTable[], int tableSize) {
    cout << "Index\tValue" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << i << "\t";
        if (hashTable[i] != -1) {
            cout << hashTable[i];
        }
        else {
            cout << "-";
        }
        cout << endl;
    }
}

int main() {
    const int tableSize = 20;
    int hashTable[tableSize];

    initializeHashTable(hashTable, tableSize);

    int data[] = { 18, 20, 23, 31, 37, 42, 47, 51, 79, 82, 85, 94, 96, 97 };
    int dataSize = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < dataSize; i++) {
        insertValue(hashTable, tableSize, data[i]);
    }

    displayHashTable(hashTable, tableSize);

    return 0;
}
