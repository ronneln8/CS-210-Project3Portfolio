#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    // Map to store the grocery item (key) and its purchase frequency (value)
    std::map<std::string, int> itemFrequencies;

    // Private helper methods for initialization
    void loadInputFile(const std::string& inputFile);
    void createBackupFile(const std::string& backupFile);

public:
    // Constructor
    ItemTracker(const std::string& inputFile, const std::string& backupFile);

    // Core functionality methods
    int getItemFrequency(const std::string& item) const;
    void printAllFrequencies() const;
    void printHistogram() const;
};

#endif // ITEMTRACKER_H