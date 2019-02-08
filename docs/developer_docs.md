# *opencv-rueppelli-2*

## developer documentation

[detect circle](#detectCircle)

[remove background](#remove background) 

[sortings](#sortings)

### detect circle

int detectCircle(cv::Mat &image)
   - input is an image, 
   - returntype a number of found circles on the input image

### remove background

- cv:: Mat removeLightWithDifference(cv:: Mat image, cv:: Mat pattern)
   - What does this program do?
     - to extract the image from pattern
   - Parameters
     - image: Input image
     - pattern: Input image with pattern
   - returntype a new image
   
- cv:: Mat removeLightWithDivision(cv:: Mat image, cv:: Mat pattern)
   - What does this program do?
     - to device the pattern with the image
   - Parameters
     - image: Input image
     - pattern: Input image with pattern
   - returntype a new image
   
- cv:: Mat removeLightWithBlur(cv:: Mat image)
   - What does this program do?
     - remove light with blur
   - Parameters
     - image: Input image
   - returntype a new image
   
- cv::Mat binarizeImage(cv::Mat image)
   - What does this program do?
     - 
   - Parameters
     - image: Input image
   - returntype a new image
   
- cv::Mat binarizeImageInverse(cv::Mat image)
   - What does this program do?
     - 
   - Parameters
     - image: Input image
   - returntype a new image

- cv::Mat connectComponents(cv::Mat image);
   - What does this program do?
     -
   - Parameters
     - image: Input image
   - returntype a new image

   
### Sortings
#### Selection sort
- std::vector<int> selectionSort(std::vector<int> numbers, int &stepCounter, int o = 1);
   - Purpose of the function:
     - it sorts the vector's elements descending or ascending order based on the o's value.
   - parameteres:
     - numbers: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - o: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the input
          numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted vector
   
- int* selectionSort(int array[], int size, int &stepCounter, int o = 1);
   - Purpose of the function:
     - it sorts the array's elements descending or ascending order based on the o's value.
   - parameteres:
     - array: array with numbers,
     - size: size of the array,
     - stepCounter: number of steps while the program does the sorting
     - o: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the input
          numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted array

#### Insertion sort
- std::vector<int> insertionSort(std::vector<int> inputVector, int &stepCounter, int order = 1);
   - Purpose of the function:
     - it sorts the array's elements descending or ascending order based on the order's value.
   - parameteres:
     - inputArray: array with numbers,
     - size: size of the inputArray,
     - stepCounter: number of steps while the program does the sorting
     - order: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - returntype the sorted array

- int* insertionSort(int* inputArray, int size, int &stepCounter, int order = 1);
   - Purpose of the function:
     - it sorts the vector's elements descending or ascending order based on the order's value.
   - parameteres:
     - inputVector: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - order: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - returntype the sorted vector
   
#### Quick sort
- int* quickSort(int* array, int low, int high, int &stepCounter, int mode = 1);
  - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - parameteres:
     - array: array with numbers,
     - low: the first element of the array
     - high: the last element of the array
     - stepCounter: number of steps while the program does the sorting
     - mode: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - returntype the sorted array
   
- std::vector<int> quickSort(std::vector<int> &vector, int low, int high, int &stepCounter, int mode = 1);
  - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - parameteres:
     - vector: vector with numbers,
     - low: the first element of the vector
     - high: the last element of the vector
     - stepCounter: number of steps while the program does the sorting
     - mode: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
              input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing
              order.
   - returntype the sorted vector
   
#### Bubble sort
- std::vector<int> bubbleSort(std::vector<int> a, int &stepCounter, int n = 1);
  - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - parameteres:
     - a: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - n: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted vector
   
- int* bubbleSort(int arr[], int size, int &stepCounter, int n = 1);
  - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - parameteres:
     - arr[]: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - n: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted array
   
 #### functions in main
 - void gaussian(int, void *)
 - void median(int, void *)
 - void trackbar()
 
 