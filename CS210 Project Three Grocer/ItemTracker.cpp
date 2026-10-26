// Developer: Ronnel Narciso
// Date: 2026-10-18
// Project Three

#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor automatically loads the input file and generates the backup file
ItemTracker::ItemTracker(const string& inputFile, const string& backupFile) {
    loadInputFile(inputFile);
    createBackupFile(backupFile);
}

// Reads the text file and populates the map
void ItemTracker::loadInputFile(const string& inputFile) {
    ifstream inFS(inputFile);
    string item;

    // Check if file opened successfully
    if (!inFS.is_open()) {
        cout << "Error: Could not open " << inputFile << ". Please ensure the file is in the correct directory." << endl;
        return;
    }

    // Read each word from the file and increment its count in the map
    while (inFS >> item) {
        itemFrequencies[item]++;
    }

    inFS.close();
}

// Writes the map contents to a backup .dat file
void ItemTracker::createBackupFile(const string& backupFile) {
    ofstream outFS(backupFile);

    if (!outFS.is_open()) {
        cout << "Error: Could not create backup file " << backupFile << "." << endl;
        return;
    }

    // Iterate through the map and write to the file
    for (const auto& pair : itemFrequencies) {
        outFS << pair.first << " " << pair.second << endl;
    }

    outFS.close();
}

// Option 1: Returns the frequency of a specific item
int ItemTracker::getItemFrequency(const string& item) const {
    // map::find returns an iterator to the item, or map::end if not found
    auto it = itemFrequencies.find(item);
    if (it != itemFrequencies.end()) {
        return it->second; // Return the integer frequency
    }
    return 0; // Return 0 if the item isn't in the list
}

// Option 2: Prints all items and their frequencies
void ItemTracker::printAllFrequencies() const {
    cout << "\n--- All Item Frequencies ---" << endl;
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << "----------------------------\n";
}

// Option 3: Prints a text-based histogram
void ItemTracker::printHistogram() const {
    cout << "\n--- Item Histogram ---" << endl;
    for (const auto& pair : itemFrequencies) {
        // setw(15) aligns the asterisks neatly by padding the item name with spaces
        cout << setw(15) << left << pair.first << " ";
        
        // Print an asterisk for each count of the item
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << "----------------------\n";
}