#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
using namespace cv::ml;

String folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/";
Ptr<KNearest> train_knn();

int main()
{
    Ptr<KNearest> knn = train_knn();

    Mat src = imread(folder + "box.png", IMREAD_GRAYSCALE);
    Mat img = Mat::zeros(400, 400, CV_8U);




    imshow("img", img);

    waitKey(0);
    return 0;
}

Ptr<KNearest> train_knn()
{
    Mat digits = imread(folder + "digits.png", IMREAD_GRAYSCALE);
    Mat train_images, train_labels;

    for(int j = 0; j < 50; j++)
    {
        for(int i = 0; i < 100; i++)
        {
            Mat roi, roi_float, roi_flatten;
            roi = digits(Rect(i * 20, j * 20, 20, 20));
            roi.convertTo(roi_float, CV_32F);
            roi_flatten = roi_float.reshape(-1, 1);

            train_images.push_back(roi_flatten);
            train_labels.push_back(j / 5);
        }
    }

    Ptr<KNearest> knn = KNearest::create();
    knn -> train(train_images, ROW_SAMPLE, train_labels);
    return knn;
}