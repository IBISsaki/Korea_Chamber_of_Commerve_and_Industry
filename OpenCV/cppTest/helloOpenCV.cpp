#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

int main()
{
    cv::Mat img;
    std::cout << img.empty() << std::endl;
    img = cv::imread("lenna.bmp");
    if (img.empty())
    {
        std::cout << "이미지 없음" << std::endl;
        return -1;
    }

    std::string windowName = "image";
    cv::String windowName2 = "image2";

    cv::imshow("image", img);
    std::cout << "Hello OpenCV" << std::endl;
    cv::imwrite("lenna.jpg", img);
    int Key;
    // cv::waitKey(0);
    while(Key != 'x'){
        Key = cv::waitKey(0);
        std::cout << Key << std::endl;
    }   

    return 0;
}