// ArrayOps.h
// CS303 Assignment
// Bean Nguyen
// No std::vector used

#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

#include <string>

// Reads integers from a text file into arr up to capacity.
// Returns the count loaded; throws std::runtime_error on file issues.
int loadFromFile(const std::string& path, int arr[], int capacity);

// Writes the array to a text file (space-separated, 10 per line).
void writeToFile(const std::string& path, const int arr[], int size);

// Prints array to std::cout (space-separated, 10 per line).
void printArray(const int arr[], int size);

// Returns index of first occurrence of target or -1 if not found.
int findIndex(const int arr[], int size, int target);

// Modifies value at index; returns old value via reference.
// Throws std::out_of_range if index invalid.
void modifyAt(int arr[], int size, int index, int newValue, int& oldValue);

// Appends value to the end (size increases by 1).
// Throws std::overflow_error if array is at capacity.
void pushBack(int arr[], int& size, int capacity, int value);

// Removes value at index (shifts left), returns removed value.
// Throws std::out_of_range if index invalid.
int removeAt(int arr[], int& size, int index);

#endif // ARRAY_OPS_H
#pragma once
