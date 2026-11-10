#include <iostream>
#include <string>
using namespace std;

class UndoStack {
private:
    static const int MAX_SIZE = 10;
    string arr[MAX_SIZE];
    int topIndex;

public:
    UndoStack() {
        topIndex = -1;
    }

    bool isFull() {
        return topIndex == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(string action) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = action;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return "";
        }
        return arr[topIndex--];
    }

    string peek() {
        if (isEmpty()) {
            return "No actions performed";
        }
        return arr[topIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "No actions stored." << endl;
            return;
        }
        cout << "Action History (Top to Bottom):" << endl;
        for (int i = topIndex; i >= 0; i--) {
            cout << " - " << arr[i] << endl;
        }
    }
};

int main() {
    UndoStack editorHistory;

    // 1. Push actions
    editorHistory.push("Type \"Hello\"");
    editorHistory.push("Type \"World\"");
    editorHistory.push("Add \"!\"");
    editorHistory.push("Delete \"!\"");

    // 2. Display all actions from TOP to bottom
    cout << "--- All Performed Actions ---" << endl;
    editorHistory.display();

    // 3. Perform two POP operations to simulate Undo
    cout << "\nSimulating two Undo operations..." << endl;
    cout << "Undone: " << editorHistory.pop() << endl;
    cout << "Undone: " << editorHistory.pop() << endl;

    // 4. Display current TOP action
    cout << "\nCurrent TOP Action: " << editorHistory.peek() << endl;

    // 5. Display remaining actions
    cout << "\n--- Remaining Action Stack ---" << endl;
    editorHistory.display();

    return 0;
}