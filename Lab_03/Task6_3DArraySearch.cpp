#include <iostream>
using namespace std;

int main()
{
    const int LAYERS = 2;
    const int ROWS = 2;
    const int COLS = 2;

    int a[LAYERS][ROWS][COLS] = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    // Display the 3D array
    cout << "3D Array:" << endl;
    for (int i = 0; i < LAYERS; i++)
    {
        cout << "\nLayer " << (i + 1) << ":" << endl;
        for (int j = 0; j < ROWS; j++)
        {
            for (int k = 0; k < COLS; k++)
            {
                cout << a[i][j][k] << "  ";
            }
            cout << endl;
        }
    }

    int target = 70;
    cout << "\nSearching for: " << target << endl;

    bool found = false;
    for (int i = 0; i < LAYERS && !found; i++)
    {
        for (int j = 0; j < ROWS && !found; j++)
        {
            for (int k = 0; k < COLS && !found; k++)
            {
                if (a[i][j][k] == target)
                {
                    cout << "\nElement found!" << endl;
                    cout << "Layer: " << (i + 1) << endl;
                    cout << "Row: " << (j + 1) << endl;
                    cout << "Column: " << (k + 1) << endl;
                    found = true;
                }
            }
        }
    }

    if (!found)
        cout << "\nElement not found." << endl;

    return 0;
}