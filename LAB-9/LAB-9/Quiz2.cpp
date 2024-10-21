#include<iostream>
using namespace std;

class Node {
public:
    Node* right, * left;
    int data;
    Node(int d) { right = left = nullptr; data = d; }
};

class BST {
    Node* root;
public:
    Node* getroot() { return root; }
    BST() { root = nullptr; }

    void insert(int num) {
        Node* ptr = new Node(num);

        if (root == nullptr) {
            root = ptr;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (num > current->data) {
                current = current->right;
            }
            else if (num < current->data) {
                current = current->left;
            }
            else {
                cout << "Cannot insert duplicates\n";
                return;
            }
        }

        if (num > parent->data)
            parent->right = ptr;
        else
            parent->left = ptr;
    }

    void search(int num) {
        search(root, num);
    }

    void search(Node* root, int num) {
        if (root == nullptr) {
            cout << "NOT FOUND\n";
            return;
        }

        if (num > root->data)
            search(root->right, num);
        else if (num < root->data)
            search(root->left, num);
        else {
            cout << "Found with value: " << num << endl;
            return;
        }
    }

    Node* search2(Node* root, int num) {
        if (root == nullptr) {
            cout << "NOT FOUND\n";
            return nullptr;
        }

        if (num > root->data)
            return search2(root->right, num); 
        else if (num < root->data)
            return search2(root->left, num); 
        else {
            cout << "Found with value: " << num << endl;
            return root;
        }
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    int countleaves(Node* root, int& count) {
        if (root != nullptr) {
            countleaves(root->left, count);
            if (root->left == nullptr && root->right == nullptr) {
                count++;
            }
            countleaves(root->right, count);
        }
        return count;
    }

    int getlength(Node* root, int& count) {
        if (root != nullptr) {
            getlength(root->left, count);
            count++;
            getlength(root->right, count);
        }
        return count;
    }

    void deletenode(int data) {
        deletenode(root, data);
    }

    void deletenode(Node*& root, int data) {
        if (root == nullptr) {
            cout << "Not found\n";
            return;
        }
        else if (data > root->data)
            deletenode(root->right, data);
        else if (data < root->data)
            deletenode(root->left, data);
        else {
            if (root->left == nullptr) {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                Node* temp = findMaxFromLeft(root->left);
                root->data = temp->data;
                deletenode(root->left, temp->data);
            }
        }
    }

    void searchsubtree(int data) {
        Node* curr = search2(root, data);
        if (curr != nullptr) {
            cout << "Subtree of node with value " << data << ": ";
            inorder(curr);
            cout << endl; 
        }
        else {
            cout << "Subtree not found for value: " << data << endl;
        }
    }

    Node* findMaxFromLeft(Node* node) {
        while (node && node->right != nullptr)
            node = node->right;
        return node;
    }

    int depth(Node* P)
    {
        if (P == NULL)
            return 0;

        int left = depth(P->left);
        int right = depth(P->right);

        if (left > right)
        {
            int h = 1 + left;
        return h;
        }
        else
        {
            int h = 1 + right;
        return h;
        }

    }

};

int main() {
    BST tree;
    int num;

    for (int i = 0; i < 10; i++) {
        cout << "ENTER : ";
        cin >> num;
        tree.insert(num);
    }

    cout << "\nInorder: ";
    tree.inorder(tree.getroot());

    cout << "\nPreorder: ";
    tree.preorder(tree.getroot());

    cout << "\nPostorder: ";
    tree.postorder(tree.getroot());

    int count = 0;
    cout << "\nTotal leaf nodes: " << tree.countleaves(tree.getroot(), count) << endl;

    count = 0;
    cout << "The Length of tree: " << tree.getlength(tree.getroot(), count) << endl;

    cout << "DEPTH OF TREE: " << tree.depth(tree.getroot()) << endl;

    cout << "Searching for 7 : ";
    cin >> count;
    tree.search(count);
    cin >> count;
    cout << "Searching for 7 and printing its subtree : ";
    tree.searchsubtree(count);

    cout << "Deleting node with value :\n";
    cin >> count;
    tree.deletenode(count);
    cout << "After deletion (Inorder): ";
    tree.inorder(tree.getroot());

    return 0;
}
