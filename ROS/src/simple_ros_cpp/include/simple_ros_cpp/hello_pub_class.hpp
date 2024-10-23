#ifndef __HELLO_PUB_CLASS_HPP__

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class HelloPublisher : public rclcpp::Node{
    public:
        HelloPublisher();

    private:
        int count_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
        rclcpp::TimerBase::SharedPtr timer_;
        void print_Hello();
};

#endif