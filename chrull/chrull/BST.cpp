#include<iostream>
#include<string>

using namespace std;

class BST_Node {
public:
    string name;
    string city;
    BST_Node* left;
    BST_Node* right;

    BST_Node(string n, string c) {
        name = n;
        city = c;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    BST_Node* root;
    BST() {
        root = nullptr;
    }
    bool isEmpty() {
        return (root == nullptr);

    }

    void insertNode(string n, string c) {
        BST_Node* temp = new BST_Node(n, c);
        if (isEmpty()) {
            root = temp;
        }
        else {
            BST_Node* curr = root;
            while (curr != nullptr) {
                if (n < curr->name) {
                    if (curr->left) {
                        curr = curr->left;
                    }
                    else {
                        curr->left = temp;
                        return;
                    }
                }
                else if (n > curr->name) {
                    if (curr->right) {
                        curr = curr->right;
                    }
                    else {
                        curr->right = temp;
                        return;
                    }
                }
                else {
                    return;
                }
            }
        }
    }
    BST_Node* search(string n, BST_Node* ptr) {
        if (ptr == nullptr) {
            return nullptr;
        }
        if (n == ptr->name) {
            return ptr;
        }
        if (n < ptr->name) {
            return search(n, ptr->left);
        }
        if (n > ptr->name) {
            return search(n, ptr->right);
        }
    }


    void displayBSTUsers(BST_Node* p) {
        if (p != nullptr) {
            displayBSTUsers(p->left);
            cout << "\033[36m\t\t\t\t\t\t\t  Name: " << p->name << "\n\t\t\t\t\t\t\t  City: " << p->city << endl;
            displayBSTUsers(p->right);
        }
    }
};
