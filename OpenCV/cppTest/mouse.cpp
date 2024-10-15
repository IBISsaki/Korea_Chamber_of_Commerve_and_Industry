#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

void onMouse(int event, int x, int y, int flags, void *data);

int main()
{
    Mat src = imread(folder + "lenna.bmp", IMREAD_COLOR);
    namedWindow("img");
    setMouseCallback("img", onMouse, ((void*)&src));

    imshow("img", src);
    waitKey(0);

    return 0;
}

void onMouse(int event, int x, int y, int flags, void *data)
{
    Mat *src = (Mat *)data;
    Mat temp;
    temp = (*src).clone();
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        cout << x << y << endl;
        circle(*src, Point(x, y), 10, Scalar(255, 0, 0), -1);
        imshow("img", *src);
        break;
    case EVENT_MOUSEMOVE:
        rectangle(temp, Rect(x, y, 50, 50), Scalar(0, 0, 255), 5);
        imshow("img", temp);
        break;

    default:
        break;
    }
}