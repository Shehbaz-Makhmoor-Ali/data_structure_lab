#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string val) {
        category = val;
        left = nullptr;
        right = nullptr;
    }
};

void bfsTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->category << endl;

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

int main() {
    Node* root = new Node("Categories");
    
    root->left = new Node("Electronics");
    root->right = new Node("Clothing");
    
    root->left->left = new Node("Mobiles");
    root->left->right = new Node("Laptops");
    
    root->right->left = new Node("Men");
    root->right->right = new Node("Women");
    
    root->right->left->left = new Node("Accessories");

    bfsTraversal(root);

    return 0;
}
