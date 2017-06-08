build.sh will compile the minarea.cpp file including the required OpenCV files.  
Simply run: ./build.sh to compile the minarea.cpp file
There are currently lines of code in the minarea.cpp file that have been inserted to inject a memleak.
once compiled, run: ./minarea to run the code.

OpenCV
  Version history search engine: http://code.opencv.org/projects/opencv/issues
  Version history: Kunal's export pdf
  Download Specific Version: http://opencv.org/releases.html
  
  //Instructions on running bug#_main.cpp and bug#_source.cpp (example: bug 3847)
  bug3847_main.cpp is the one that you will run on your device, it calls a function in the API named cv::findContours. The API function cv::findContours is located in the file (path)/src/main/java/org/opencv/imgproc/Imgproc.java. The bug3847_source.cpp is basically the same as the Imgproc.java file. Since this is a bug that was reported by developers on OpenCV forum, in an earlier version of that file, the program without line 13 was supposed to create problem, so we can add that line back to see if it actually fixes the problem.

  //Problem
  As Greg mentioned, modifying that line in the API didn't change anything. It might be an issue that when we run main.cpp, the API isn't being compiled everytime. But Greg also mentioned that Imgproc.java has a note that says "this is an automated generated file, do not modify". So I suggest leaving this bug out for now, and I will keep looking for other bugs and find the correct environment to recompile API source code. 
  
  Done/New issues with "memory" issues running Linux or MacOSX
 | Bug#    | OS     | Affected Version  | Tested on Valgrind? | Note
   3847      Linux    2.4.9               Yes                   Classes that create new Mat should Mat.release() else memory leaks
   3961      Linux    2.4.9               No                    Memory leak in cv::viz::WImage3D::setImage()   
   4489      Linux    2.4.11              Yes                   Possible memory leak in cvtColor with TBB support
   4250      MacOSX   2.4.9               No                    Memory leak on LKDEMO.cpp

---------------------------------------------------------------------------------------------------------------------------------------
   3263      Linux    2.4.6               Yes                   CvKnearest::find_nearest memory leak
   3085               2.4.5               No                    a memory bug in mlann_mlp.cpp
   1734               2.4.0               No                    Out of bounds memory access in Brox optical flow
   1663               2.4.0               No                    cppcheck: objdetect/src/matching.cpp, memory leaks
