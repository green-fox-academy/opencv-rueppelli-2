#include "sort_functions.h"

std::vector<int> selectionSort(std::vector<int> &numbers, int o)
{
    int i, j, mindex;
    if(o == 1){
        for (i = 0; i < numbers.size(); ++i) {
            mindex = i;
            for (j = i + 1; j < numbers.size(); ++j) {
                if(numbers[mindex] > numbers[j]){
                    mindex = j;
                }
            }
            int swap = numbers[i];
            numbers[i] = numbers[mindex];
            numbers[mindex] = swap;
        }
    }else if(o == 0){
        for (i = 0; i < numbers.size(); ++i) {
            mindex = i;
            for (j = i + 1; j < numbers.size(); ++j) {
                if(numbers[mindex] < numbers[j]){
                    mindex = j;
                }
            }
            int swap = numbers[i];
            numbers[i] = numbers[mindex];
            numbers[mindex] = swap;
        }
    }

    return numbers;
}

int* selectionSort(int array[], int size, int o)
{
    int i, j, mindex;
    if(o == 1){
        for (i = 0; i < size; ++i) {
            mindex = i;
            for (j = i + 1; j < size; ++j) {
                if(array[mindex] > array[j]){
                    mindex = j;
                }
            }
            int swap = array[i];
            array[i] = array[mindex];
            array[mindex] = swap;
        }
    }else if(o == 0){
        for (i = 0; i < size; ++i) {
            mindex = i;
            for (j = i + 1; j < size; ++j) {
                if(array[mindex] < array[j]){
                    mindex = j;
                }
            }
            int swap = array[i];
            array[i] = array[mindex];
            array[mindex] = swap;
        }
    }

    return array;
}
