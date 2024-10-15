#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";
int main()
{
    Mat src = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
    Mat brightSrc, saturateSrc;
    brightSrc = src.clone();
    saturateSrc = src.clone();

    for(auto it = brightSrc.begin<uchar>(); it != brightSrc.end<uchar>(); it++){
        *it = *it + 100;
    }

    for(auto it = saturateSrc.begin<uchar>(); it != saturateSrc.end<uchar>(); it++){
        *it = saturate_cast<uchar>(*it + 100);
    }
    Mat addImage;
    // addImage = src + 100;
    add(src, 100, addImage);

    imshow("src", src);
    imshow("brightSrc", brightSrc);
    imshow("saturateSrc", saturateSrc);
    imshow("addimage", addImage);
    waitKey(0);

    return 0;
}