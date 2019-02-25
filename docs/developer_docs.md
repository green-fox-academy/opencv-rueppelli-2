## developer documentation

[Detect circle](#Detect-circle)

[Light patterns](#Light-patterns) 

[Binary images](#Binary-images)

[Selection sort](#Selection-sort)

[Insertion sort](#Insertion-sort)

[Quick sort](#Quick-sort)

[Bubble sort](#Bubble-sort)

[Merge sort] (#Merge-sort)

[Heap sort] (#Heap-sort)

[Shell sort] (#Shell-sort)

[Shaker sort] (#Shaker-sort)

[Histogram] (#Histogram)

### Detect circle
```int detectCircle(cv::Mat &image)```
   - Purpose of the function:
     - it detects the circles on the input image
   - Parameter:
     - image: input is an image, 
   - Returntype: int, the number of found circles on the input image

### Light patterns
```cv:: Mat removeLightWithDifference(cv:: Mat image, cv:: Mat pattern)```
   - Purpose of the function:
     - to extract the image from pattern
   - Parameters:
     - image: Input image
     - pattern: Input image with pattern
   - Returntype cv::Mat 
   
```cv:: Mat removeLightWithDivision(cv:: Mat image, cv:: Mat pattern)```
   - Purpose of the function:
     - to device the pattern with the image
   - Parameters:
     - image: Input image
     - pattern: Input image with pattern
   - Returntype cv::Mat
   
```cv:: Mat removeLightWithBlur(cv:: Mat image)```
   - Purpose of the function:
     - remove light with blur
   - Parameter:
     - image: Input image
   - Returntype cv::Mat

### Binary images    
```cv::Mat binarizeImage(cv::Mat image)```
   - Purpose of the function:
     - it binarize the images
   - Parameter:
     - image: Input image
   - Returntype cv::Mat
   
```cv::Mat binarizeImageInverse(cv::Mat image)```
   - Purpose of the function:
     - it binarize the input image
   - Parameter:
     - image: Input image
   - Returntype cv::Mat

```cv::Mat connectComponents(cv::Mat image)```
   - Purpose of the function:
     - computes the connected components labeled image of boolean image
   - Parameter:
     - image: Input image
   - Returntype cv::Mat
   
```cv::Mat connectComponentsWithStats(cv::Mat image)```
   - Purpose of the function:
     - computes the connected components labeled image of boolean image and also produces a statistics output for each label
   - Parameter:
     - image: Input image
   - Returntype cv::Mat

   
### Selection sort
```std::vector<int> selectionSort(std::vector<int> numbers, int &stepCounter, int o = 1)```
   - Purpose of the function:
     - it sorts the vector's elements descending or ascending order based on the o's value.
   - Parameteres:
     - numbers: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - o: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the input
          numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted vector
   
```int* selectionSort(int array[], int size, int &stepCounter, int o = 1)```
   - Purpose of the function:
     - it sorts the array's elements descending or ascending order based on the o's value.
   - Parameteres:
     - array: array with numbers,
     - size: size of the array,
     - stepCounter: number of steps while the program does the sorting
     - o: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the input
          numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted array

### Insertion sort
```std::vector<int> insertionSort(std::vector<int> inputVector, int &stepCounter, int order = 1)```
   - Purpose of the function:
     - it sorts the array's elements descending or ascending order based on the order's value.
   - Parameteres:
     - inputArray: array with numbers,
     - size: size of the inputArray,
     - stepCounter: number of steps while the program does the sorting
     - order: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - Returntype the sorted array

```int* insertionSort(int* inputArray, int size, int &stepCounter, int order = 1)```
   - Purpose of the function:
     - it sorts the vector's elements descending or ascending order based on the order's value.
   - Parameteres:
     - inputVector: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - order: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - Returntype the sorted vector
   
### Quick sort
```int* quickSort(int* array, int low, int high, int &stepCounter, int mode = 1)```
  - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - array: array with numbers,
     - low: the first element of the array
     - high: the last element of the array
     - stepCounter: number of steps while the program does the sorting
     - mode: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - Returntype the sorted array
   
```std::vector<int> quickSort(std::vector<int> &vector, int low, int high, int &stepCounter, int mode = 1)```
   - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - vector: vector with numbers,
     - low: the first element of the vector
     - high: the last element of the vector
     - stepCounter: number of steps while the program does the sorting
     - mode: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - Returntype the sorted vector
   
### Bubble sort
```std::vector<int> bubbleSort(std::vector<int> a, int &stepCounter, int n = 1)```
   - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - a: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - n: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted vector
   
```int* bubbleSort(int arr[], int size, int &stepCounter, int n = 1)```
   - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - arr[]: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - n: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted array
   
### Merge sort

   - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - : vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - : an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted vector
   
   - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - : vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - : an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted array
   
### Heap sort
   
   - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - : vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - : an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted vector
   
   - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - arr[]: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - n: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted array
   
### Shell sort

   - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - : vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - : an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted vector
   
   - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - parameteres:
     - : vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - : an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted array
   
### Shaker sort
```std::vector<int> shakerSort(std::vector<int> vector, int &stepCounter, int mode = 1)```
   - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - vector: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - mode: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted vector

```int* shakerSort(int* array, int size, int &stepCounter, int mode = 1)``` 
   - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - Parameteres:
     - array: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - mode: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - Returntype the sorted array
   
### Histogram
```cv::Mat histogram(cv::Mat input)```
  - Purpose of the function:
    - create histogram based on an input image
  - Parameter:
    - input: input image
  - Returntype: cv:: Mat