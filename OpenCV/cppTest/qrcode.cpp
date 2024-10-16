#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "frame.png");
    
    QRCodeDetector detector;
    
    vector<Point> points;

    String info = detector.detectAndDecode(src, points);

    if(!info.empty()){
    polylines(src, points, true, Scalar(0, 0, 255), 2);
    cout << info << endl;    
    }
    imshow("src", src);
    
    
    waitKey(0);
    return 0;
}
