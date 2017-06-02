//Run with bug3487_source.cpp
//Notice, you must pust the image in the correct path

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

/*
static void findContours(cv::Mat image, List<MatOfPoint> contours, cv::Mat hierarchy, int mode, int method) 
{
    cv::Mat contours_mat = new cv::Mat();
    cv::findContours_1(image.nativeObj, contours_mat.nativeObj, hierarchy.nativeObj, mode, method);
    cv::Converters.Mat_to_vector_vector_Point(contours_mat, contours);
    *contours_mat.release();* 
    return;
}*/

int main(int argc, const char * argv[]) {

    cv::Mat image= cv::imread("image.jpg");
    //Prepare the image for findContours
    cv::cvtColor(image, image, CV_BGR2GRAY);
    cv::threshold(image, image, 128, 255, CV_THRESH_BINARY);

    //Find the contours. Use the contourOutput Mat so the original image doesn't get overwritten
    std::vector<std::vector<cv::Point> > contours;
    cv::Mat contourOutput = image.clone();
    cv::findContours( contourOutput, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE );


    return 0;
}
