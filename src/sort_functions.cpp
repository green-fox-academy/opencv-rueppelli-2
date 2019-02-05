#include "sort_functions.h"

std::vector<int> selectionSort(std::vector<int> &numbers, int &stepCounter, int o)
{
    int i, j, mindex;
    if(o == 1) {
        for (i = 0; i < numbers.size(); ++i) {
            mindex = i;
            for (j = i + 1; j < numbers.size(); ++j) {
                if(numbers[mindex] > numbers[j]) {
                    mindex = j;
                }
            }
            int swap = numbers[i];
            numbers[i] = numbers[mindex];
            numbers[mindex] = swap;
            stepCounter++;
        }
    } else if(o == 0) {
        for (i = 0; i < numbers.size(); ++i) {
            mindex = i;
            for (j = i + 1; j < numbers.size(); ++j) {
                if(numbers[mindex] < numbers[j]) {
                    mindex = j;
                }
            }
            int swap = numbers[i];
            numbers[i] = numbers[mindex];
            numbers[mindex] = swap;
            stepCounter++;
        }
    }

    return numbers;
}

int* selectionSort(int array[], int size, int &stepCounter, int o)
{
    int i, j, mindex;
    if(o == 1) {
        for (i = 0; i < size; ++i) {
            mindex = i;
            for (j = i + 1; j < size; ++j) {
                if(array[mindex] > array[j]) {
                    mindex = j;
                }
            }
            int swap = array[i];
            array[i] = array[mindex];
            array[mindex] = swap;
            stepCounter++;
        }
    } else if(o == 0) {
        for (i = 0; i < size; ++i) {
            mindex = i;
            for (j = i + 1; j < size; ++j) {
                if(array[mindex] < array[j]) {
                    mindex = j;
                }
            }
            int swap = array[i];
            array[i] = array[mindex];
            array[mindex] = swap;
            stepCounter++;
        }
    }

    return array;
}

int* insertionSort(int* inputArray, int size, int &stepCounter, int order)
{
    int pick = 0;
    int index = 0;

    for (int i = 1; i < size; ++i) {
        pick = inputArray[i];
        index = i - 1;

        if (order) {
            while (pick < inputArray[index] && index >= 0) {
                inputArray[index + 1] = inputArray[index];
                stepCounter++;
                index--;
            }
        } else {
            while (pick > inputArray[index] && index >= 0) {
                inputArray[index + 1] = inputArray[index];
                stepCounter++;
                index--;
            }
        }
        inputArray[index + 1] = pick;
        stepCounter++;
    }
    return inputArray;
}

std::vector<int> insertionSort(std::vector<int> inputVector, int &stepCounter, int order)
{
    int size = (int)inputVector.size();

    int pick = 0;
    int index = 0;

    for (int i = 1; i < size; ++i) {
        pick = inputVector[i];
        index = i - 1;

        if (order) {
            while (pick < inputVector[index] && index >= 0) {
                inputVector[index + 1] = inputVector[index];
                stepCounter++;
                index--;
            }
        } else {
            while (pick > inputVector[index] && index >= 0) {
                inputVector[index + 1] = inputVector[index];
                stepCounter++;
                index--;
            }
        }
        inputVector[index + 1] = pick;
        stepCounter++;
    }
    return inputVector;
}
