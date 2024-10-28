#include "AVLq8.h"



LNode::LNode(int value, string n) : data(value), name(n), next(nullptr) {}

LList::LList() : head(nullptr) {}

void LList::insertAtEnd(int value, string name) {
    LNode* newNode = new LNode(value, name);
    if (!head) {
        head = newNode;
        return;
    }
    LNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void LList::display() const {
    LNode* temp = head;
    while (temp) {
        cout << " ->" << temp->name << "->" << temp->data << " ";
        temp = temp->next;
    }
}

Node::Node(int f, string n) : freq(f), name(n), height(1), left(nullptr), right(nullptr) {}


AVL::AVL() : root(nullptr) {}

int AVL::height(Node* node) {
    return node == nullptr ? 0 : node->height;
}

int AVL::max(int a, int b) {
    return (a > b) ? a : b;
}

Node* AVL::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* AVL::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

int AVL::getBalanceFactor(Node* node) {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

Node* AVL::insert(Node* node, int freq, string name) {
    if (node == nullptr)
        return new Node(freq, name);

    if (freq < node->freq)
        node->left = insert(node->left, freq, name);
    else if (freq > node->freq)
        node->right = insert(node->right, freq, name);
    else {
        node->next.insertAtEnd(freq, name);
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalanceFactor(node);

    if (balance > 1 && freq < node->left->freq)
        return rightRotate(node);

    if (balance < -1 && freq > node->right->freq)
        return leftRotate(node);

    if (balance > 1 && freq > node->left->freq) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && freq < node->right->freq) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* AVL::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* AVL::deleteNode(Node* root, int freq) {
    if (root == nullptr)
        return root;

    if (freq < root->freq)
        root->left = deleteNode(root->left, freq);
    else if (freq > root->freq)
        root->right = deleteNode(root->right, freq);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);
            root->freq = temp->freq;
            root->name = temp->name;
            root->next = temp->next;
            root->right = deleteNode(root->right, temp->freq);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void AVL::playSong(Node* node, int freq, string name) {
    if (node == nullptr)
        return;

    if (freq < node->freq)
        playSong(node->left, freq, name);
    else if (freq > node->freq)
        playSong(node->right, freq, name);
    else {
        if (node->name == name) {
            node->freq++;
            root = deleteNode(root, freq);
            root = insert(root, node->freq, name);
        }
    }
}

void AVL::inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->name << " " << node->freq << " ";
        if (node->next.head != nullptr) node->next.display();
        cout << endl;
        inorder(node->right);
    }
}

void AVL::insert(int freq, string name) {
    root = insert(root, freq, name);
}

void AVL::playSong(int freq, string name) {
    playSong(root, freq, name);
}

void AVL::display() {
    inorder(root);
}
