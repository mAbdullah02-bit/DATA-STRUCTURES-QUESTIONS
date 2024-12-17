////#include <iostream>
////using namespace std;
////
////void printArray(int arr[], int n)
////{
////  
////
////    for (int i = 0; i < n; i++) {
////        cout << arr[i] << " ";
////    }
////    cout << endl;
////}
////
////int hashfunction(int k, int size) { return (k % size); }
////
////void hashing(int table[], int tsize, int arr[], int n)
////{
////    for (int i = 0; i < n; i++) {
////        int hv = hashfunction(arr[i], tsize); 
////
////        if (table[hv] == -1)
////            table[hv] = arr[i]; 
////        else {
////            for (int j = 1; j <= tsize; j++) {
////                int hv2 = (arr[i] + j * j) % tsize; 
////
////                if (table[hv2] == -1) {
////                    table[hv2] = arr[i]; 
////                    break;
////                }
////            }
////        }
////    }
////    printArray(table, tsize); 
////}
////
////int main()
////{
////    int arr[] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
////    int n = sizeof(arr) / sizeof(arr[0]);
////
////    int tsize = 15;
////    int* hash_table = new int[tsize];
////
////    
////    for (int i = 0; i < tsize; i++) {
////        hash_table[i] = -1;
////    }
////
////    cout << "PART 1: \n";
////    hashing(hash_table, tsize, arr, n);
////
////    delete[] hash_table; 
////    return 0;
////}
////
//#include <iostream>
//using namespace std;
//
//void printArray(int arr[], int n)
//{
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int hashfunction(int k, int size) { return (k % size); }
//
//int secondaryHash(int k, int size) { return (1 + (k % (size - 1))); }
//
//void doubleHashing(int table[], int tsize, int arr[], int n)
//{
//    int max_elements = 0.7 * tsize; 
//    int count = 0; 
//
//    for (int i = 0; i < n; i++) {
//        if (count >= max_elements) {
//            cout << " 70% load reached.stopping to save performance ." << endl;
//            break;
//        }
//
//        int hv = hashfunction(arr[i], tsize); 
//        int offset = secondaryHash(arr[i], tsize); 
//
//        if (table[hv] == -1) {
//            table[hv] = arr[i];
//            count++;
//        }
//        else {
//           
//            for (int j = 1; j <= tsize; j++) {
//                int hv2 = (hv + j * offset) % tsize;
//
//                if (table[hv2] == -1) {
//                    table[hv2] = arr[i];
//                    count++;
//                    break;
//                }
//            }
//        }
//    }
//    printArray(table, tsize);
//}
//
//int main()
//{
//    int arr[] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    int tsize = 15;
//    int* hash_table = new int[tsize];
//
//    for (int i = 0; i < tsize; i++) {
//        hash_table[i] = -1;
//    }
//
//    cout << "PART 2: Double Hashing \n";
//    doubleHashing(hash_table, tsize, arr, n);
//
//    delete[] hash_table;
//
//    return 0;
//}
