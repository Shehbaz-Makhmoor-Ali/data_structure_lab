#include <iostream>
#include <string>
using namespace std;

class StaffNode {
public:
    string name;
    StaffNode* left;
    StaffNode* right;

    StaffNode(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void showStaff(StaffNode* node) {
    if (node == NULL) return;
    cout << node->name << " -> Left: " << (node->left ? node->left->name : "NULL")
         << ", Right: " << (node->right ? node->right->name : "NULL") << endl;
    showStaff(node->left);
    showStaff(node->right);
}

void showStaffInOrder(StaffNode* node) {
    if (node == NULL) return;
    showStaffInOrder(node->left);
    cout << node->name << " | ";
    showStaffInOrder(node->right);
}

void deleteStaff(StaffNode* node) {
    if (node == NULL) return;
    deleteStaff(node->left);
    deleteStaff(node->right);
    delete node;
}

class BSTNode {
public:
    int id;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        id = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    BSTNode* root;

    BSTNode* insertHelper(BSTNode* node, int id, bool& added) {
        if (node == NULL) {
            added = true;
            return new BSTNode(id);
        }
        if (id < node->id)
            node->left = insertHelper(node->left, id, added);
        else if (id > node->id)
            node->right = insertHelper(node->right, id, added);
        return node;
    }

    BSTNode* smallest(BSTNode* node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    BSTNode* removeHelper(BSTNode* node, int id, bool& removed) {
        if (node == NULL) return NULL;
        if (id < node->id) {
            node->left = removeHelper(node->left, id, removed);
        } else if (id > node->id) {
            node->right = removeHelper(node->right, id, removed);
        } else {
            removed = true;
            if (node->left == NULL) {
                BSTNode* child = node->right;
                delete node;
                return child;
            }
            if (node->right == NULL) {
                BSTNode* child = node->left;
                delete node;
                return child;
            }
            BSTNode* next = smallest(node->right);
            node->id = next->id;
            bool temp = false;
            node->right = removeHelper(node->right, next->id, temp);
        }
        return node;
    }

    void inOrderHelper(BSTNode* node) {
        if (node == NULL) return;
        inOrderHelper(node->left);
        cout << node->id << " ";
        inOrderHelper(node->right);
    }

    void destroy(BSTNode* node) {
        if (node == NULL) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    bool insert(int id) {
        bool added = false;
        root = insertHelper(root, id, added);
        return added;
    }

    bool search(int id, int& visits) {
        visits = 0;
        BSTNode* current = root;
        while (current != NULL) {
            visits++;
            if (id == current->id) return true;
            if (id < current->id) current = current->left;
            else current = current->right;
        }
        return false;
    }

    bool remove(int id) {
        bool removed = false;
        root = removeHelper(root, id, removed);
        return removed;
    }

    void display() {
        inOrderHelper(root);
        cout << endl;
    }
};

void fillOriginal(BST& tree) {
    int ids[] = {48, 28, 68, 18, 38, 58, 78};
    int size = sizeof(ids) / sizeof(ids[0]);
    for (int i = 0; i < size; i++) {
        tree.insert(ids[i]);
    }
}

void searchAndShow(BST& tree, int id) {
    int visits;
    bool found = tree.search(id, visits);
    cout << "Search " << id << ": " << (found ? "Found" : "Not found")
         << ", node visits = " << visits << endl;
}

void testDeletion(string title, int firstRemove, int target) {
    BST tree;
    fillOriginal(tree);
    if (firstRemove != -1) tree.remove(firstRemove);
    cout << title << endl;
    cout << "Before: ";
    tree.display();
    tree.remove(target);
    cout << "After deleting " << target << ": ";
    tree.display();
    cout << endl;
}

int main() {
    cout << "--- General Binary Tree ---" << endl;
    StaffNode* root = new StaffNode("Vice Chancellor");
    root->left = new StaffNode("Dean");
    root->right = new StaffNode("Registrar");
    root->left->left = new StaffNode("HOD Computer Science");
    root->left->right = new StaffNode("HOD Mathematics");
    root->right->left = new StaffNode("Accountant");
    root->right->right = new StaffNode("Librarian");

    showStaff(root);
    cout << "In-order of general tree: ";
    showStaffInOrder(root);
    cout << endl << endl;

    cout << "--- BST of Staff IDs ---" << endl;
    BST tree;
    fillOriginal(tree);
    cout << "Initial IDs: ";
    tree.display();

    int count = 0;
    while (count < 3) {
        int id;
        cout << "Enter a staff ID to insert: ";
        cin >> id;
        if (tree.insert(id)) {
            cout << id << " inserted." << endl;
            count++;
        } else {
            cout << id << " already exists. Duplicate rejected." << endl;
        }
    }
    cout << "IDs now: ";
    tree.display();
    cout << endl;

    cout << "--- Search Tests ---" << endl;
    searchAndShow(tree, 58);
    searchAndShow(tree, 60);
    searchAndShow(tree, 5);
    cout << endl;

    cout << "--- Deletion Tests (fresh BST each time) ---" << endl;
    testDeletion("Leaf node (18):", -1, 18);
    testDeletion("Node with one child (28 after removing 18):", 18, 28);
    testDeletion("Node with two children (48):", -1, 48);

    int id;
    cout << "Enter a staff ID to delete: ";
    cin >> id;
    if (tree.remove(id)) cout << id << " deleted." << endl;
    else cout << id << " not found." << endl;
    cout << "Remaining IDs in ascending order: ";
    tree.display();
    cout << endl;

    cout << "--- Why In-order Differs ---" << endl;
    cout << "In a general binary tree, nodes are linked in any order, so in-order traversal" << endl;
    cout << "follows the tree shape and the output is not necessarily sorted." << endl;
    cout << "In a BST, every left value is smaller and every right value is larger," << endl;
    cout << "so in-order (left, node, right) always gives ascending order." << endl;

    deleteStaff(root);
    return 0;
}
