#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            cout << "NULL ";
        else
            cout << arr[i] << " ";
    }
    cout << endl;
}

int hashfunction(int k, int size) { return (k % size); }

int secondaryHash(int k, int size) { return (1 + (k % (size - 1))); }

void rehash(int* table, int& tsize, int& count)
{
    cout << "Rehashing initiated...\n";
    int oldSize = tsize;
    tsize *= 2; 
    int* newTable = new int[tsize];

    
    for (int i = 0; i < tsize; i++) {
        newTable[i] = -1;
    }

    
    for (int i = 0; i < oldSize; i++) {
        if (table[i] != -1) { 
            int hv = hashfunction(table[i], tsize);
            int offset = secondaryHash(table[i], tsize);

            if (newTable[hv] == -1) {
                newTable[hv] = table[i];
            }
            else {
                for (int j = 1; j <= tsize; j++) {
                    int hv2 = (hv + j * offset) % tsize;
                    if (newTable[hv2] == -1) {
                        newTable[hv2] = table[i];
                        break;
                    }
                }
            }
        }
    }

    delete[] table;
    table = newTable; 
    count = 0; 
    cout << "Rehashing complete. New table size: " << tsize << endl;
}

void doubleHashing(int* table, int& tsize, int arr[], int n)
{
    int max_elements = 0.7 * tsize; 
    int count = 0;                  

    for (int i = 0; i < n; i++) {
        if (count >= max_elements) {
            rehash(table, tsize, count); 
            max_elements = 0.7 * tsize;  
        }

        int hv = hashfunction(arr[i], tsize);
        int offset = secondaryHash(arr[i], tsize);

        if (table[hv] == -1) {
            table[hv] = arr[i];
            count++;
        }
        else {
            for (int j = 1; j <= tsize; j++) {
                int hv2 = (hv + j * offset) % tsize;

                if (table[hv2] == -1) {
                    table[hv2] = arr[i];
                    count++;
                    break;
                }
            }
        }
    }

    printArray(table, tsize); 
}

int main()
{
    int arr[] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int tsize = 15;
    int* hash_table = new int[tsize];

    for (int i = 0; i < tsize; i++) {
        hash_table[i] = -1;
    }

    cout << "PART 2: Double Hashing with Rehashing\n";
    doubleHashing(hash_table, tsize, arr, n);

    delete[] hash_table;

    return 0;
}
