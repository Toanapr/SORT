#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <iomanip>
#include <cmath>

void countingSort(std::vector<int> &arr, unsigned long long &countComparison);
void selectionSort(std::vector<int> &arr, unsigned long long &countComparison);
void bubbleSort(std::vector<int> &arr, unsigned long long &countComparison);
void shellSort(std::vector<int> &arr, unsigned long long &countComparison);
void mergeSort(std::vector<int> &arr, unsigned long long &countComparison);
void shakerSort(std::vector<int> &arr, unsigned long long &countComparison);
void quickSort(std::vector<int> &arr, unsigned long long &countComparison);
void flashSort(std::vector<int> &arr, unsigned long long &countComparison);
void radixSort(std::vector<int> &arr, unsigned long long &countComparison);
void heapSort(std::vector<int> &arr, unsigned long long &countComparison);
void insertionSort(std::vector<int> &arr, unsigned long long &countComparison);

const std::map<std::string, int> dataTypeMap = {
    {"-rand", 0},
    {"-sorted", 1},
    {"-rev", 2},
    {"-nsorted", 3}};

const std::map<std::string, std::string> dataTypeNameMap = {
    {"-rand", "Random"},
    {"-sorted", "Sorted"},
    {"-rev", "Reverse"},
    {"-nsorted", "Nearly Sorted"}};

const std::map<std::string, std::string> algorithmNameMap = {
    {"selection-sort", "Selection Sort"},
    {"insertion-sort", "Insertion Sort"},
    {"bubble-sort", "Bubble Sort"},
    {"shaker-sort", "Shaker Sort"},
    {"shell-sort", "Shell Sort"},
    {"heap-sort", "Heap Sort"},
    {"merge-sort", "Merge Sort"},
    {"quick-sort", "Quick Sort"},
    {"counting-sort", "Counting Sort"},
    {"radix-sort", "Radix Sort"},
    {"flash-sort", "Flash Sort"}};


const std::map<std::string, std::function<void(std::vector<int> &, unsigned long long &)>> algorithmFunctionMap = {
    {"selection-sort", selectionSort},
    {"insertion-sort", insertionSort},
    {"bubble-sort", bubbleSort},
    {"shaker-sort", shakerSort},
    {"shell-sort", shellSort},
    {"heap-sort", heapSort},
    {"merge-sort", mergeSort},
    {"quick-sort", quickSort},
    {"counting-sort", countingSort},
    {"radix-sort", radixSort},
    {"flash-sort", flashSort}};
