#include <iostream>
using namespace std;

#define SIZE 5

class SimpleQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue is Full (Overflow)!\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        items[rear] = token;
        cout << "Customer " << token << " added to line.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty (Underflow)!\n";
            return;
        }
        cout << "Serving Customer: " << items[front] << endl;
        front++;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "No waiting customers.\n";
            return;
        }
        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    void count() {
        if (front == -1 || front > rear) {
            cout << "Total waiting customers: 0\n";
        } else {
            cout << "Total waiting customers: " << (rear - front + 1) << endl;
        }
    }
};

int main() {
    SimpleQueue bank;

    bank.enqueue(101);
    bank.enqueue(102);
    bank.enqueue(103);

    bank.display();
    bank.count();

    bank.dequeue();

    bank.display();
    bank.count();

    return 0;
}