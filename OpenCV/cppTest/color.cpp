#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    Mat src = imread(folder + "butterfly.jpg", IMREAD_COLOR);
    
    Vec3b &pixel = src.at<Vec3b>(0, 0);
    cout << pixel[0] << " " << pixel[1] << " " << pixel[2] << " " << endl;
    imshow("img", src);

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            Vec3b &pixel = src.at<Vec3b>(i, j);
            pixel[0] = i;
            pixel[1] = j;
            pixel[2] = 0;
        }
    }
    imshow("img2", src);
    waitKey(0);


    return 0;
}
