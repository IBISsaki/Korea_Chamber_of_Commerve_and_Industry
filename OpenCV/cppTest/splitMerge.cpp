#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "candies.png");
    Mat emptyM(src.rows, src.cols, CV_8UC1, Scalar(0));
    
    vector<Mat> bgr, b_planes;
    split(src, bgr);
    b_planes = {bgr[0], emptyM, emptyM};
    Mat bsrc;
    merge(b_planes, bsrc);
    
    imshow("src", src);
    int i = 0;
    for(auto img : bgr){
        imshow("bgr" + to_string(i), img);
        i++;
    }
    imshow("bsrc", bsrc);

    waitKey(0);
    return 0;
}
