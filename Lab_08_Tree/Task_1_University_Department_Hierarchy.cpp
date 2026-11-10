#include <iostream>
#include <string>
using namespace std;

// Requirement 1: Create nodes using a class
class Node {
public:
    string name; // Requirement 2: Store the name of each department member
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(string memberName) {
        name = memberName;
        left = NULL;
        right = NULL;
    }
};

// Requirement 4: Display each member's name along with their left and right children
void displayHierarchy(Node* node) {
    if (node == NULL) {
        return;
    }

    cout << "Member: " << node->name << endl;
    
    if (node->left != NULL) {
        cout << " Left Child: " << node->left->name << endl;
    } else {
        cout << " Left Child: None" << endl;
    }

    if (node->right != NULL) {
        cout << " Right Child: " << node->right->name << endl;
    } else {
        cout << " Right Child: None" << endl;
    }
    cout << "---------------------------------------" << endl;

    displayHierarchy(node->left);
    displayHierarchy(node->right);
}

int main() {
    Node* hod = new Node("Dr. Smith (HOD)");
    
    Node* coordUG = new Node("Mr. Ali (UG Coordinator)");
    Node* coordPG = new Node("Dr. Sara (PG Coordinator)");
    
    Node* faculty1 = new Node("Ms. Ayesha (Lecturer)");
    Node* faculty2 = new Node("Mr. Bilal (Lecturer)");
    Node* faculty3 = new Node("Dr. Usman (Assistant Prof)");
    Node* faculty4 = new Node("Ms. Fatima (Lab Engineer)");
    hod->left = coordUG;
    hod->right = coordPG;

    coordUG->left = faculty1;
    coordUG->right = faculty2;

    coordPG->left = faculty3;
    coordPG->right = faculty4;

    // Display the tree
    cout << "University Department Hierarchy:\n";
    cout << "=======================================\n";
    displayHierarchy(hod);
    
    delete faculty4;
    delete faculty3;
    delete faculty2;
    delete faculty1;
    delete coordPG;
    delete coordUG;
    delete hod;

    return 0;
}
