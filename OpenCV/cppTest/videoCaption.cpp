#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
int main()
{
    // String pipeline = "v4l2src device=/dev/video0 ! video/x-raw, width=1280, height=720, framerate=30/1 ! videoconvert ! appsink";
    // VideoCapture cap(pipeline, CAP_GSTREAMER);
    // VideoCapture cap(0);
    String folder = "/home/aa/aiot_2024_robot/OpenCV/cppTest/data/";
    VideoCapture cap(folder + "vtest.avi");
    Mat frame;

    if(!cap.isOpened())
    {
        cerr << "비디오 오픈 실패\n";
        return -1;
    }

    int delay = 100;
    while (true)
    {
        cap >> frame;
        imshow("frame", frame);
        if (waitKey(delay) == 27) {
            break;
        }
    }
    cap.release();
    destroyAllWindows();
    return 0;
}