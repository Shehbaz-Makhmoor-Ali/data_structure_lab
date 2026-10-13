#include <iostream>
#include <string>
using namespace std;

struct Node {
    string patientID;
    Node* next;
    Node(string id) : patientID(id), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return "";
        }
        Node* temp = top;
        string poppedID = temp->patientID;
        top = top->next;
        delete temp;
        return poppedID;
    }

    string peek() {
        if (isEmpty()) {
            return "No requests pending";
        }
        return top->patientID;
    }

    void display() {
        if (isEmpty()) {
            cout << "Request stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Emergency Requests (Top to Bottom):" << endl;
        while (current != nullptr) {
            cout << " - " << current->patientID << endl;
            current = current->next;
        }
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    LinkedListStack emergencyStack;

    emergencyStack.push("P101");
    emergencyStack.push("P102");
    emergencyStack.push("P103");
    emergencyStack.push("P104");

    cout << "--- All Emergency Requests ---" << endl;
    emergencyStack.display();

    cout << "\nHandling latest emergency request..." << endl;
    cout << "Handled request: " << emergencyStack.pop() << endl;

    cout << "\nNew TOP Request: " << emergencyStack.peek() << endl;

    cout << "\n--- Remaining Emergency Requests ---" << endl;
    emergencyStack.display();

    return 0;
}