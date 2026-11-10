#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
private:
    int items[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    void insertFront(int val) {
        if (count == SIZE) {
            cout << "Deque Full!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        items[front] = val;
        count++;
    }

    void insertRear(int val) {
        if (count == SIZE) {
            cout << "Deque Full!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        items[rear] = val;
        count++;
    }

    void deleteFront() {
        if (count == 0) {
            cout << "Deque Empty!\n";
            return;
        }
        cout << "Removed from Front: " << items[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void deleteRear() {
        if (count == 0) {
            cout << "Deque Empty!\n";
            return;
        }
        cout << "Removed from Rear: " << items[rear] << endl;
        rear = (rear - 1 + SIZE) % SIZE;
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Deque Empty!\n";
            return;
        }
        cout << "Front -> ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << items[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << "<- Rear\n";
    }
};

int main() {
    Deque dq;

    dq.insertRear(301);
    dq.insertRear(302);
    dq.insertFront(300);

    dq.display(); // Front -> 300 301 302 <- Rear

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    return 0;
}