//#include "AVL7.h"
//
//
//void AvlTree::inorder(Node* root) {
//    if (root != nullptr) {
//        inorder(root->left);
//        cout << "Data: " << root->data << endl; 
//        inorder(root->right);
//    }
//}
//
//Node* AvlTree::insert(Node* root, int data) {
//    if (root == nullptr) {
//        return new Node(data);
//    }
//    else if (data > root->data) {
//        root->right = insert(root->right, data);
//    }
//    else if (data < root->data) {
//        root->left = insert(root->left, data);
//    }
//    else {
//        cout << "Cannot enter duplicates\n";
//        return root;
//    }
//
//    root->height = 1 + max(height(root->left), height(root->right));
//    return balance(root);
//}
//
//Node* AvlTree::deletenode(Node*& root, int data) {
//    if (root == nullptr) {
//        cout << "Not found\n";
//        return nullptr;
//    }
//    else if (data > root->data) {
//        root->right = deletenode(root->right, data);
//    }
//    else if (data < root->data) {
//        root->left = deletenode(root->left, data);
//    }
//    else {
//        if (root->left == nullptr) {
//            Node* temp = root;
//            root = root->right;
//            delete temp;
//        }
//        else if (root->right == nullptr) {
//            Node* temp = root;
//            root = root->left;
//            delete temp;
//        }
//        else {
//            Node* temp = findMaxFromLeft(root->left);
//            root->data = temp->data; 
//            root->left = deletenode(root->left, temp->data);
//        }
//    }
//
//    if (root == nullptr) return root;
//
//    root->height = 1 + max(height(root->left), height(root->right));
//    return balance(root);
//}
//
//Node* AvlTree::findMaxFromLeft(Node* node) {
//    while (node && node->right != nullptr)
//        node = node->right;
//    return node;
//}
//
//int AvlTree::height(Node* root) {
//    if (root == nullptr) {
//        return 0;
//    }
//    return root->height;
//}
//
//int AvlTree::getbalancefactor(Node* root) {
//    return height(root->left) - height(root->right);
//}
//
//Node* AvlTree::rightrotate(Node* x) {
//    Node* y = x->left;
//    Node* z = y->right;
//    y->right = x;
//    x->left = z;
//
//    x->height = 1 + max(height(x->left), height(x->right));
//    y->height = 1 + max(height(y->left), height(y->right));
//    return y;
//}
//
//Node* AvlTree::leftrotate(Node* x) {
//    Node* y = x->right;
//    Node* z = y->left;
//    y->left = x;
//    x->right = z;
//
//    x->height = 1 + max(height(x->left), height(x->right));
//    y->height = 1 + max(height(y->left), height(y->right));
//    return y;
//}
//
//Node* AvlTree::balance(Node* node) {
//    int balanceFactor = getbalancefactor(node);
//
//    // LL
//    if (balanceFactor > 1 && getbalancefactor(node->left) >= 0) {
//        return rightrotate(node);
//    }
//
//    // RR
//    if (balanceFactor < -1 && getbalancefactor(node->right) <= 0) {
//        return leftrotate(node);
//    }
//
//    // LR
//    if (balanceFactor > 1 && getbalancefactor(node->left) < 0) {
//        node->left = leftrotate(node->left);
//        return rightrotate(node);
//    }
//
//    // RL
//    if (balanceFactor < -1 && getbalancefactor(node->right) > 0) {
//        node->right = rightrotate(node->right);
//        return leftrotate(node);
//    }
//
//    return node;
//}
//
//bool AvlTree::isAVL(Node* node) {
//    if (node == nullptr) return true;
//
//    int balanceFactor = getbalancefactor(node);
//    return (balanceFactor >= -1 && balanceFactor <= 1) && isAVL(node->left) && isAVL(node->right);
//}
//void AvlTree::mergeTrees(Node*& root, Node* other) {
//    if (other == nullptr)return;
//    root = insert(root,other->data);
//    mergeTrees(root, other->left);
//    mergeTrees(root, other->right);
//
//}
