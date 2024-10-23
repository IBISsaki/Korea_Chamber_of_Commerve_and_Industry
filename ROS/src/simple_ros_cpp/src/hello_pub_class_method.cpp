#include "simple_ros_cpp/hello_pub_class.hpp"

HelloPublisher::HelloPublisher()
    : Node("hello"), count_(0)
{
    pub_ = this -> create_publisher<std_msgs::msg::String>("message", 10);
    timer_ = this -> create_wall_timer(1s, bind(&HelloPublisher::print_Hello, this));
}

void HelloPublisher::print_Hello()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello, World!!!!!" + to_string(count_);
    pub_ -> publish(msg);
    // cout << "Hello, World!!!!!" << count_ << endl;
    RCLCPP_INFO(this -> get_logger(), msg.data.c_str());
    count_++;
}
