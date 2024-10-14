#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
int main()
{
    String path = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data";
    Mat img1;
    img1 = imread(path + "/dog.bmp");
    Mat img2 = img1;
    Mat img3 = img1;

    Mat img4 = img1.clone();
    Mat img5;
    img1.copyTo(img5);

    img1.setTo(Scalar(0, 255, 255));

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);

    waitKey(0);
    return 0;
}