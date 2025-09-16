// ArrayOps.cpp
#include "ArrayOps.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>

int loadFromFile(const std::string& path, int arr[], int capacity) {
    std::ifstream in(path);
    if (!in) {
        throw std::runtime_error("Failed to open input file: " + path);
    }
    int x, count = 0;
    while (in >> x) {
        if (count >= capacity) {
            // stop loading if capacity reached—could also throw
            break;
        }
        arr[count++] = x;
    }
    return count;
}

void writeToFile(const std::string& path, const int arr[], int size) {
    std::ofstream out(path);
    if (!out) {
        throw std::runtime_error("Failed to open output file: " + path);
    }
    for (int i = 0; i < size; ++i) {
        out << arr[i];
        if ((i + 1) % 10 == 0) out << "\n";
        else if (i + 1 < size) out << ' ';
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if ((i + 1) % 10 == 0) std::cout << "\n";
        else if (i + 1 < size) std::cout << ' ';
    }
    if (size % 10 != 0) std::cout << "\n";
}

int findIndex(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

void modifyAt(int arr[], int size, int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("modifyAt: index out of range");
    }
    oldValue = arr[index];
    arr[index] = newValue;
}

void pushBack(int arr[], int& size, int capacity, int value) {
    if (size >= capacity) {
        throw std::overflow_error("pushBack: array is at capacity");
    }
    arr[size++] = value;
}

int removeAt(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("removeAt: index out of range");
    }
    int removed = arr[index];
    for (int i = index + 1; i < size; ++i) {
        arr[i - 1] = arr[i];
    }
    --size;
    return removed;
}
