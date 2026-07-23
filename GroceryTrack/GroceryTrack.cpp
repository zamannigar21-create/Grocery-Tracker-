/*
* CS-210 Project Three: Corner Grocer Item Tracking
* Author: Nigar Babayeva
* Date: 2/22/2026
*/


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <cctype>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;
    string inputFileName;
    string backupFileName;

    // Convert a string to lowercase (simple loop version for zyBooks)
    string ToLower(string word) {
        for (unsigned int i = 0; i < word.size(); ++i) {
            word.at(i) = (char)tolower(word.at(i));
        }
        return word;
    }

public:
    GroceryTracker(string inputFile, string backupFile) {
        inputFileName = inputFile;
        backupFileName = backupFile;
    }

    bool LoadData() {
        ifstream inFS(inputFileName);

        if (!inFS.is_open()) {
            cout << "ERROR: Could not open input file: " << inputFileName << endl;
            return false;
        }

        itemFrequency.clear();

        string item;
        while (inFS >> item) {
            item = ToLower(item);
            itemFrequency[item] = itemFrequency[item] + 1;
        }

        inFS.close();
        return true;
    }

    bool WriteBackupFile() {
        ofstream outFS(backupFileName);

        if (!outFS.is_open()) {
            cout << "ERROR: Could not create backup file: " << backupFileName << endl;
            return false;
        }

        map<string, int>::iterator it;
        for (it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
            outFS << it->first << " " << it->second << endl;
        }

        outFS.close();
        return true;
    }

    int GetFrequency(string item) {
        item = ToLower(item);

        if (itemFrequency.count(item) == 0) {
            return 0;
        }
        return itemFrequency[item];
    }

    void PrintAllFrequencies() {
        map<string, int>::iterator it;
        for (it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }

    void PrintHistogram() {
        map<string, int>::iterator it;
        for (it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
            cout << it->first << " ";
            for (int i = 0; i < it->second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

void PrintMenu() {
    cout << "\n====== GroceryTrack Menu ======\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "==============================\n";
}

int ReadMenuChoice() {
    int choice;

    while (true) {
        cout << "Enter your choice: ";

        if (cin >> choice) {
            if (choice >= 1 && choice <= 4) {
                return choice;
            }
            cout << "Please enter a number from 1 to 4." << endl;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    // Load data and create backup file at the beginning (required)
    if (!tracker.LoadData()) {
        cout << "Program cannot continue without the input file." << endl;
        return 1;
    }
    tracker.WriteBackupFile();

    int choice = 0;

    while (choice != 4) {
        PrintMenu();
        choice = ReadMenuChoice();

        if (choice == 1) {
            string item;
            cout << "Enter the item to look for: ";
            cin >> item;
            cout << "Frequency: " << tracker.GetFrequency(item) << endl;
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
        else if (choice == 4) {
            cout << "Goodbye." << endl;
        }
    }

    return 0;
}
