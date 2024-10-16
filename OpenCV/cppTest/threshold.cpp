#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "sudoku.jpg", IMREAD_GRAYSCALE);
    Mat dst1, dst2, dst3;
    threshold(src, dst1, 0, 255, THRESH_OTSU);
    threshold(src, dst2, 60, 255, THRESH_BINARY);
    adaptiveThreshold(src, dst3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 71, 5);

    Mat erodeMat, dilateMat;
    erode(dst3, erodeMat, Mat());
    dilate(dst3, dilateMat, Mat());

    Mat openMat, closeMat;
    morphologyEx(dst3, openMat, MORPH_OPEN, Mat());
    morphologyEx(dst3, closeMat, MORPH_CLOSE, Mat());

    imshow("src", src);
    // imshow("dst1", dst1);
    // imshow("dst2", dst2);
    imshow("dst3", dst3);
    imshow("erodeM", erodeMat);
    imshow("dilateM", dilateMat);
    imshow("openMat", openMat);
    imshow("closeMat", closeMat);

    waitKey(0);
    return 0;
}
