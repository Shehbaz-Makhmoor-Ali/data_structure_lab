#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int packetID) {
        if ((rear + 1) % SIZE == front) {
            cout << "Buffer Full (Overflow)!\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = packetID;
        cout << "Packet " << packetID << " inserted.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Buffer Empty (Underflow)!\n";
            return;
        }
        cout << "Transmitted Packet: " << items[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No packets in buffer.\n";
            return;
        }
        cout << "Packets waiting: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue network;

    network.enqueue(201);
    network.enqueue(202);
    network.enqueue(203);

    network.display();

    network.dequeue();
    network.display();

    // Reusing the position
    network.enqueue(204);
    network.display();

    return 0;
}