#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "candies.png", IMREAD_COLOR);
    int lowerHue = 140, upperHue = 180;
    
    imshow("src", src);

    cvtColor(src, src, COLOR_BGR2HSV);

    Mat dst;
    inRange(src, Scalar(lowerHue, 50, 0), Scalar(upperHue, 255, 255), dst);
    imshow("dst", dst);

    waitKey(0);
    return 0;
}
