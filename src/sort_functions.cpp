#include "sort_functions.h"

std::vector<int> selectionSort(std::vector<int> numbers, int &stepCounter, int o)
{
    int i, j, mindex;
    if (o == 1) {
        for (i = 0; i < numbers.size(); ++i) {
            mindex = i;
            for (j = i + 1; j < numbers.size(); ++j) {
                if (numbers[mindex] > numbers[j]) {
                    mindex = j;
                }
            }
            int swap = numbers[i];
            numbers[i] = numbers[mindex];
            numbers[mindex] = swap;
            stepCounter++;
        }
    } else if (o == 0) {
        for (i = 0; i < numbers.size(); ++i) {
            mindex = i;
            for (j = i + 1; j < numbers.size(); ++j) {
                if (numbers[mindex] < numbers[j]) {
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
    if (o == 1) {
        for (i = 0; i < size; ++i) {
            mindex = i;
            for (j = i + 1; j < size; ++j) {
                if (array[mindex] > array[j]) {
                    mindex = j;
                }
            }
            int swap = array[i];
            array[i] = array[mindex];
            array[mindex] = swap;
            stepCounter++;
        }
    } else if (o == 0) {
        for (i = 0; i < size; ++i) {
            mindex = i;
            for (j = i + 1; j < size; ++j) {
                if (array[mindex] < array[j]) {
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

int* quickSort(int* array, int low, int high, int &stepCounter, int mode)
{
    int* newArray = array;
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    if (mode == 1) {

        while (i <= j) {
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;
            if (i <= j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
                stepCounter++;
            }
        }
        if (j > low) {
            quickSort(array, low, stepCounter, j);
        }
        if (i < high) {
            quickSort(array, i, stepCounter, high);
        }
    }
    else if (mode == 0) {
        while (i <= j) {
            while (array[i] > pivot)
                i++;
            while (array[j] < pivot)
                j--;
            if (i <= j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
                stepCounter++;
            }
        }
        if (j > low) {
            quickSort(array, low, j, stepCounter, 0);
        }
        if (i < high) {
            quickSort(array, i, high, stepCounter, 0);
        }
    }
    return newArray;
}

std::vector<int> quickSort(std::vector<int> &vector, int low, int high, int &stepCounter, int mode)
{
    std::vector<int> newVector = vector;
    int i = low;
    int j = high;
    int pivot = vector[(i + j) / 2];
    int temp = 0;

    if (mode==1) {

        while (i <= j) {
            while (vector[i] < pivot)
                i++;
            while (vector[j] > pivot)
                j--;
            if (i <= j) {
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
                i++;
                j--;
                stepCounter++;
            }
        }
        if (j > low) {
            quickSort(vector, low, stepCounter, j);
        }
        if (i < high) {
            quickSort(vector, i, stepCounter, high);
        }
    }
    else if (mode == 0) {
        while (i <= j) {
            while (vector[i] > pivot)
                i++;
            while (vector[j] < pivot)
                j--;
            if (i <= j) {
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
                i++;
                j--;
                stepCounter++;
            }
        }
        if (j > low) {
            quickSort(vector, low, j, stepCounter, 0);
        }
        if (i < high) {
            quickSort(vector, i, high, stepCounter, 0);
        }
    }
    return newVector;
}

std::vector<int> bubbleSort(std::vector<int> a, int &stepCounter, int n)
{
    for (size_t i = 1; i < a.size(); ++i) {
        for (size_t j = 0; j < a.size() - 1; ++j) {
            if (n == 1) {
                if (a[j] > a[i]) {
                    std::swap(a[j], a[i]);
                }
            } else if (n == 0) {
                if (a[j] < a[i]) {
                    std::swap(a[j], a[i]);
                }
            }
            stepCounter++;
        }
    }
    return a;
}

int* bubbleSort(int arr[], int size, int &stepCounter, int n)
{
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++){
            if (n == 1) {
                if (arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    stepCounter++;
                }
            } else if (n == 0) {
                if (arr[j] < arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    stepCounter++;
                }
            }
        }
    }
    return arr;
}

int* shakerSort(int* array, int size, int &stepCounter, int mode){
    int *newArray = array;

    int i;
    int j;
    int k;

    if(mode == 1) {
        for (k = 0; k < size;) {
            for (i = 0; i < size - 1; i++) {
                if (array[i] > array[i + 1]) {
                    std::swap(array[i], array[i + 1]);
                    stepCounter++;
                }
            }
            size--;
            for (j = size - 1; j > 0; j--) {
                if (array[j] < array[j - 1]) {
                    std::swap(array[j], array[j - 1]);
                    stepCounter++;
                }
            }
            k++;
        }
    }else if (mode == 0) {
        for (k = 0; k < size;) {
            for (i = 0; i < size - 1; i++) {
                if (array[i] < array[i + 1]) {
                    std::swap(array[i], array[i + 1]);
                    stepCounter++;
                }
            }
            size--;
            for (j = size - 1; j > 0; j--) {
                if (array[j] > array[j - 1]) {
                    std::swap(array[j], array[j - 1]);
                    stepCounter++;
                }
            }
            k++;
        }
    }
    return newArray;
}

std::vector<int> shakerSort(std::vector<int> vector, int &stepCounter, int mode){
    std::vector<int> newVector = vector;
    int size = (int)vector.size();

    int i;
    int j;
    int k;

    if(mode == 1) {
        for (k = 0; k < size;) {
            for (i = 0; i < size- 1; i++) {
                if (vector[i] > vector[i + 1]) {
                    std::swap(vector[i], vector[i + 1]);
                    stepCounter++;
                }
            }
            size--;
            for (j = size - 1; j > 0; j--) {
                if (vector[j] < vector[j - 1]) {
                    std::swap(vector[j], vector[j - 1]);
                    stepCounter++;
                }
            }
            k++;
        }
    }else if (mode == 0) {
        for (k = 0; k < size;) {

            for (i = 0; i < size - 1; i++) {
                if (vector[i] < vector[i + 1]) {
                    std::swap(vector[i], vector[i + 1]);
                    stepCounter++;
                }
            }
            size--;
            for (j = size - 1; j > 0; j--) {
                if (vector[j] > vector[j - 1]) {
                    std::swap(vector[j], vector[j - 1]);
                    stepCounter++;
                }
            }
            k++;
        }
    }
    return newVector;
}
