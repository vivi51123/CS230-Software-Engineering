---------------------------------------------------------------------------------------------
Notepad++
  Version History: http://docs.notepad-plus-plus.org/index.php/Releases
  Download Specific Version: https://notepad-plus-plus.org/download/all-versions.html

  Most recent fixes on memory / memory leaks
  Version 6.4.1 -> Version 6.4.2
  Fix Find/Replace dialog status bar overwriting memory problem.

  Version 5.8.3 -> Version 5.8.4
  Fix memory leak problem while switching tab.

  Version 5.8.3
  Memory leaks were plugged

  Version 5.5.0 -> Version 5.5.1
  Fix some memory leaks.
---------------------------------------------------------------------------------------------
OpenCV
  Version history search engine: http://code.opencv.org/projects/opencv/issues
  Version history: Kunal's export pdf
  Download Specific Version: http://opencv.org/releases.html
  
  Done/New issues with "memory" issues running Linux or MacOSX
 | Bug#    | OS     | Affected Version  | Tested on Valgrind? | Note
   4489      Linux    2.4.11              Yes                   Possible memory leak in cvtColor with TBB support
   4250      MacOSX   2.4.9               No                    Memory leak on LKDEMO.cpp
   3961      Linux    2.4.9               No                    Memory leak in cv::viz::WImage3D::setImage()
   3847      Linux    2.4.9               Yes                   Classes that create new Mat should Mat.release() else memory leaks
   3263      Linux    2.4.6               Yes                   CvKnearest::find_nearest memory leak
   3085               2.4.5               No                    a memory bug in mlann_mlp.cpp
   1734               2.4.0               No                    Out of bounds memory access in Brox optical flow
   1663               2.4.0               No                    cppcheck: objdetect/src/matching.cpp, memory leaks
---------------------------------------------------------------------------------------------  
Firefox
  Download Specific Version: https://www.mozilla.org/en-US/firefox/releases/
  
  49.0 
  Improvements in about:memory reports for tracking font memory usage
  
  45.0
  Ability to filter snapshot output in memory tool
  
  44.0
  Introduce new memory tool for inspecting the memory heap
---------------------------------------------------------------------------------------------
