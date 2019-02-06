#include <gtest/gtest.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <time.h>

#include "detect_circle.h"
#include "sort_functions.h"

TEST(DetectCircles, noCircle)
{
    cv::Mat image = cv::imread("../../img/noCircle.jpg", cv::IMREAD_GRAYSCALE);
    EXPECT_EQ(detectCircle(image), 0);
}

TEST(DetectCircles, numerousCircles)
{
    cv::Mat image = cv::imread("../../img/ball.jpg", cv::IMREAD_GRAYSCALE);
    EXPECT_EQ(detectCircle(image), 3);
}

TEST(DetectCircles, overlayCircles)
{
    cv::Mat image = cv::imread("../../img/balls11.jpg", cv::IMREAD_GRAYSCALE);
    EXPECT_EQ(detectCircle(image), 3);
}

TEST(FastestSorting, increasingIntArray)
{
   srand(time(nullptr));

   int size = (rand() % 1000) + 1;

   int selectionSortArray[size];
   int insertionSortArray[size];
   int bubbleSortArray[size];
   int quickSortArray[size];

   int randomNumber = 0;

   for (int i = 0; i < size; ++i) {
       randomNumber = (rand() % 1000) + 1;

       selectionSortArray[i] = randomNumber;
       insertionSortArray[i] = randomNumber;
       bubbleSortArray[i] = randomNumber;
       quickSortArray[i] = randomNumber;
   }

   int counterSelection = 0;
   int counterInsertion = 0;
   int counterBubble = 0;
   int counterQuick = 0;

   int* newSelectionSort = selectionSort(selectionSortArray, size, counterSelection);
   int* newInsertionSort = insertionSort(insertionSortArray, size, counterInsertion);
   int* newBubbleSort;
   int* newQuickSort;

   ASSERT_LT(counterSelection, counterInsertion);
}

TEST(FastestSorting, decrasingIntArray)
{
    srand(time(nullptr));

    int size = (rand() % 1000) + 1;

    int selectionSortArray[size];
    int insertionSortArray[size];
    int bubbleSortArray[size];
    int quickSortArray[size];

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;

        selectionSortArray[i] = randomNumber;
        insertionSortArray[i] = randomNumber;
        bubbleSortArray[i] = randomNumber;
        quickSortArray[i] = randomNumber;
    }

    int counterSelection = 0;
    int counterInsertion = 0;
    int counterBubble = 0;
    int counterQuick = 0;

    int* newSelectionSort = selectionSort(selectionSortArray, size, counterSelection, 0);
    int* newInsertionSort = insertionSort(insertionSortArray, size, counterInsertion, 0);
    int* newBubbleSort;
    int* newQuickSort;

    ASSERT_LT(counterSelection, counterInsertion);
}

TEST(FastestSorting, increasingIntVector)
{
    srand(time(nullptr));

    int size = (rand() % 1000) + 1;

    std::vector<int> selectionSortVector;
    std::vector<int> insertionSortVector;
    std::vector<int> bubbleSortVector;
    std::vector<int> quickSortVector;

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;

        selectionSortVector.push_back(randomNumber);
        insertionSortVector.push_back(randomNumber);
        bubbleSortVector.push_back(randomNumber);
        quickSortVector.push_back(randomNumber);
    }

    int counterSelection = 0;
    int counterInsertion = 0;
    int counterBubble = 0;
    int counterQuick = 0;

    std::vector<int> newSelectionSort = selectionSort(selectionSortVector, counterSelection);
    std::vector<int> newInsertionSort = insertionSort(insertionSortVector, counterInsertion);
    std::vector<int> newBubbleSort;
    std::vector<int> newQuickSort;

    ASSERT_LT(counterSelection, counterInsertion);
}

TEST(FastestSorting, decrasingIntVector)
{
    srand(time(nullptr));

    int size = (rand() % 1000) + 1;

    std::vector<int> selectionSortVector;
    std::vector<int> insertionSortVector;
    std::vector<int> bubbleSortVector;
    std::vector<int> quickSortVector;

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;

        selectionSortVector.push_back(randomNumber);
        insertionSortVector.push_back(randomNumber);
        bubbleSortVector.push_back(randomNumber);
        quickSortVector.push_back(randomNumber);
    }

    int counterSelection = 0;
    int counterInsertion = 0;
    int counterBubble = 0;
    int counterQuick = 0;

    std::vector<int> newSelectionSort = selectionSort(selectionSortVector, counterSelection, 0);
    std::vector<int> newInsertionSort = insertionSort(insertionSortVector, counterInsertion, 0);
    std::vector<int> newBubbleSort;
    std::vector<int> newQuickSort;

    ASSERT_LT(counterSelection, counterInsertion);
}

TEST(FastestSorting, byTimeIntArray)
{
    srand(time(nullptr));

    int size = (rand() % 1000) + 1;

    int selectionSortArray[size];
    int insertionSortArray[size];
    int bubbleSortArray[size];
    int quickSortArray[size];

    int low;
    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;

        selectionSortArray[i] = randomNumber;
        insertionSortArray[i] = randomNumber;
        bubbleSortArray[i] = randomNumber;
        quickSortArray[i] = randomNumber;
    }

    int counterSelection = 0;
    int counterInsertion = 0;
    int counterBubble = 0;
    int counterQuick = 0;

    double timeSelection = 0;
    double timeInsertion = 0;
    double timeBubble = 0;
    double timeQuick = 0;

    int64 ts0 = cv::getTickCount();
    int* newSelectionSort = selectionSort(selectionSortArray, size, counterSelection, 0);
    int64 ts1 = cv::getTickCount();
    timeSelection = (ts1-ts0)/cv::getTickFrequency();

    int64 ti0 = cv::getTickCount();
    int* newInsertionSort = insertionSort(insertionSortArray, size, counterInsertion, 0);
    int64 ti1 = cv::getTickCount();
    timeInsertion = (ti1-ti0)/cv::getTickFrequency();

    /*int64 tb0 = cv::getTickCount();
    int* newBubbleSort = bubbleSort(bubbleSortArray, size, counterBubble, 0);
    int64 tb1 = cv::getTickCount();
    timeBubble = (tb1-tb0)/cv::getTickFrequency();*/

    int64 tq0 = cv::getTickCount();
    int* newQuickSort = quickSort(quickSortArray, low, size, counterInsertion, 0);
    int64 tq1 = cv::getTickCount();
    timeQuick = (tq1-tq0)/cv::getTickFrequency();

    ASSERT_LT(timeInsertion, timeSelection);
}

TEST(FastestSorting, byTimeIntVector)
{
    srand(time(nullptr));

    int size = (rand() % 1000) + 1;

    std::vector<int> selectionSortVector;
    std::vector<int> insertionSortVector;
    std::vector<int> bubbleSortVector;
    std::vector<int> quickSortVector;

    int low;
    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;

        selectionSortVector.push_back(randomNumber);
        insertionSortVector.push_back(randomNumber);
        bubbleSortVector.push_back(randomNumber);
        quickSortVector.push_back(randomNumber);
    }

    int counterSelection = 0;
    int counterInsertion = 0;
    int counterBubble = 0;
    int counterQuick = 0;

    double timeSelection = 0;
    double timeInsertion = 0;
    double timeBubble = 0;
    double timeQuick = 0;

    int64 ts0 = cv::getTickCount();
    std::vector<int> newSelectionSort = selectionSort(selectionSortVector, counterSelection, 0);
    int64 ts1 = cv::getTickCount();
    timeSelection = (ts1-ts0)/cv::getTickFrequency();

    int64 ti0 = cv::getTickCount();
    std::vector<int> newInsertionSort = insertionSort(insertionSortVector, counterInsertion, 0);
    int64 ti1 = cv::getTickCount();
    timeInsertion = (ti1-ti0)/cv::getTickFrequency();

    /*int64 tb0 = cv::getTickCount();
    std::vector<int> newBubbleSort;
    int64 tb1 = cv::getTickCount();
    timeBubble = (tb1-tb0)/cv::getTickFrequency();*/

    int64 tq0 = cv::getTickCount();
    std::vector<int> newQuickSort = quickSort(quickSortVector, low, size, counterQuick, 0);;
    int64 tq1 = cv::getTickCount();
    timeQuick = (tq1-tq0)/cv::getTickFrequency();

    ASSERT_LT(timeQuick, timeInsertion);
}