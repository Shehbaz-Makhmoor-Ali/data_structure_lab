#include <iostream>
#include <string>
using namespace std;

class BrowserStack {
private:
    static const int MAX_SIZE = 10;
    string arr[MAX_SIZE];
    int topIndex;

public:
    BrowserStack() {
        topIndex = -1;
    }

    bool isFull() {
        return topIndex == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(string page) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot add page: " << page << endl;
            return;
        }
        arr[++topIndex] = page;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No pages to remove." << endl;
            return "";
        }
        return arr[topIndex--];
    }

    string peek() {
        if (isEmpty()) {
            return "No page available";
        }
        return arr[topIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "History is empty." << endl;
            return;
        }
        cout << "Current Stack (Top to Bottom):" << endl;
        for (int i = topIndex; i >= 0; i--) {
            cout << " - " << arr[i] << endl;
        }
    }
};

int main() {
    BrowserStack history;

    // 1. Push visited pages
    history.push("Google");
    history.push("YouTube");
    history.push("Facebook");
    history.push("GitHub");

    // 2. Display all pages
    cout << "--- Initial Browsing History ---" << endl;
    history.display();

    // 3. Perform one POP (Back button)
    cout << "\nSimulating 'Back' button press..." << endl;
    string removed = history.pop();
    cout << "Removed: " << removed << endl;

    // 4. Display current TOP page
    cout << "\nCurrent TOP Page: " << history.peek() << endl;

    // 5. Display remaining history
    cout << "\n--- Remaining Browsing History ---" << endl;
    history.display();

    return 0;
}