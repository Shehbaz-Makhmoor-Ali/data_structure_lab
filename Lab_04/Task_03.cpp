#include <iostream>
#include <string>
using namespace std;
struct Node {
    string productID;
    Node* next;

    Node(string id) {
        productID = id;
        next = NULL;
    }
};

class ShoppingCart {
private:
    Node* head = NULL;

public:
    void addProduct(string id) {
        Node* newNode = new Node(id);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeProduct(string id) {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }

        if (head->productID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Remove Product: " << id << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->productID != id) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Product " << id << " not found in the cart." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Remove Product: " << id << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "Shopping Cart: [Empty]" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->productID;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.addProduct("P101");
    cart.addProduct("P205");
    cart.addProduct("P310");
    cart.addProduct("P415");
    cout << "Shopping Cart:" << endl;
    cart.display();
    cout << endl;
    cart.removeProduct("P310");
    cout << "Updated Cart:" << endl;
    cart.display();
    return 0;
}