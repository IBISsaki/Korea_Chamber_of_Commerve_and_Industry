#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "rose.bmp", IMREAD_GRAYSCALE);

    Mat dst;
    int sigma = 3;
    GaussianBlur(src, dst, Size(0, 0), sigma);



    imshow("src", src);
    imshow("dst", dst);
    

    waitKey(0);
    return 0;
}
