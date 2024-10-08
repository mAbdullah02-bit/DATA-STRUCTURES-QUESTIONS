//#include <iostream>
//#include <string>
//using namespace std;
//
//
//struct TreeNode {
//    string data;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(string val) : data(val), left(nullptr), right(nullptr) {}
//};
//
//void preOrder(TreeNode* root) {
//    if (!root)
//        return;
//    cout << root->data << " ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//
//void postOrder(TreeNode* root) {
//    if (!root)
//        return;
//    postOrder(root->left);
//    postOrder(root->right);
//    cout << root->data << " ";
//}
//
//void inOrder(TreeNode* root) {
//    if (!root)
//        return;
//    inOrder(root->left);
//    cout << root->data << " ";
//    inOrder(root->right);
//}
//
//TreeNode* createTree() {
//    TreeNode* root = new TreeNode("D");
//
//    root->left = new TreeNode("Data Structures");
//    root->right = new TreeNode("Data Structures Lab");
//
//    root->left->left = new TreeNode("Labs");
//    root->left->right = new TreeNode("Assignments");
//
//    root->left->left->left = new TreeNode("Lab 1");
//    root->left->left->right = new TreeNode("Lab 2");
//
//    root->right->left = new TreeNode("Assignment 1");
//    root->right->right = new TreeNode("Assignment 2");
//
//    return root;
//}
//
//int main() {
//
//    TreeNode* root = createTree();
//
//    cout << "Pre-order Traversal: ";
//    preOrder(root);
//    cout << endl;
//
//    cout << "Post-order Traversal: ";
//    postOrder(root);
//    cout << endl;
//
//    cout << "In-order Traversal: ";
//    inOrder(root);
//    cout << endl;
//
//    return 0;
//}
