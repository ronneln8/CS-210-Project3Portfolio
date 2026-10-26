// Developer: Ronnel Narciso
// Date: 2026-10-18
// Project Three

#include <iostream>
#include <string>
#include <limits>
#include "ItemTracker.h"

using namespace std;

// Function to display the menu options
void printMenu() {
    cout << "\n========================================" << endl;
    cout << "        CORNER GROCER ITEM TRACKER      " << endl;
    cout << "========================================" << endl;
    cout << "1. Look up the frequency of a specific item" << endl;
    cout << "2. Print the frequency of all items" << endl;
    cout << "3. Print a histogram of all items" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Instantiate the ItemTracker class
    // This automatically reads the input file and creates the frequency.dat backup
    ItemTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int userChoice = 0;
    string searchItem;

    while (userChoice != 4) {
        printMenu();

        // Input validation: Check if the user entered an integer
        if (!(cin >> userChoice)) {
            cout << "\nInvalid input. Please enter a number between 1 and 4." << endl;
            // Clear the error state
            cin.clear();
            // Discard the bad input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Process the valid integer choice
        switch (userChoice) {
            case 1:
                cout << "\nEnter the name of the item to look up: ";
                cin >> searchItem;
                // Capitalize first letter to match file formatting if necessary
                searchItem[0] = toupper(searchItem[0]); 
                
                cout << "\n" << searchItem << " was purchased " 
                     << tracker.getItemFrequency(searchItem) << " times." << endl;
                break;

            case 2:
                tracker.printAllFrequencies();
                break;

            case 3:
                tracker.printHistogram();
                break;

            case 4:
                cout << "\nExiting program. Backup data saved in 'frequency.dat'." << endl;
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "\nInvalid choice. Please select a valid option from the menu." << endl;
                break;
        }
    }

    return 0;
}