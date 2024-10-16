#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";

int main()
{
    // Mat src = imread(folder + "tkfka.jpg");
    VideoCapture cap(folder + "vtest.avi");
    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    while (1)
    {
        Mat src;
        cap >> src;
        vector<Rect> detected;
        hog.detectMultiScale(src, detected);
        for(auto d : detected){
            rectangle(src, d, Scalar(0, 0, 255), 3);
        }
        imshow("src", src);
        if (waitKey(100) == 27)
            {break;}
    }
    
    
    
    
    

    


    // waitKey(0);
    return 0;
}
