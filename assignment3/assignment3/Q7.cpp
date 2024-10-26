//#include"AVL7.h"
//#include<iostream>
//
//using namespace std;
//
//
//int main() {
//    AvlTree T1, T2;
//    int id;
//
//    for (int i = 0; i < 5; ++i) {
//        cout << "Enter Data for T1: ";
//        cin >> id;
//        T1.root = T1.insert(T1.root, id);
//    }
//
//    cout << "Tree T1 (Inorder):" << endl;
//    T1.inorder(T1.root);
//
//    for (int i = 0; i < 4; ++i) {
//        cout << "Enter Data for T2: ";
//        cin >> id;
//        T2.root = T2.insert(T2.root, id);
//    }
//
//    cout << "Tree T2 (Inorder):" << endl;
//    T2.inorder(T2.root);
//
//
//    T1.mergeTrees(T1.root, T2.root);
//    cout << "Merged Tree T1 (Inorder):" << endl;
//    T1.inorder(T1.root);
//
//    if (T1.isAVL(T1.root)) {
//        cout << "The tree is AVL balanced." << endl;
//    }
//    else {
//        cout << "The tree is not AVL balanced." << endl;
//    }
//
//    return 0;
//}
