#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "tekapo.bmp", IMREAD_GRAYSCALE);
    Mat dst, dst2;
    Point2f srcPts[3], dstPts[3];
    srcPts[0] = Point2f(0, 0);
    srcPts[1] = Point2f(src.cols - 1, 0);
    srcPts[2] = Point2f(src.cols - 1, src.rows - 1);

    dstPts[0] = Point2f(src.cols/2, 0);
    dstPts[1] = Point2f(src.cols - 50, 0);
    dstPts[2] = Point2f(src.cols - 1, src.rows - 1);

    Point2d cp(src.cols/2, src.rows/2);
    Mat M2 = getRotationMatrix2D(cp, 30, 0.6);
    warpAffine(src, dst2, M2, Size());

    Mat M =getAffineTransform(srcPts, dstPts);
    warpAffine(src, dst, M, Size());

    imshow("src", src);
    imshow("dst1", dst);
    imshow("dst2", dst2);
    
    waitKey(0);
    return 0;
}
