// main.cpp
// Demonstrates Q1 + Q2 requirements with try/catch around user inputs.
#include "ArrayOps.h"
#include <iostream>
#include <limits>
#include <stdexcept>

static int readInt(const char* prompt) {
    std::cout << prompt;
    int v;
    if (!(std::cin >> v)) {
        // Clear error state and discard line
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid integer input.");
    }
    return v;
}

int main(int argc, char* argv[]) {

    const int CAPACITY = 1000;
    int data[CAPACITY];
    int size = 0;

    std::string inPath = (argc >= 2) ? argv[1] : "A1input.txt";

    try {
        size = loadFromFile(inPath, data, CAPACITY);
        std::cout << "Loaded " << size << " integers from \"" << inPath << "\".\n\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Error while loading: " << ex.what() << "\n";
        return 1;
    }

    bool running = true;
    while (running) {
        std::cout << "=========== MENU ===========\n"
            << "1) Print array\n"
            << "2) Find index of a value\n"
            << "3) Modify value at index (Q1 + try/catch for Q2)\n"
            << "4) Add value to end (Q1 + try/catch for Q2)\n"
            << "5) Remove at index\n"
            << "6) Save to file\n"
            << "0) Exit\n"
            << "============================\n";

        int choice;
        try {
            choice = readInt("Choose: ");
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Input error: " << e.what() << "\n\n";
            continue;
        }

        std::cout << "\n";
        try {
            switch (choice) {
            case 1: {
                printArray(data, size);
                std::cout << "\n";
            } break;

            case 2: {
                int target = readInt("Enter value to search: ");
                int idx = findIndex(data, size, target);
                if (idx == -1) std::cout << target << " not found.\n\n";
                else std::cout << target << " found at index " << idx << ".\n\n";
            } break;

            case 3: { // modifyAt with try/catch (Q2)
                try {
                    int idx = readInt("Enter index to modify: ");
                    int newVal = readInt("Enter new value: ");
                    int oldVal = 0;
                    modifyAt(data, size, idx, newVal, oldVal);
                    std::cout << "Modified index " << idx << ": "
                        << "old=" << oldVal << ", new=" << newVal << "\n\n";
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Range error: " << e.what() << "\n\n";
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Input error: " << e.what() << "\n\n";
                }
            } break;

            case 4: { // pushBack with try/catch (Q2)
                try {
                    int val = readInt("Enter value to append: ");
                    pushBack(data, size, CAPACITY, val);
                    std::cout << "Appended " << val << ". New size = " << size << "\n\n";
                }
                catch (const std::overflow_error& e) {
                    std::cout << "Capacity error: " << e.what() << "\n\n";
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Input error: " << e.what() << "\n\n";
                }
            } break;

            case 5: {
                int idx = readInt("Enter index to remove: ");
                int removed = removeAt(data, size, idx);
                std::cout << "Removed value " << removed << " at index " << idx
                    << ". New size = " << size << "\n\n";
            } break;

            case 6: {
                std::string outPath;
                std::cout << "Enter output file name (e.g., output.txt): ";
                std::cin >> outPath;
                writeToFile(outPath, data, size);
                std::cout << "Saved to \"" << outPath << "\".\n\n";
            } break;

            case 0:
                running = false;
                break;

            default:
                std::cout << "Unknown choice. Try again.\n\n";
                break;
            }
        }
        catch (const std::exception& e) {
            // Generic safety net so program keeps running (avoids uncaught exceptions)
            std::cout << "Unexpected error: " << e.what() << "\n\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
