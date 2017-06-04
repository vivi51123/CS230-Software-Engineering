//http://code.opencv.org/issues/3847
//Fix: Line 13. This will deallocate native memory right away



Imgproc.findContours
@
    public static void findContours(Mat image, List<MatOfPoint> contours, Mat hierarchy, int mode, int method)
    {
        Mat contours_mat = new Mat();
        findContours_1(image.nativeObj, contours_mat.nativeObj, hierarchy.nativeObj, mode, method);
        Converters.Mat_to_vector_vector_Point(contours_mat, contours);
        // *contours_mat.release();* 
        return;
    }