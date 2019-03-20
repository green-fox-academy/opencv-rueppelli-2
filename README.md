
# *opencv-rueppelli-2*
<p>made by Andrea Rapp, Fanni Takacs, Mark Toth and Zsuzsanna Franko</p>

 This is a software being developed by students of **GFA** in the project phase. 
 Its aim is to be able detect numbers on traffic signboards accurately. 

 It is written in *C++* and uses the *openCV* library for picture processing.
 
 It can detect circles on any given image after turning it into grayscale. We get the number of circles thetected, their area and the central coordinates .
 
 ![Alt Text](Opencv-VS/img/featuresguide05.jpg)
 
 
 The number of circles detected on a picture and the time in which it was processed are saved into an *SQLite* database.
 
  ![Alt Text](Opencv-VS/img/featuresguide02.jpg)
  
 
 We mask the features to a blank image, so later on we will be able to operate only with the detected circles.

![Alt Text](Opencv-VS/img/featuresguide04.jpg)


We can use various filters on our for more accurate detection (for ex., blurring, thresholding, binarizing, normalizing, sharpening). 
We can check the tonal distribution for any digital image with a histogram.

![Alt Text](Opencv-VS/img/featuresguide06.jpg)

 
 We unit test the software with *googletest*.

<h2> INSTALLATION AND SETUP </h2>

 Things you will need:

 - [Visual Studio 2017](https://visualstudio.microsoft.com/downloads/)
 - [CMake](https://github.com/Kitware/CMake/releases/download/v3.14.0-rc1/cmake-3.14.0-rc1-win64-x64.msi)
 - [VCPKG](https://github.com/Microsoft/vcpkg)
 - [OpenCV 4.0.1](https://drive.google.com/open?id=11OIT6GlLsg0z8G8tLzs674nv5BZdKgfq)
 
 Intall Visual Studio 2017 and the Microsoft Visual c++ toolset with the installer.
 
 Install CMake and add it to your PATH environment variable.
 
 Start the InstallOCV.sh, it will automatically download the latest version of OpenCV with the extra modules and builds the binaries for you.
 
 Create the OPENCV_DIR environment variable and set it to the vc15 folder. (%the folder where installOCV.sh is located%\install\x64\vc15)
 
In Visual Studio, on the property pages of your project set the following properties: C++ -> General -> Additional    include libraries -> `$(OPENCV_DIR)\..\..\include`, Linker -> General -> Additional library directories -> `  $(OPENCV_DIR)\lib`, Linker -> Input -> Additional Dependencies ->  `opencv_world401d.lib;opencv_world401.lib;ws2_32.lib;`
 
 Clone the VCPKG repo and follow the instructions to install it. (`bootstrap-vcpkg.bat` and `vcpkg integrate install`)
 
 Install Sqlite3, gtest and Tesseract with the following command with VCPKG: `vcpkg install sqlite3:x64-windows`, `vcpkg install tesseract:x64-windows` and `vcpkg install gtest:x64-windows`
 
 Known issue: on some machines, Visual Studio can't find the `opencv-world401.dll`, in that case, copy the file from the OpenCV install folder to the folder of the built executable
 