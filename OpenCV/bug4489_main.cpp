//http://code.opencv.org/issues/4489

//This issue was never fixed but listed as suppressing errors
//Adding suppressing error in Valgrind.cpp: https://github.com/opencv/opencv/pull/6843/files
//Definition of suppressing errors: http://valgrind.org/docs/manual/manual-core.html#manual-core.suppress

//2.4.8 found no memory leaks on Valgrind
//2.4.11 found 12 errors as shown below
//LEAK SUMMARY:
//definitely lost: 0 bytes in 0 blocks
//indirectly lost: 0 bytes in 0 blocks
//possibly lost: 24,160 bytes in 60 blocks
//still reachable: 0 bytes in 0 blocks
//     suppressed: 0 bytes in 0 blocks
// 
//For counts of detected and suppressed errors, rerun with: -v
//ERROR SUMMARY: 12 errors from 12 contexts (suppressed: 0 from 0)

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    std::cout << cv::getBuildInformation() << std::endl;

    cv::Mat src = cv::Mat::zeros(5, 5, CV_8UC3);
    cv::Mat dst;

    //cv::cvtColor( src, dst, CV_BGR2GRAY );
}
