#ifndef COMPUTER_VISION_SORT_FUNCTIONS_H
#define COMPUTER_VISION_SORT_FUNCTIONS_H

#include <vector>
#include <iostream>

std::vector<int> selectionSort(std::vector<int> numbers, int &stepCounter, int o = 1);
int* selectionSort(int array[], int size, int &stepCounter, int o = 1);

std::vector<int> insertionSort(std::vector<int> inputVector, int &stepCounter, int order = 1);
int* insertionSort(int* inputArray, int size, int &stepCounter, int order = 1);

std::vector<int> quickSort(std::vector<int> &vector, int low, int high, int &stepCounter, int mode = 1);
int* quickSort(int* array, int low, int high, int &stepCounter, int mode = 1);

std::vector<int> bubbleSort(std::vector<int> a, int &stepCounter, int n = 1);
int* bubbleSort(int arr[], int size, int &stepCounter, int n = 1);

int* shakerSort(int* array, int size, int &stepCounter, int mode = 1);
std::vector<int> shakerSort(std::vector<int> &vector, int &stepCounter, int mode = 1);
#endif
