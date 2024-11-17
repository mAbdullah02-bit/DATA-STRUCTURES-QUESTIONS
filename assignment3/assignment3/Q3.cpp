//#include "headers.h"
//
//void menu() {
//    cout << "1. Insert" << endl;
//    cout << "2. Display Inorder" << endl;
//    cout << "3. Find Maximum Path Sum" << endl;
//    cout << "4. Exit" << endl;
//}
//
//int main()
//{
//    BST tree;
//    int choice, value;
//    while (true) {
//        menu();
//        cout << "Choice: ";
//        cin >> choice;
//        switch (choice) {
//        case 1:
//            cout << "Enter value to insert: ";
//            cin >> value;
//            tree.insert(value);
//            break;
//        case 2:
//            cout << "Inorder traversal: ";
//            tree.inorder(tree.getRoot());
//            cout << endl;
//            break;
//        case 3:
//            cout << "Maximum Path Sum: " << tree.findMaxPathSum() << endl;
//            break;
//        case 4:
//            cout << "Exiting..." << endl;
//            return 0;
//        default:
//            cout << "Invalid choice! Please try again." << endl;
//        }
//    }
//}
