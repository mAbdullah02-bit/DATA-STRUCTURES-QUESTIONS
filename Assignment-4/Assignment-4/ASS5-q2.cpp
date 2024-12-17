//////#include <iostream>
//////using namespace std;
//////
//////struct Node {
//////    int data;
//////    Node* next;
//////
//////    Node(int value) : data(value), next(nullptr) {}
//////};
//////
//////void insert(Node*& head, int value) {
//////    Node* newNode = new Node(value);
//////    if (head == nullptr) {
//////        head = newNode;
//////    }
//////    else {
//////        Node* temp = head;
//////        while (temp->next != nullptr) {
//////            temp = temp->next;
//////        }
//////        temp->next = newNode;
//////    }
//////}
//////
//////void printChain(Node* head) {
//////    Node* temp = head;
//////    while (temp != nullptr) {
//////        cout << temp->data << " -> ";
//////        temp = temp->next;
//////    }
//////    cout << "NULL";
//////}
//////
//////void printHashTable(Node* hashTable[], int size) {
//////    for (int i = 0; i < size; i++) {
//////        cout << "Index " << i << ": ";
//////        if (hashTable[i] != nullptr) {
//////            printChain(hashTable[i]);
//////        }
//////        else {
//////            cout << "NULL";
//////        }
//////        cout << endl;
//////    }
//////}
//////
//////int hashfunction(int k, int size) {
//////    return k % size;
//////}
//////
//////Node** rehash(Node* oldTable[], int& tsize, int& count) {
//////    cout << "\nRehashing initiated...\n";
//////    cout << "Hash table before rehashing:\n";
//////    printHashTable(oldTable, tsize);
//////
//////    int oldSize = tsize;
//////    tsize *= 2; 
//////    count = 0;  
//////
//////
//////    Node** newTable = new Node * [tsize];
//////    for (int i = 0; i < tsize; i++) {
//////        newTable[i] = nullptr;
//////    }
//////
//////  
//////    for (int i = 0; i < oldSize; i++) {
//////        Node* current = oldTable[i];
//////        while (current != nullptr) {
//////            int hv = hashfunction(current->data, tsize);
//////            insert(newTable[hv], current->data);
//////            count++;  
//////            current = current->next;
//////        }
//////    }
//////
//////   
//////    for (int i = 0; i < oldSize; i++) {
//////        Node* current = oldTable[i];
//////        while (current != nullptr) {
//////            Node* temp = current;
//////            current = current->next;
//////            delete temp;
//////        }
//////    }
//////    delete[] oldTable;
//////
//////    cout << "Rehashing complete. New table size: " << tsize << endl;
//////    cout << "Hash table after rehashing:\n";
//////    printHashTable(newTable, tsize);
//////
//////    return newTable;
//////}
//////
//////Node** chaining(Node* hashTable[], int& tsize, int arr[], int n) {
//////    int max_elements = 0.7 * tsize;
//////    int count = 0;                  
//////
//////    for (int i = 0; i < n; i++) {
//////        if (count >= max_elements) {
//////            cout << "\n70% load reached. Rehashing...\n";
//////            hashTable = rehash(hashTable, tsize, count);
//////            max_elements = 0.7 * tsize;  
//////        }
//////
//////        int hv = hashfunction(arr[i], tsize);  
//////        insert(hashTable[hv], arr[i]);         
//////        count++;
//////    }
//////
//////    cout << "\nFinal Hash Table after all insertions:\n";
//////    printHashTable(hashTable, tsize); 
//////    return hashTable; 
//////}
//////
//////void deleteHashTable(Node* hashTable[], int size) {
//////    for (int i = 0; i < size; i++) {
//////        Node* current = hashTable[i];
//////        while (current != nullptr) {
//////            Node* temp = current;
//////            current = current->next;
//////            delete temp;
//////        }
//////    }
//////    delete[] hashTable;
//////}
//////
//////int main() {
//////    int arr[] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
//////    int n = sizeof(arr) / sizeof(arr[0]);
//////
//////    int tsize = 15;
//////    Node** hashTable = new Node * [tsize];  
//////    for (int i = 0; i < tsize; i++) {
//////        hashTable[i] = nullptr;
//////    }
//////
//////    cout << "PART 2: Hashing with Chaining and Rehashing \n";
//////    hashTable = chaining(hashTable, tsize, arr, n);
//////
//////    deleteHashTable(hashTable, tsize); 
//////
//////    return 0;
//////}
//
//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* next;
//
//    Node(int value) : data(value), next(nullptr) {}
//};
//
//void insert(Node*& head, int value) {
//    Node* newNode = new Node(value);
//    if (head == nullptr) {
//        head = newNode;
//    }
//    else {
//        Node* temp = head;
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        temp->next = newNode;
//    }
//}
//
//void printChain(Node* head) {
//    Node* temp = head;
//    while (temp != nullptr) {
//        cout << temp->data << " -> ";
//        temp = temp->next;
//    }
//    cout << "NULL";
//}
//
//void printHashTable(Node** hashTable[], int bucketCount, int bucketSize) {
//    for (int i = 0; i < bucketCount; i++) {
//        cout << "Bucket " << i << ":" << endl;
//        for (int j = 0; j < bucketSize; j++) {
//            if (hashTable[i][j] != nullptr) {
//                cout << "  Entry " << j << ": ";
//                printChain(hashTable[i][j]);
//                cout << endl;
//            }
//            else {
//                cout << "  Entry " << j << ": NULL" << endl;
//            }
//        }
//    }
//}
//
//int hashFunction(int k, int bucketCount) {
//    return k % bucketCount;
//}
//
//void insertIntoBucket(Node** hashTable[], int bucketCount, int bucketSize, int value) {
//    int bucketIndex = hashFunction(value, bucketCount);
//
//   
//    for (int i = 0; i < bucketSize; i++) {
//        if (hashTable[bucketIndex][i] == nullptr) {
//            hashTable[bucketIndex][i] = new Node(value);
//            return;
//        }
//    }
//
//  
//    insert(hashTable[bucketIndex][bucketSize - 1], value);
//}
//
//void chainingWithBuckets(Node** hashTable[], int bucketCount, int bucketSize, int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        insertIntoBucket(hashTable, bucketCount, bucketSize, arr[i]);
//    }
//    cout << "\nFinal Hash Table with Buckets:\n";
//    printHashTable(hashTable, bucketCount, bucketSize);
//}
//
//void deleteHashTable(Node** hashTable[], int bucketCount, int bucketSize) {
//    for (int i = 0; i < bucketCount; i++) {
//        for (int j = 0; j < bucketSize; j++) {
//            Node* current = hashTable[i][j];
//            while (current != nullptr) {
//                Node* temp = current;
//                current = current->next;
//                delete temp;
//            }
//            hashTable[i][j] = nullptr;
//        }
//        delete[] hashTable[i];
//    }
//    delete[] hashTable;
//}
//
//int main() {
//    int arr[] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    const int bucketCount = 3; 
//    const int bucketSize = 3; 
//
//    
//    Node*** hashTable = new Node * *[bucketCount];
//    for (int i = 0; i < bucketCount; i++) {
//        hashTable[i] = new Node * [bucketSize];
//        for (int j = 0; j < bucketSize; j++) {
//            hashTable[i][j] = nullptr; 
//        }
//    }
//
//    cout << "PART 3: Hashing with Bucketing\n";
//    chainingWithBuckets(hashTable, bucketCount, bucketSize, arr, n);
//
//    deleteHashTable(hashTable, bucketCount, bucketSize);
//
//    return 0;
//}
//
