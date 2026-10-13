#include <iostream>
using namespace std;
struct Node {
    int roll;
    Node* next;
};

void addStudent(Node*& head, int roll) {
    Node* newStudent = new Node();
    newStudent->roll = roll;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}

void display(Node* head) {
    cout << "Registered Students:\n";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->roll;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// 4. Search function
bool search(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == target) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = NULL; 
    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    // Display list
    display(head);

    // Search example
    int rollToFind = 108;
    cout << "\nSearching for " << rollToFind << "... ";
    if (search(head, rollToFind)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not Found!" << endl;
    }

    return 0;
}