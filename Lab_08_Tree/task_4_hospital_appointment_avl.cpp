#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        token = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int token) {
    if (node == NULL) return new Node(token);

    if (token < node->token)
        node->left = insert(node->left, token);
    else if (token > node->token)
        node->right = insert(node->right, token);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    // LL Case
    if (balance > 1 && token < node->left->token)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && token > node->right->token)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && token > node->left->token) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && token < node->right->token) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->token << " (BF: " << getBalanceFactor(root) << ") ";
        inOrder(root->right);
    }
}

void printTree(Node* root, string indent, bool last) {
    if (root != NULL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "     ";
        } else {
            cout << "L----";
            indent += "|    ";
        }
        cout << root->token << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

int main() {
    Node* root = NULL;
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int token : tokens) {
        root = insert(root, token);
    }

    cout << "In-order Traversal (Token and Balance Factor):\n";
    inOrder(root);
    cout << "\n\n";

    cout << "Final Balanced AVL Tree Structure:\n";
    printTree(root, "", true);

    return 0;
}
