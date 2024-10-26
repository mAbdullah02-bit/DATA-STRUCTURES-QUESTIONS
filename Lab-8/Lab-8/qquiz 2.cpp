//#include <iostream>
//using namespace std;
//
//class Node
//{
//public:
//    int number;
//    Node* left;
//    Node* right;
//
//    Node(int val)
//    {
//        number = val;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//class BST
//{
//public:
//    Node* root;
//
//    BST()
//    {
//        root = nullptr;
//    }
//
//    void insert(int val)
//    {
//        Node* newNode = new Node(val);
//        if (root == nullptr)
//        {
//            root = newNode;
//            return;
//        }
//        Node* temp = root;
//        while (true)
//        {
//            if (val > temp->number)
//            {
//                if (temp->right == nullptr)
//                {
//                    temp->right = newNode;
//                    return;
//                }
//                temp = temp->right;
//            }
//            else if (val < temp->number)
//            {
//                if (temp->left == nullptr)
//                {
//                    temp->left = newNode;
//                    return;
//                }
//                temp = temp->left;
//            }
//            else
//            {
//                cout << "Duplicates are not allowed...\n";
//                delete newNode;
//                return;
//            }
//        }
//    }
//
//    int findMinLeft(Node*& ptr)
//    {
//        if (ptr->left == nullptr)
//        {
//            int val = ptr->number;
//            Node* temp = ptr;
//            ptr = ptr->right;
//            delete temp;
//            return val;
//        }
//        return findMinLeft(ptr->left);
//    }
//
//    void deleteNode(Node*& ptr, int val)
//    {
//        if (ptr == nullptr)
//        {
//            return;
//        }
//        if (ptr->number > val)
//        {
//            deleteNode(ptr->left, val);
//        }
//        else if (ptr->number < val)
//        {
//            deleteNode(ptr->right, val);
//        }
//        else
//        {
//            if (ptr->left == nullptr && ptr->right == nullptr)
//            {
//                delete ptr;
//                ptr = nullptr;
//                return;
//            }
//            if (ptr->left == nullptr)
//            {
//                Node* temp = ptr;
//                ptr = ptr->right;
//                delete temp;
//                return;
//            }
//            if (ptr->right == nullptr)
//            {
//                Node* temp = ptr;
//                ptr = ptr->left;
//                delete temp;
//                return;
//            }
//            int number = findMinLeft(ptr->right);
//            ptr->number = number;
//        }
//    }
//
//    int countLeaves(Node* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            return 1;
//        }
//        return countLeaves(node->left) + countLeaves(node->right);
//    }
//
//    bool search(Node* node, int number)
//    {
//        if (node == nullptr)
//        {
//            return false;
//        }
//        if (number == node->number)
//        {
//            return true;
//        }
//        if (number < node->number)
//        {
//            return search(node->left, number);
//        }
//        return search(node->right, number);
//    }
//
//    void preOrder(Node* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        cout << node->number << " ";
//        preOrder(node->left);
//        preOrder(node->right);
//    }
//
//    void inOrder(Node* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        inOrder(node->left);
//        cout << node->number << " ";
//        inOrder(node->right);
//    }
//
//    void postOrder(Node* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        postOrder(node->left);
//        postOrder(node->right);
//        cout << node->number << " ";
//    }
//
//    int length(Node* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        return 1 + length(node->left) + length(node->right);
//    }
//
//    int depth(Node* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        int leftDepth = depth(node->left);
//        int rightDepth = depth(node->right);
//        return 1 + max(leftDepth, rightDepth);
//    }
//
//    void displaySubtree(int val)
//    {
//        Node* current = root;
//        while (current != nullptr)
//        {
//            if (val == current->number)
//            {
//                cout << "Subtree rooted at " << val << ":\n";
//                inOrder(current);
//                cout << endl;
//                return;
//            }
//            if (val < current->number)
//            {
//                current = current->left;
//            }
//            else
//            {
//                current = current->right;
//            }
//        }
//        cout << "Value not found in the tree.\n";
//    }
//};
//
//int main()
//{
//    BST tree;
//    int choice;
//    int number;
//
//    while (true)
//    {
//        cout << "\n1.Insert\n2.Delete\n3.Search\n4.InOrder Traversal\n5.Count Leaves\n6.PostOrder Traversal\n7.PreOrder Traversal\n8.Length\n9.Depth\n10.Display Subtree\n11.Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//        {
//            cout << "Enter number: ";
//            cin >> number;
//            tree.insert(number);
//            break;
//        }
//        case 2:
//        {
//            cout << "Enter number to delete: ";
//            cin >> number;
//            tree.deleteNode(tree.root, number);
//            break;
//        }
//        case 3:
//        {
//            cout << "Enter number to search: ";
//            cin >> number;
//            if (tree.search(tree.root, number))
//            {
//                cout << "number found.\n";
//            }
//            else
//            {
//                cout << "number not found.\n";
//            }
//            break;
//        }
//        case 4:
//        {
//            cout << "in order traversal: ";
//            tree.inOrder(tree.root);
//            cout << endl;
//            break;
//        }
//        case 5:
//        {
//            cout << "number of leaves: " << tree.countLeaves(tree.root) << endl;
//            break;
//        }
//        case 6:
//        {
//            cout << "post order traversal: ";
//            tree.postOrder(tree.root);
//            cout << endl;
//            break;
//        }
//        case 7:
//        {
//            cout << "pre order traversal : ";
//            tree.preOrder(tree.root);
//            cout << endl;
//            break;
//        }
//        case 8:
//        {
//            cout << "Length of the tree: " << tree.length(tree.root) << endl;
//            break;
//        }
//        case 9:
//        {
//            cout << "depth of the tree: " << tree.depth(tree.root) << endl;
//            break;
//        }
//        case 10:
//        {
//            cout << "Enter number to display subtree: ";
//            cin >> number;
//            tree.displaySubtree(number);
//            break;
//        }
//        case 11:
//        {
//            exit(0);
//        }
//        default:
//        {
//            cout << "Invalid choice! Please try again.\n";
//        }
//        }
//    }
//    return 0;
//}
