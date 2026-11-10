#include <iostream>
using namespace std;

int main()
{
    const int ROWS = 4;
    const int SPACES = 5;

    // 0 -> Empty, 1 -> Occupied
    int parking[ROWS][SPACES] = {
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1}
    };

    // 1 & 2. Display the complete parking layout
    cout << "===== Parking Layout =====" << endl;
    cout << "(0 = Empty, 1 = Occupied)\n" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "Row " << i << ": ";
        for (int j = 0; j < SPACES; j++)
        {
            cout << parking[i][j] << "\t";
        }
        cout << endl;
    }

    // 3. Count total occupied and 4. total empty spaces
    int occupied = 0, empty = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < SPACES; j++)
        {
            if (parking[i][j] == 1)
                occupied++;
            else
                empty++;
        }
    }

    cout << "\nTotal Occupied Spaces: " << occupied << endl;
    cout << "Total Empty Spaces: " << empty << endl;

    // 5. Ask the user to enter a row and column number
    int row, col;
    cout << "\nEnter row number (0 to " << ROWS - 1 << "): ";
    cin >> row;
    cout << "Enter column number (0 to " << SPACES - 1 << "): ";
    cin >> col;

    // 6. Check whether the selected space is available or occupied
    if (row >= 0 && row < ROWS && col >= 0 && col < SPACES)
    {
        if (parking[row][col] == 1)
            cout << "Parking space [" << row << "][" << col << "] is OCCUPIED." << endl;
        else
            cout << "Parking space [" << row << "][" << col << "] is AVAILABLE." << endl;
    }
    else
    {
        cout << "Invalid row or column entered." << endl;
    }

    // 7. Display the total parking capacity and current occupancy
    int capacity = ROWS * SPACES;
    cout << "\nTotal Parking Capacity: " << capacity << endl;
    cout << "Current Occupancy: " << occupied << " / " << capacity << endl;

    return 0;
}