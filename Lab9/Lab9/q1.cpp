//#include <iostream>
//using namespace std;
//
//class ArrayAVLTree {
//    int* tree;
//    int capacity;
//    int currentSize;
//
//public:
//    ArrayAVLTree(int size) {
//        capacity = size;
//        tree = new int[capacity];
//        currentSize = 0;
//        for (int i = 0; i < capacity; ++i)
//            tree[i] = -1;
//    }
//
//    int isEmpty() {
//        return currentSize == 0;
//    }
//
//    int search(int val) {
//        return searchHelper(0, val);
//    }
//
//    void insert(int val) {
//        if (currentSize == capacity) {
//            cout << "Tree is full.\n";
//            return;
//        }
//        insertHelper(0, val);
//        currentSize++;
//        cout << "Inserted " << val << " and balanced tree:\n";
//        displayInOrder(0);  
//        cout << "\n";
//    }
//
//    void deleteNode(int val) {
//        if (isEmpty() || search(val) == 0) {
//            cout << "Value not found.\n";
//            return;
//        }
//        deleteHelper(0, val);
//        currentSize--;
//        cout << "Deleted " << val << " and balanced tree:\n";
//        displayInOrder(0);  
//        cout << "\n";
//    }
//
//    int isBalanced() {
//        return isBalancedHelper(0) != -1;
//    }
//
//    void displayInOrder(int index) {
//        if (index >= capacity || tree[index] == -1) return;
//        displayInOrder(2 * index + 1);
//        cout << tree[index] << " ";
//        displayInOrder(2 * index + 2);
//    }
//
//    void displayPreOrder(int index) {
//        if (index >= capacity || tree[index] == -1) return;
//        cout << tree[index] << " ";
//        displayPreOrder(2 * index + 1);
//        displayPreOrder(2 * index + 2);
//    }
//
//    void displayPostOrder(int index) {
//        if (index >= capacity || tree[index] == -1) return;
//        displayPostOrder(2 * index + 1);
//        displayPostOrder(2 * index + 2);
//        cout << tree[index] << " ";
//    }
//
//
//    int searchHelper(int index, int val) {
//        if (index >= capacity || tree[index] == -1) return 0;
//        if (tree[index] == val) return 1;
//        if (val < tree[index]) return searchHelper(2 * index + 1, val);
//        return searchHelper(2 * index + 2, val);
//    }
//
//    void insertHelper(int index, int val) {
//        if (index >= capacity) return;
//        if (tree[index] == -1) {
//            tree[index] = val;
//        }
//        else if (val < tree[index]) {
//            insertHelper(2 * index + 1, val);
//        }
//        else {
//            insertHelper(2 * index + 2, val);
//        }
//        balanceTree(index);
//    }
//
//    void deleteHelper(int index, int val) {
//        if (index >= capacity || tree[index] == -1) return;
//        if (val < tree[index]) {
//            deleteHelper(2 * index + 1, val);
//        }
//        else if (val > tree[index]) {
//            deleteHelper(2 * index + 2, val);
//        }
//        else {
//            if (tree[2 * index + 1] == -1 && tree[2 * index + 2] == -1) {
//                tree[index] = -1;
//            }
//            else if (tree[2 * index + 1] == -1) {
//                tree[index] = replaceNode(2 * index + 2);
//            }
//            else if (tree[2 * index + 2] == -1) {
//                tree[index] = replaceNode(2 * index + 1);
//            }
//            else {
//                int maxIndex = findMax(2 * index + 1);
//                tree[index] = tree[maxIndex];
//                deleteHelper(maxIndex, tree[maxIndex]);
//            }
//            balanceTree(index);
//        }
//    }
//
//    int findMax(int index) {
//        while (index < capacity && tree[2 * index + 2] != -1)
//            index = 2 * index + 2;
//        return index;
//    }
//
//    int isBalancedHelper(int index) {
//        if (index >= capacity || tree[index] == -1) return 0;
//        int leftHeight = isBalancedHelper(2 * index + 1);
//        if (leftHeight == -1) return -1;
//        int rightHeight = isBalancedHelper(2 * index + 2);
//        if (rightHeight == -1) return -1;
//        int bf = leftHeight - rightHeight;
//        if (bf < -1 || bf > 1) return -1;
//        return max(leftHeight, rightHeight) + 1;
//    }
//
//    void balanceTree(int index) {
//        int bf = balanceFactor(index);
//        if (bf > 1) {
//            if (balanceFactor(2 * index + 1) >= 0) {
//                rotateRight(index); 
//            }
//            else {
//                rotateLeft(2 * index + 1); 
//                rotateRight(index);
//            }
//        }
//        else if (bf < -1) {
//            if (balanceFactor(2 * index + 2) <= 0) {
//                rotateLeft(index); 
//            }
//            else {
//                rotateRight(2 * index + 2); 
//                rotateLeft(index);
//            }
//        }
//    }
//
//    int balanceFactor(int index) {
//        return height(2 * index + 1) - height(2 * index + 2);
//    }
//
//    int height(int index) {
//        if (index >= capacity || tree[index] == -1) return 0;
//        int leftHeight = height(2 * index + 1);
//        int rightHeight = height(2 * index + 2);
//        return max(leftHeight, rightHeight) + 1;
//    }
//
//    void rotateRight(int index) {
//        int leftIndex = 2 * index + 1;
//        int temp = tree[index];
//        tree[index] = tree[leftIndex];
//        tree[leftIndex] = tree[2 * leftIndex + 2];
//        tree[2 * leftIndex + 2] = temp;
//
//     
//        tree[2 * leftIndex + 2] = tree[leftIndex];
//        tree[leftIndex] = temp;
//    }
//
//    void rotateLeft(int index) {
//        int rightIndex = 2 * index + 2;
//        int temp = tree[index];
//        tree[index] = tree[rightIndex];
//        tree[rightIndex] = tree[2 * rightIndex + 1];
//        tree[2 * rightIndex + 1] = temp;
//
//        
//        tree[2 * rightIndex + 1] = tree[rightIndex];
//        tree[rightIndex] = temp;
//    }
//
//    int replaceNode(int index) {
//        int value = tree[index];
//        tree[index] = -1;
//        return value;
//    }
//};
//
//int main() {
//    int size;
//    cout << "Enter tree capacity: ";
//    cin >> size;
//
//    ArrayAVLTree avlTree(size);
//
//    avlTree.insert(30);
//    avlTree.insert(20);
//    avlTree.insert(10);  
//    avlTree.insert(40);
//    avlTree.insert(50);  
//    avlTree.insert(25);  
//    avlTree.insert(60);  
//
//    cout << "Inorder traversal:\n";
//    avlTree.displayInOrder(0);
//    cout << "\n";
//
//    cout << "Preorder traversal:\n";
//    avlTree.displayPreOrder(0);
//    cout << "\n";
//
//    cout << "Postorder traversal:\n";
//    avlTree.displayPostOrder(0);
//    cout << "\n";
//
//    if (avlTree.search(20)) cout << "Element 20 found.\n";
//    else cout << "Element 20 not found.\n";
//
//    if (avlTree.isBalanced()) cout << "The tree is balanced.\n";
//    else cout << "The tree is not balanced.\n";
//
//    avlTree.deleteNode(20);
//    cout << "After deleting 20, inorder traversal:\n";
//    avlTree.displayInOrder(0);
//    cout << "\n";
//
//    return 0;
//}
