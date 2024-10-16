#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "building.jpg", IMREAD_COLOR);
    Mat dst1, dst2, ori, temp;
    int cannyParam;

    ori = src.clone();
    cvtColor(src, src, COLOR_BGR2GRAY);

    namedWindow("dst1");
    namedWindow("src");
    createTrackbar("cannyParam", "dst1", &cannyParam, 200);

    while(1)
    {
        Canny(src, dst1, cannyParam, 100);
        vector<Vec4i> lines;
        HoughLinesP(dst1, lines, 1, CV_PI/180.0, 160, 50, 5);
        
        Point pt1, pt2;
        temp = ori.clone();
        for(auto lineP:lines){
            pt1.x = lineP[0];
            pt1.y = lineP[1];
            pt2.x = lineP[2];
            pt2.y = lineP[3];
            
            line(temp, pt1, pt2, Scalar(0, 0, 255), 2);
        }
        cout << cannyParam << endl;
        imshow("src", temp);
        imshow("dst1", dst1);
        
        if(waitKey(33) == 27){
            break;
        }
    }
    return 0;
}
