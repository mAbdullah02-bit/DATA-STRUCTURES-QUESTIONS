//#include "BST+LL.h"
//#include <iostream>
//using namespace std;
//
//
//LinkedList::LinkedList() : head(nullptr) {}
//
//void LinkedList::insert(int data) {
//    Node* newNode = new Node(data);
//    if (!head) {
//        head = newNode;
//        head->next = head;
//        head->prev = head;
//    }
//    else {
//        Node* last = head->prev;
//        last->next = newNode;
//        newNode->prev = last;
//        newNode->next = head;
//        head->prev = newNode;
//    }
//}
//
//void LinkedList::deleteNode(int data) {
//    if (!head) return;
//    Node* current = head;
//    do {
//        if (current->data == data) {
//            if (current == head && current->next == head) {
//                head = nullptr;
//            }
//            else {
//                Node* prevNode = current->prev;
//                Node* nextNode = current->next;
//                prevNode->next = nextNode;
//                nextNode->prev = prevNode;
//                if (current == head) head = nextNode;
//            }
//            delete current;
//            return;
//        }
//        current = current->next;
//    } while (current != head);
//}
//
//void LinkedList::display() const {
//    if (!head) return;
//    Node* current = head;
//    do {
//        cout << current->data << " ";
//        current = current->next;
//    } while (current != head);
//    cout << endl;
//}
//
//bool LinkedList::search(int data) const {
//    if (!head) return false;
//    Node* current = head;
//    do {
//        if (current->data == data) return true;
//        current = current->next;
//    } while (current != head);
//    return false;
//}
//
//
//BST::BST() : root(nullptr) {}
//
//void BST::insert(int data) {
//    TreeNode* newNode = new TreeNode(data);
//    if (!root) {
//        root = newNode;
//        return;
//    }
//    TreeNode* current = root;
//    TreeNode* parent = nullptr;
//    while (current) {
//        parent = current;
//        if (data < current->data) current = current->left;
//        else if (data > current->data) current = current->right;
//        else return; 
//    }
//    if (data < parent->data) parent->left = newNode;
//    else parent->right = newNode;
//}
//
//TreeNode* deleteRec(TreeNode* root, int data) {
//    if (!root) return root;
//    if (data < root->data) root->left = deleteRec(root->left, data);
//    else if (data > root->data) root->right = deleteRec(root->right, data);
//    else {
//        if (!root->left) {
//            TreeNode* temp = root->right;
//            delete root;
//            return temp;
//        }
//        else if (!root->right) {
//            TreeNode* temp = root->left;
//            delete root;
//            return temp;
//        }
//        TreeNode* temp = root->right;
//        while (temp && temp->left) temp = temp->left;
//        root->data = temp->data;
//        root->right = deleteRec(root->right, temp->data);
//    }
//    return root;
//}
//
//void BST::deleteNode(int data) {
//    root = deleteRec(root, data);
//}
//
//bool BST::search(int data) const {
//    TreeNode* current = root;
//    while (current) {
//        if (data == current->data) return true;
//        if (data < current->data) current = current->left;
//        else current = current->right;
//    }
//    return false;
//}
//
//void inorderTraversal(TreeNode* node) {
//    if (!node) return;
//    inorderTraversal(node->left);
//    cout << node->data << " ";
//    inorderTraversal(node->right);
//}
//void BST::TreetoLL(TreeNode* root,LinkedList& l) {
//
//    if (root!=nullptr)
//    {
//      
//       TreetoLL(root->left,l);
//       l.insert(root->data);
//       TreetoLL(root->right,l);
//
//    }
//    
//}
//
//void BST::inorder() const {
//    inorderTraversal(root);
//    cout << endl;
//}
