#include <iostream>
using namespace std;

int main()
{
    const int LABS = 2;
    const int ROWS = 3;
    const int COMPUTERS = 5;

    // 0 -> Available, 1 -> In Use
    int labs[LABS][ROWS][COMPUTERS] = {
        {
            {1, 0, 1, 0, 0},
            {0, 1, 1, 0, 1},
            {1, 0, 0, 1, 0}
        },
        {
            {0, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 0, 0}
        }
    };

    // 2. Display the status of all computers lab by lab
    cout << "===== Computer Lab Status =====" << endl;
    cout << "(0 = Available, 1 = In Use)\n" << endl;
    for (int l = 0; l < LABS; l++)
    {
        cout << "Lab " << (l + 1) << ":" << endl;
        for (int r = 0; r < ROWS; r++)
        {
            cout << "  Row " << (r + 1) << ": ";
            for (int c = 0; c < COMPUTERS; c++)
            {
                cout << labs[l][r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 3 & 4. Count total available and in-use computers
    int totalAvailable = 0, totalInUse = 0;
    int availablePerLab[LABS] = {0};

    for (int l = 0; l < LABS; l++)
    {
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COMPUTERS; c++)
            {
                if (labs[l][r][c] == 0)
                {
                    totalAvailable++;
                    availablePerLab[l]++;
                }
                else
                {
                    totalInUse++;
                }
            }
        }
    }

    cout << "Total Available Computers: " << totalAvailable << endl;
    cout << "Total Computers In Use: " << totalInUse << endl;

    // 5. Available computers in each lab
    cout << "\n===== Available Computers Per Lab =====" << endl;
    for (int l = 0; l < LABS; l++)
    {
        cout << "Lab " << (l + 1) << ": " << availablePerLab[l] << " available computer(s)" << endl;
    }

    // 6. Ask the user to enter a lab, row, and computer number
    int lab, row, computer;
    cout << "\nEnter lab number (1 to " << LABS << "): ";
    cin >> lab;
    cout << "Enter row number (1 to " << ROWS << "): ";
    cin >> row;
    cout << "Enter computer number (1 to " << COMPUTERS << "): ";
    cin >> computer;

    // Convert to 0-based indices
    lab--; row--; computer--;

    // 7. Display the current status of the selected computer
    if (lab >= 0 && lab < LABS && row >= 0 && row < ROWS && computer >= 0 && computer < COMPUTERS)
    {
        if (labs[lab][row][computer] == 1)
            cout << "Computer " << (computer + 1) << " in Row " << (row + 1)
                 << ", Lab " << (lab + 1) << " is IN USE." << endl;
        else
            cout << "Computer " << (computer + 1) << " in Row " << (row + 1)
                 << ", Lab " << (lab + 1) << " is AVAILABLE." << endl;
    }
    else
    {
        cout << "Invalid lab, row, or computer number entered." << endl;
    }

    return 0;
}