#include <iostream>
#include <string>
using namespace std;

struct Node {
    string orderID;
    Node* next;
    Node(string id) : orderID(id), next(nullptr) {}
};

class OrderStack {
private:
    Node* top;

public:
    OrderStack() {
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
            cout << "Stack Underflow! No orders to process." << endl;
            return "";
        }
        Node* temp = top;
        string poppedID = temp->orderID;
        top = top->next;
        delete temp;
        return poppedID;
    }

    string peek() {
        if (isEmpty()) {
            return "No pending orders";
        }
        return top->orderID;
    }

    void display() {
        if (isEmpty()) {
            cout << "Order stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Orders (Top to Bottom):" << endl;
        while (current != nullptr) {
            cout << " - " << current->orderID << endl;
            current = current->next;
        }
    }

    ~OrderStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    OrderStack restaurantStack;

    restaurantStack.push("ORD-101");
    restaurantStack.push("ORD-102");
    restaurantStack.push("ORD-103");
    restaurantStack.push("ORD-104");

    cout << "--- All Pending Orders ---" << endl;
    restaurantStack.display();

    cout << "\nProcessing two orders..." << endl;
    cout << "Processed Order: " << restaurantStack.pop() << endl;
    cout << "Processed Order: " << restaurantStack.pop() << endl;

    cout << "\nCurrent TOP Order: " << restaurantStack.peek() << endl;

    cout << "\n--- Remaining Orders ---" << endl;
    restaurantStack.display();

    cout << "\nIs the Stack empty? " << (restaurantStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}