#include <iostream>
using namespace std;

int main()
{
    const int FLOORS = 3;
    const int WARDS = 3;
    const int BEDS = 4;

    // 0 -> Available, 1 -> Occupied
    int beds[FLOORS][WARDS][BEDS] = {
        {
            {1, 0, 1, 0},
            {0, 0, 1, 1},
            {1, 1, 0, 0}
        },
        {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {0, 0, 0, 1}
        },
        {
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 0, 1, 1}
        }
    };

    // 2. Display the bed status of each floor and ward
    cout << "===== Hospital Bed Status =====" << endl;
    cout << "(0 = Available, 1 = Occupied)\n" << endl;
    for (int f = 0; f < FLOORS; f++)
    {
        cout << "Floor " << (f + 1) << ":" << endl;
        for (int w = 0; w < WARDS; w++)
        {
            cout << "  Ward " << (w + 1) << ": ";
            for (int b = 0; b < BEDS; b++)
            {
                cout << beds[f][w][b] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 3 & 4. Count total occupied and available beds
    int totalOccupied = 0, totalAvailable = 0;
    int occupiedPerFloor[FLOORS] = {0};

    for (int f = 0; f < FLOORS; f++)
    {
        for (int w = 0; w < WARDS; w++)
        {
            for (int b = 0; b < BEDS; b++)
            {
                if (beds[f][w][b] == 1)
                {
                    totalOccupied++;
                    occupiedPerFloor[f]++;
                }
                else
                {
                    totalAvailable++;
                }
            }
        }
    }

    cout << "Total Occupied Beds: " << totalOccupied << endl;
    cout << "Total Available Beds: " << totalAvailable << endl;

    // 5. Occupied beds on each floor
    cout << "\n===== Occupied Beds Per Floor =====" << endl;
    for (int f = 0; f < FLOORS; f++)
    {
        cout << "Floor " << (f + 1) << ": " << occupiedPerFloor[f] << " occupied bed(s)" << endl;
    }

    // 6. Ask the user to enter a floor, ward, and bed number
    int floor, ward, bed;
    cout << "\nEnter floor number (1 to " << FLOORS << "): ";
    cin >> floor;
    cout << "Enter ward number (1 to " << WARDS << "): ";
    cin >> ward;
    cout << "Enter bed number (1 to " << BEDS << "): ";
    cin >> bed;

    // Convert to 0-based indices
    floor--; ward--; bed--;

    // 7. Display whether the selected bed is available or occupied
    if (floor >= 0 && floor < FLOORS && ward >= 0 && ward < WARDS && bed >= 0 && bed < BEDS)
    {
        if (beds[floor][ward][bed] == 1)
            cout << "Bed " << (bed + 1) << " in Ward " << (ward + 1)
                 << " on Floor " << (floor + 1) << " is OCCUPIED." << endl;
        else
            cout << "Bed " << (bed + 1) << " in Ward " << (ward + 1)
                 << " on Floor " << (floor + 1) << " is AVAILABLE." << endl;
    }
    else
    {
        cout << "Invalid floor, ward, or bed number entered." << endl;
    }

    return 0;
}