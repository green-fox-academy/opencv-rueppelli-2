# *opencv-rueppelli-2*

## developer documentation

[detect circle](detectCircle)

[GaussianBlur](GaussianBlur)

[HoughCircles](HoughCircles)

[remove background](remove background)

### detect circle

int detectCircle(&image)
   - input is an image, 
   - returntype a number of found circles on the input image

   - void cv::GaussianBlur	(	InputArray src, OutputArray dst, Size ksize, double sigmaX, double 	sigmaY = 0, 
                              int	borderType =  BORDER_DEFAULT)
     - What does this program do?
         - Blurs an image using a Gaussian filter.
         - The function convolves the source image with the specified Gaussian kernel. In-place filtering is supported.
     - Parameters
         - src	input image; the image can have any number of channels, which are processed independently, but the depth should be
           CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
         - dst	output image of the same size and type as src.
         - ksize	Gaussian kernel size. ksize.width and ksize.height can differ but they both must be positive and odd. Or, they can be
           zero's and then they are computed from sigma.
         - sigmaX	Gaussian kernel standard deviation in X direction.
         - sigmaY	Gaussian kernel standard deviation in Y direction; if sigmaY is zero, it is set to be equal to sigmaX, if both sigmas
           are zeros, they are computed from ksize.width and ksize.height, respectively (see cv::getGaussianKernel for details); 
           to fully control the result regardless of possible future modifications of all this semantics, it is recommended to specify 
           all of ksize, sigmaX, and sigmaY.
         - borderType	pixel extrapolation method, see cv::BorderTypes

   - HoughCircles (image, circles, method, dp, minDist, param1 = 100, param2 = 100, minRadius = 0, maxRadius = 0)
     - What does this program do?
       - Loads an image and blur it to reduce the noise
       - Applies the Hough Circle Transform to the blurred image .
       - Display the detected circle in a window.

     - Parameters
       - image: Input image (grayscale)
       - circles: A vector that stores sets of 3 values: x_{c}, y_{c}, r for each detected circle.
       - method: Define the detection method. Currently this is the only one available in OpenCV.
       - dp = 1: The inverse ratio of resolution.
       - minDist = src_gray.rows/8: Minimum distance between detected centers.
       - param1 = 200: Upper threshold for the internal Canny edge detector.
       - param2 = 100*: Threshold for center detection.
       - minRadius = 0: Minimum radio to be detected. If unknown, put zero as default.
       - maxRadius = 0: Maximum radius to be detected. If unknown, put zero as default.

### remove background

- removeLightWithDifference(image, pattern)
   - What does this program do?
     - to extract the image from pattern
   - Parameters
     - image: Input image
     - pattern: Input image with pattern
   - returntype a new image
   
- removeLightWithDivision(image, pattern)
   - What does this program do?
     - to device the pattern with the image
   - Parameters
     - image: Input image
     - pattern: Input image with pattern
   - returntype a new image
   
- removeLightWithBlur(image)
   - What does this program do?
     - remove light with blur
   - Parameters
     - image: Input image
   - returntype a new image
   
### Sorts
#### Selection sort
- selectionSort(numbers, &stepCounter, o)
   - Purpose of the function:
     - it sorts the vector's elements descending or ascending order based on the o's value.
   - parameteres:
     - numbers: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - o: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the input
          numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted vector
   
- selectionSort(array[], size, &stepCounter, o)
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
- insertionSort(* inputArray, size, &stepCounter, order)
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

- insertionSort( inputVector, int &stepCounter, int order)
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
- quickSort(* array, low, high, &stepCounter, mode)
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
   
- quickSort(&vector, low, high, &stepCounter, mode)
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
- bubbleSort(a, &stepCounter, n)
  - Purpose of the function:
    - it sorts the vector's elements descending or ascending order based on the mode's value.
   - parameteres:
     - a: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - n: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted vector
   
- bubbleSort(arr[], size, &stepCounter, n)
  - Purpose of the function:
    - it sorts the array's elements descending or ascending order based on the mode's value.
   - parameteres:
     - arr[]: vector with numbers,
     - stepCounter: number of steps while the program does the sorting
     - n: an integer, if that integer is 0 it should sort the input numbers in descending order and if it is 1 it should sort the
          input numbers in increasing order. If the second parameter is not provided it should sort the given list is increasing order.
   - returntype the sorted array