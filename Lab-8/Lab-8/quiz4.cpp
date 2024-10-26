//#include <iostream>
//using namespace std;
//
//int binarySearch(int arr[], int left, int right, int target) {
//    if (left <= right) {
//        int mid = left + (right - left) / 2;
//
//        // Check if the target is at the middle
//        if (arr[mid] == target) {
//            return mid; // Target found
//        }
//        // If the target is greater, search in the right half
//        else if (arr[mid] < target) {
//            return binarySearch(arr, mid + 1, right, target);
//        }
//        // If the target is smaller, search in the left half
//        else {
//            return binarySearch(arr, left, mid - 1, target);
//        }
//    }
//    return -1; // Target not found
//}
//
//int main() {
//    int arr[] = { 2, 3, 4, 10, 40, 50 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    int target = 10;
//
//    int result = binarySearch(arr, 0, size - 1, target);
//
//    if (result != -1) {
//        cout << "Element found at index: " << result << endl;
//    }
//    else {
//        cout << "Element not found in array." << endl;
//    }
//
//    return 0;
//}