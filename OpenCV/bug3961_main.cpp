//http://code.opencv.org/issues/3961
//Repeatedly calling setImage on a WImage3D widget seems to take a copy of the image data each time. 
//If this function is called in a loop, we get a memory leak.
//By the end of the loop, 3GB of memory is required by the application.

//Set up
//- OpenCV 2.4.9 (built from source)
//- Ubuntu 12.04 x64 
//- CMake 2.8.12 (built from source)
//- Qt 5.3.1 (x64 binary package)
//- VTK 6.1.0 (built from source against the same Qt version)

//Please refer to bug3961_source.cpp for the source code, changing things there cause memory leaks.

#include <opencv2/opencv.hpp>
#include <opencv2/viz/vizcore.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    cv::Mat image = cv::Mat::zeros(1024,1024, CV_8UC3);
    cv::viz::WImage3D imageWidget(image, cv::Size(1.0,1.0));

    for(int i = 0; i < 1E3; ++i)
    {
        imageWidget.setImage(image);
    }

    std::cout << "Press <RETURN> to exit...";
    std::cin.get();

    return 0;
}