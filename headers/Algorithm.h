#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <iomanip>
#include <cmath>

// enum SORT_ALGORITHMS
// {
//     SELECTION_SORT,
//     INSERTION_SORT,
//     BUBBLE_SORT,
//     SHAKER_SORT,
//     SHELL_SORT,
//     HEAP_SORT,
//     MERGE_SORT,
//     QUICK_SORT,
//     COUNTING_SORT,
//     RADIX_SORT,
//     FLASH_SORT
// };

// enum DATA_TYPE
// {
//     RANDOM,
//     SORTED,
//     REVERSE,
//     NEARLY_SORTED
// };

// enum OUTPUT_PARAM
// {
//     TIME,
//     COMPARISIONS,
//     BOTH
// };

// const std::map<std::string, SORT_ALGORITHMS> algorithmMap = {
//     {"selection-sort", SELECTION_SORT},
//     {"insertion-sort", INSERTION_SORT},
//     {"bubble-sort", BUBBLE_SORT},
//     {"shaker-sort", SHAKER_SORT},
//     {"shell-sort", SHELL_SORT},
//     {"heap-sort", HEAP_SORT},
//     {"merge-sort", MERGE_SORT},
//     {"quick-sort", QUICK_SORT},
//     {"counting-sort", COUNTING_SORT},
//     {"radix-sort", RADIX_SORT},
//     {"flash-sort", FLASH_SORT}};

// const std::map<std::string, DATA_TYPE> dataTypeMap = {
//     {"-rand", RANDOM},
//     {"-sorted", SORTED},
//     {"-rev", REVERSE},
//     {"-nsorted", NEARLY_SORTED}};

// const std::map<std::string, OUTPUT_PARAM> outputParamMap = {
//     {"-time", TIME},
//     {"-comp", COMPARISIONS},
//     {"-both", BOTH}};

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



void mergeSort(std::vector<int> &arr, unsigned long long &countComparison);
void countingSort(std::vector<int> &arr, unsigned long long &countComparison);
void shakerSort(std::vector<int> &arr, unsigned long long &countComparison);
void shellSort(std::vector<int> &arr, unsigned long long &countComparison);
void heapSort(std::vector<int> &arr, unsigned long long &countComparison);
void flashSort(std::vector<int> &arr, unsigned long long &countComparison);
void quickSort(std::vector<int> &arr, unsigned long long &countComparison);
void bubbleSort(std::vector<int> &arr, unsigned long long &countComparison);
void insertionSort(std::vector<int> &arr, unsigned long long &countComparison);
void radixSort(std::vector<int> &arr, unsigned long long &countComparison);
void selectionSort(std::vector<int> &arr, unsigned long long &countComparison);

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


// const std::map<SORT_ALGORITHMS, std::function<void(std::vector<int> &, unsigned long long &)>> algorithmFunctionMap = {
//     {SELECTION_SORT, selectionSort},
//     {INSERTION_SORT, insertionSort},
//     {BUBBLE_SORT, bubbleSort},
//     {SHAKER_SORT, shakerSort},
//     {SHELL_SORT, shellSort},
//     {HEAP_SORT, heapSort},
//     {MERGE_SORT, mergeSort},
//     {QUICK_SORT, quickSort},
//     {COUNTING_SORT, countingSort},
//     {RADIX_SORT, radixSort},
//     {FLASH_SORT, flashSort}};

// const std::map<SORT_ALGORITHMS, std::string> algorithmNameMap = {
//     {SELECTION_SORT, "Selection Sort"},
//     {INSERTION_SORT, "Insertion Sort"},
//     {BUBBLE_SORT, "Bubble Sort"},
//     {SHAKER_SORT, "Shaker Sort"},
//     {SHELL_SORT, "Shell Sort"},
//     {HEAP_SORT, "Heap Sort"},
//     {MERGE_SORT, "Merge Sort"},
//     {QUICK_SORT, "Quick Sort"},
//     {COUNTING_SORT, "Counting Sort"},
//     {RADIX_SORT, "Radix Sort"},
//     {FLASH_SORT, "Flash Sort"}};

// const std::map<DATA_TYPE, std::string> dataTypeNameMap = {
//     {RANDOM, "Random"},
//     {SORTED, "Sorted"},
//     {REVERSE, "Reverse"},
//     {NEARLY_SORTED, "Nearly Sorted"}};
