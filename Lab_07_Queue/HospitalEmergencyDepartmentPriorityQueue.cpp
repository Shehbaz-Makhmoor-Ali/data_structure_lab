#include <iostream>
using namespace std;

#define SIZE 5

struct Patient {
    int id;
    int priority; // Lower number = higher urgency (1 is highest)
};

class PriorityQueue {
private:
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void enqueue(int id, int priority) {
        if (count == SIZE) {
            cout << "Emergency Queue Full!\n";
            return;
        }
        patients[count].id = id;
        patients[count].priority = priority;
        count++;
        cout << "Patient P" << id << " with priority " << priority << " added.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        // Find highest priority patient (lowest priority number)
        int highestPriorityIndex = 0;
        for (int i = 1; i < count; i++) {
            if (patients[i].priority < patients[highestPriorityIndex].priority) {
                highestPriorityIndex = i;
            }
        }

        cout << "Treating Patient: P" << patients[highestPriorityIndex].id 
             << " (Priority " << patients[highestPriorityIndex].priority << ")\n";

        // Shift remaining patients to fill gap
        for (int i = highestPriorityIndex; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Waiting Patients:\n";
        for (int i = 0; i < count; i++) {
            cout << "Patient P" << patients[i].id << " - Priority: " << patients[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue hospital;

    hospital.enqueue(101, 3); // Normal
    hospital.enqueue(102, 1); // Urgent
    hospital.enqueue(103, 2); // Moderate

    hospital.display();

    hospital.dequeue(); // Treats P102 first
    hospital.display();

    return 0;
}