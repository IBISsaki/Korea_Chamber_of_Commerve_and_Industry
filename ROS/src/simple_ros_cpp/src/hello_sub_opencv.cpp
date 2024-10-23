#include "opencv2/opencv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;
using namespace cv;

class HelloSubscriber : public rclcpp::Node{
    public:
        HelloSubscriber()
            : Node("hello_sub"), img_(500, 500, CV_8UC1, Scalar(255))
        {
            sub_ = this -> create_subscription<std_msgs::msg::String>(
                "message", 
                10, 
                bind(&HelloSubscriber::sub_callback, 
                    this, 
                    placeholders::_1));
        }

    private:
        int count_;
        Mat img_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
        void sub_callback(const std_msgs::msg::String::SharedPtr msg){
            RCLCPP_INFO(this -> get_logger(), msg -> data.c_str());
            img_ = Scalar(255);
            putText(img_, msg -> data.c_str(), Point(50, 50), FONT_HERSHEY_PLAIN, 1, Scalar(0), 2);
            imshow("img", img_);
            waitKey(30);
        }
};


int main()
{
    rclcpp::init(0, nullptr);
    auto node = make_shared<HelloSubscriber>();    // C++ 코드
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}
