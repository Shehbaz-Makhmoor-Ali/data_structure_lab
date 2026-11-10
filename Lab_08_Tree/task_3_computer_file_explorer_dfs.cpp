#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string folderName;
    Node* left;
    Node* right;

    Node(string name) {
        folderName = name;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->folderName << " -> ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->folderName << " -> ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->folderName << " -> ";
}

int main() {
    Node* root = new Node("C: (Root)");
    
    root->left = new Node("Program Files");
    root->right = new Node("Users");
    
    root->left->left = new Node("Java");
    root->left->right = new Node("Microsoft");
    
    root->right->left = new Node("Public");
    root->right->right = new Node("Admin");

    cout << "Pre-order Traversal (Root, Left, Right):\n";
    preOrder(root);
    cout << "End\n\n";

    cout << "In-order Traversal (Left, Root, Right):\n";
    inOrder(root);
    cout << "End\n\n";

    cout << "Post-order Traversal (Left, Right, Root):\n";
    postOrder(root);
    cout << "End\n";

    return 0;
}
