#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "building.jpg", IMREAD_GRAYSCALE);

    // vector<KeyPoint> keypoint;
    // FAST(src, keypoint, 60, true);
    vector<Point2f> keypoint;
    goodFeaturesToTrack(src, keypoint, 100, 0.01, 10);
    cout << keypoint.size() << endl;
    // for(auto keypoint : keypoint)
    // {
    //     Point pt(keypoint.pt.x, keypoint.pt.y);
    //     circle(src, pt, 10, Scalar(0), -1);
    // }
    for(auto pta : keypoint)
    {
        Point pt(pta.x, pta.y);
        circle(src, pt, 10, Scalar(0), -1);
    }


    imshow("src", src);

    waitKey(0);
    return 0;
}
