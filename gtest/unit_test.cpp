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

TEST(FastestSortingStep, increasingIntArray)
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
   int* newBubbleSort = bubbleSort(bubbleSortArray, size, counterBubble);

   int low = quickSortArray[0];
   int high = quickSortArray[size-1];
   int* newQuickSort = quickSort(quickSortArray, low, high, counterQuick);

   ASSERT_LT(counterQuick, counterInsertion);
}

TEST(FastestSortingStep, decrasingIntArray)
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
    int* newBubbleSort = bubbleSort(bubbleSortArray, size, counterBubble, 0);

    int low = quickSortArray[0];
    int high = quickSortArray[size-1];
    int* newQuickSort = quickSort(quickSortArray, low, high, counterQuick, 0);

    ASSERT_LT(counterQuick, counterInsertion);
}

TEST(FastestSortingStep, increasingIntVector)
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
    std::vector<int> newBubbleSort = bubbleSort(bubbleSortVector, counterBubble);

    int low = quickSortVector[0];
    int high = quickSortVector[size-1];
    std::vector<int> newQuickSort = quickSort(quickSortVector, low, high, counterQuick);

    ASSERT_LT(counterQuick, counterInsertion);
}

TEST(FastestSortingStep, decrasingIntVector)
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
    std::vector<int> newBubbleSort = bubbleSort(bubbleSortVector, counterBubble, 0);

    int low = quickSortVector[0];
    int high = quickSortVector[size-1];
    std::vector<int> newQuickSort = quickSort(quickSortVector, low, high, counterQuick, 0);

    ASSERT_LT(counterQuick, counterInsertion);
}

TEST(FastestSortingTime, byTimeIntArray)
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

    int64 tb0 = cv::getTickCount();
    int* newBubbleSort = bubbleSort(bubbleSortArray, size, counterBubble, 0);
    int64 tb1 = cv::getTickCount();
    timeBubble = (tb1-tb0)/cv::getTickFrequency();

    int low = quickSortArray[0];
    int high = quickSortArray[size-1];
    int64 tq0 = cv::getTickCount();
    int* newQuickSort = quickSort(quickSortArray, low, high, counterQuick, 0);
    int64 tq1 = cv::getTickCount();
    timeQuick = (tq1-tq0)/cv::getTickFrequency();

    ASSERT_LT(timeQuick, timeInsertion);
}

TEST(FastestSortingTime, byTimeIntVector)
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

    int64 tb0 = cv::getTickCount();
    std::vector<int> newBubbleSort = bubbleSort(bubbleSortVector, counterBubble, 0);
    int64 tb1 = cv::getTickCount();
    timeBubble = (tb1-tb0)/cv::getTickFrequency();

    int low = quickSortVector[0];
    int high = quickSortVector[size-1];
    int64 tq0 = cv::getTickCount();
    std::vector<int> newQuickSort = quickSort(quickSortVector, low, high, counterQuick, 0);
    int64 tq1 = cv::getTickCount();
    timeQuick = (tq1-tq0)/cv::getTickFrequency();

    ASSERT_LT(timeQuick, timeInsertion);
}

TEST(Bubblesort, increaseVector)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    std::vector<int> bubbleSortVector;
    std::vector<int> sortFunctionVector;

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 100) + 1;
        bubbleSortVector.push_back(randomNumber);
    }
    int counterBubble = 0;

    std::vector<int> newBubbleSort = bubbleSort( bubbleSortVector, counterBubble, 1);

    std::sort(bubbleSortVector.begin(), bubbleSortVector.end());
    for (auto x : bubbleSortVector) {
        sortFunctionVector.push_back(x);
    }

    EXPECT_EQ(newBubbleSort, sortFunctionVector);
}

TEST(Bubblesort, decreaseVector)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    std::vector<int> bubbleSortVector;
    std::vector<int> sortFunctionVector;

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;
        bubbleSortVector.push_back(randomNumber);
    }
    int counterBubble = 0;

    std::vector<int> newBubbleSort = bubbleSort( bubbleSortVector, counterBubble, 0);

    std::sort(bubbleSortVector.rbegin(), bubbleSortVector.rend());

    for (auto x : bubbleSortVector) {
        sortFunctionVector.push_back(x);
    }

    EXPECT_EQ(newBubbleSort, sortFunctionVector);
}

TEST(Bubblesort, increaseArray)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    int bubbleSortArray[size];
    int sortFunctionArray[size];

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;
        bubbleSortArray[i] = randomNumber;
    }
    int counterBubble = 0;

    int* newBubbleSort = bubbleSort(bubbleSortArray, size, counterBubble, 0);

    int n = sizeof(bubbleSortArray)/sizeof(bubbleSortArray[0]);

    std::sort(bubbleSortArray, bubbleSortArray+n);

    for (int i = 0; i < n; ++i){
        sortFunctionArray[i] = bubbleSortArray[i];
    }
    for (int j = 0; j < size; ++j){
        EXPECT_EQ(newBubbleSort[j], sortFunctionArray[j]);
    }
}

TEST(Bubblesort, decreaseArray)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    int bubbleSortArray[size];
    int sortFunctionArray[size];

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;
        bubbleSortArray[i] = randomNumber;
    }
    int counterBubble = 0;

    int* newBubbleSort = bubbleSort(bubbleSortArray, size, counterBubble, 1);

    int n = sizeof(bubbleSortArray)/sizeof(bubbleSortArray[0]);

    std::sort(bubbleSortArray, bubbleSortArray+n);

    for (int i = n-1; i >=0; --i){
        sortFunctionArray[i] = bubbleSortArray[i];
    }
    for (int j = 0; j < size; ++j){
        EXPECT_EQ(newBubbleSort[j], sortFunctionArray[j]);
    }
}

TEST(Selectionsort, increaseVector)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    std::vector<int> selectionSortVector;
    std::vector<int> sortFunctionVector;

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 100) + 1;
        selectionSortVector.push_back(randomNumber);
    }
    int counterSelection = 0;

    std::vector<int> newSelectionSort = selectionSort( selectionSortVector, counterSelection, 1);

    std::sort(selectionSortVector.begin(), selectionSortVector.end());
    for (auto x : selectionSortVector) {
        sortFunctionVector.push_back(x);
    }

    EXPECT_EQ(newSelectionSort, sortFunctionVector);
}

TEST(Selectionsort, decreaseVector)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    std::vector<int> selectionSortVector;
    std::vector<int> sortFunctionVector;

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;
        selectionSortVector.push_back(randomNumber);
    }
    int counterSelection = 0;

    std::vector<int> newSelectionSort = selectionSort( selectionSortVector, counterSelection, 0);

    std::sort(selectionSortVector.rbegin(), selectionSortVector.rend());

    for (auto x : selectionSortVector) {
        sortFunctionVector.push_back(x);
    }

    EXPECT_EQ(newSelectionSort, sortFunctionVector);
}

TEST(Selectionsort, increaseArray)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    int selectionSortArray[size];
    int sortFunctionArray[size];

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;
        selectionSortArray[i] = randomNumber;
    }
    int counterSelection = 0;

    int* newSelectionSort = selectionSort(selectionSortArray, size, counterSelection, 0);

    int n = sizeof(selectionSortArray)/sizeof(selectionSortArray[0]);

    std::sort(selectionSortArray, selectionSortArray+n);

    for (int i = 0; i < n; ++i){
        sortFunctionArray[i] = selectionSortArray[i];
    }
    for (int j = 0; j < size; ++j){
        EXPECT_EQ(newSelectionSort[j], sortFunctionArray[j]);
    }
}
TEST(Selectionsort, decreaseArray)
{
    srand(time(nullptr));
    int size = (rand() % 1000) + 1;

    int selectionSortArray[size];
    int sortFunctionArray[size];

    int randomNumber = 0;

    for (int i = 0; i < size; ++i) {
        randomNumber = (rand() % 1000) + 1;
        selectionSortArray[i] = randomNumber;
    }
    int counterSelection = 0;

    int* newSelectionSort = selectionSort(selectionSortArray, size, counterSelection, 1);

    int n = sizeof(selectionSortArray)/sizeof(selectionSortArray[0]);

    std::sort(selectionSortArray, selectionSortArray+n);

    for (int i = n-1; i >=0; --i){
        sortFunctionArray[i] = selectionSortArray[i];
    }
    for (int j = 0; j < size; ++j){
        EXPECT_EQ(newSelectionSort[j], sortFunctionArray[j]);
    }
}
