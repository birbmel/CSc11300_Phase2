/*
    Name: Tehseen Chowdhury, Melissa Martinez, and Ferdus Rifa
    Course: CSc 11300 1XB
    Project Phase 2: Reservation System
    Due Date: 06/30/2024 11:59pm
*/

#include <iostream>
using namespace std;

// Function to display menu to user
void displayMenu() {
    cout << "Please type 1 for \"Reservation\"\n";
    cout << "Please type 2 for \"Cancelling\"\n";
    cout << "Please type 3 for \"Displaying all seats\"\n";
    cout << "Please type 0 to \"Exit\"\n";
}

// Option 1: Reserves seat user chooses. 
void reserveSeat(bool seats[10][10]) {
    int row, col;
    cout << "Enter row (0-9): ";
    cin >> row;
    cout << "Enter column (0-9): ";
    cin >> col;

    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        cout << "Invalid seat coordinates.\n";
        return;
    }

    if (seats[row][col]) {
        cout << "Seat is already reserved.\n";
    }
    else {
        seats[row][col] = true;     // The corresponding elements of reserved seat is set to True/1. 
        cout << "Seat reserved successfully.\n";
    }
}

// Option 2: Cancels reservation of seat user chooses. 
void cancelReservation(bool seats[10][10]) {
    int row, col;
    cout << "Enter row (0-9): ";
    cin >> row;
    cout << "Enter column (0-9): ";
    cin >> col;

    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        cout << "Invalid seat coordinates.\n";
        return;
    }

    if (!seats[row][col]) {
        cout << "Seat is not reserved.\n";
    }
    else {
        seats[row][col] = false;
        cout << "Reservation cancelled successfully.\n";
    }
}

// Option 3: Displays all the seats; 1 is reserved and 0 is available. 
void displaySeats(bool seats[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    bool seats[10][10] = { false };     // Initializes array to False/0. 
    int option;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            reserveSeat(seats);
            break;
        case 2:
            cancelReservation(seats);
            break;
        case 3:
            displaySeats(seats);
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (option != 0);

    return 0;
}

