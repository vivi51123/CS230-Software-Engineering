g++ -I/usr/local/Cellar/opencv3/3.2.0/include/opencv -I/usr/local/Cellar/opencv3/3.2.0/include -L/usr/local/Cellar/opencv3/3.2.0/lib -g -o bug3961 bug3961_main.cpp -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core