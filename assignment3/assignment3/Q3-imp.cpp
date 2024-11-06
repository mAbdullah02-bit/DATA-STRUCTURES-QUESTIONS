#include "headers.h"

node::node(int data, node* left, node* right) : data(data), left(left), right(right) {}

BST::BST() : root(NULL) {}

node* BST::getRoot() {
    return root;
}

node* BST::insertion(node* root, int n) {
    node* temp = new node(n);
    if (!root) {
        root = temp;
    }
    else {
        node* current = root;
        node* parent = NULL;
        while (current != NULL) {
            parent = current;
            if (n < current->data) {
                current = current->left;
            }
            else if (n > current->data) {
                current = current->right;
            }
            else {
                cout << "Duplicate found!" << endl;
                delete temp;
                return root;
            }
        }
        if (n < parent->data) {
            parent->left = temp;
        }
        else {
            parent->right = temp;
        }
    }
    return root;
}

void BST::insert(int n) {
    root = insertion(root, n);
}

int BST::findMaxPathSum() {
    int sum = INT_MIN;
    maxPathSum(root, sum);
    return sum;
}

int BST::maxPathSum(node* root, int& sum) {
    if (!root) {
        return 0;
    }
    int left = maxPathSum(root->left, sum);
    int right = maxPathSum(root->right, sum);
    if (left < 0) left = 0;
    if (right < 0) right = 0;
    int maxSingle = root->data + max(left, right);
    int maxTop = root->data + left + right;

    if (maxTop > sum) sum = maxTop;

    return maxSingle;
}

void BST::inorder(node* n) const {
    if (n != NULL) {
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}
