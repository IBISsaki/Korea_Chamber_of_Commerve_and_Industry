#include "rclcpp/rclcpp.hpp"
#include "rcutils/cmdline_parser.h"
#include "user_interface/msg/arithmetic_argument.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class Calculator : public rclcpp::Node{
public:
    Calculator(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
        : Node("calculator")
    {
        sub_ = this -> create_subscription<user_interface::msg::ArithmeticArgument>(
            "argument", 
            10, 
            bind(&Calculator::sub_callback, 
                this, 
                placeholders::_1));
    }

private:
    int count_;
    rclcpp::Subscription<user_interface::msg::ArithmeticArgument>::SharedPtr sub_;
    void sub_callback(const user_interface::msg::ArithmeticArgument::SharedPtr msg)
    {
        RCLCPP_INFO(get_logger(), "%ld, %ld", msg -> stamp.sec, msg -> stamp.nanosec);
        RCLCPP_INFO(get_logger(),  "%f", msg -> argument_a);
        RCLCPP_INFO(get_logger(),  "%f", msg -> argument_b);
    }
};

void print_help(){
    printf("for argument node: \n");
    printf("node name [-h]\n");
    printf("Option:\n");
    // printf("\t-h Help           : Print this help function.\n");
}

int main(int argc, char* argv[])
{
    if (rcutils_cli_option_exist(argv, argv + argc, "-h"))
    {
        print_help();
        return 0;
    }
    rclcpp::init(argc, argv);
    auto node = make_shared<Calculator>();    // C++ 코드
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}
