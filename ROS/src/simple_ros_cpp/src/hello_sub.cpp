#include "simple_ros_cpp/hello_pub_class.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class HelloSubscriber : public rclcpp::Node{
    public:
        HelloSubscriber()
            : Node("hello_sub")
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
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
        void sub_callback(const std_msgs::msg::String::SharedPtr msg){
            // cout << msg -> data << endl;
            RCLCPP_INFO(this -> get_logger(), msg -> data.c_str());
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
