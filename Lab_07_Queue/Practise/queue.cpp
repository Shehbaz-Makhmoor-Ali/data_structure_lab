#include <iostream>
using namespace std;

#define SIZE 5

class Queue{
    int arr[SIZE];
    int front, rear;

    public:
    Queue(){
        front = 0;
        rear = -1;
    }

    void enqueue(int value){
        if (rear == SIZE -10) {
            cout << "Queue is Full (Overflow)!\n";
            return;
        }
        rear++;
        arr[rear] = value;
        cout << "Added to Queue: " << value << endl;
    }

    void dequeue(){
        if (front == 0) {
            cout << "Queue is Empty (Underflow)!\n";
            return;
        }
        cout << "Removed from Queue: " << arr[front] << endl;
        front++;
    }

    void display(){
        if (front == 0) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}