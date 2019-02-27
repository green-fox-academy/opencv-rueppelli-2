# *opencv-rueppelli-2*
<p>made by Andrea Rapp, Fanni Takacs, Mark Toth and Zsuzsanna Franko</p>

 This is a software being developed by students of **GFA** in the project phase. 

 It is written in *C++* and uses the *openCV* library for picture processing.
 
 It can detect circles on any given picture, we also get the area and the coordinates of the circles.
 We can modify the picture with gaussian or median blur for more accurate detection.
 
 ![Alt Text](img/featuresguide01.jpg)
 
 
 The number of circles detected on a picture and the time in which it was processed are saved into an *SQLite* database.
 
  ![Alt Text](img/featuresguide02.jpg)
 
 
 It has a few sorting functions based on sorting algorithms. Their usage is still being developed.
 
 We unit test the software with *googletest*.

*Our aim is to increase accuracy of image detection and to add useful features during the development.*

<h2> INSTALLATION AND SETUP </h2>

<h3> Requirements </h3> 

<li>JetBrainsCLion</li>
<li>CMake</li>
<li>MinGW-w64</li>
<li>Open CV library</li>
<li>SQLite</li>
<li>Google Test</li>

<h3> Installation </h3>

<h4> First of all you will need to download these goods: </h4>

<li> <a href="https://www.jetbrains.com/clion/download/download-thanks.html">CLion</a></li>
<li> <a href="https://github.com/Kitware/CMake/releases/download/v3.14.0-rc2/cmake-3.14.0-rc2.zip">CMake</a></li>
<li> <a href="https://bit.ly/2FOzQN5">MinGW-w64</a></li>
<li> <a href="https://dev.mysql.com/downloads/mysql/" rel="nofollow">MySQL Community Server</a></li>
<li> <a href="https://github.com/opencv/opencv/archive/4.0.1.zip">Open CV library 4.0.1.</a></li>
<li> <a href="https://github.com/green-fox-academy/teaching-materials/blob/master/workshop/testing/env-setup/cpp/resource/googletest.zip" rel="nofollow">Google Test</a></li>

<h4> Building Open CV: </h4>

<li> Once you have installed CLion, there are still quite a few things you need to do to properly setup and launch your Open CV library. </li>
<li> Let's continue the installation process with the *CMake*. </li>
<li> Unpacking everything else, like *MinGW-w64, Open CV, SQLite*. </li>
<li> Go directly to the folder where you unpacked *MinGW-w64*, looking for folder *bin*, copy the exact path of this folder. </li>
<li> Edit the *System Environment Variables*. On the *Advanced* layer choose the *Environment Variables* button". Add the new path to your list.</li>
<li> Restart your computer. </li>
<li> Run *Cmake*. </li>
<li> Tick *Grouped* and *Advanced*. </li>
<li> Click *Browse Scource* and go directly to the folder you unpacked your *Open CV library*. </li>
<li> Click *Browse Build* and define then browse a folder to locate your *Open CV library*. </li>
<li> Click *Configure* and specify the generator for this project, select *MinGW Makefiles*, tick *Use default native compilers*. </li>
<li> After the configure, select *CMAKE* from the red list, open the sub-list, choose *CMAKE_BUILD_TYPE*, set it to *Release*  </li>
<li> Select *ENAMBLE* from the red list, open the sub-list, untick *ENABLE PRECOMPILED HEADERS* </li>
<li> Select *WITH* from the red list, open the sub-list, untick *WITH IPP* and *WITH MSMF* that case if they were ticked. </li>
<li> Click *Configure* again to set the changes. </li>
<li> Click *Generate* after all. </li>

<li> Copy all the *DLL* files to the *cmake-build-debug* folder and the *gtest* folder found in *cmake-build-debug*. </li>


