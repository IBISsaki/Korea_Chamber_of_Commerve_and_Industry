#include "rclcpp/rclcpp.hpp"
#include "rcutils/cmdline_parser.h"
#include "user_interface/msg/arithmetic_argument.hpp"
#include <cstdio>
#include <random>
#include <utility>

using namespace std;
using namespace std::chrono_literals;

class Argument : public rclcpp::Node{
    public:
        explicit Argument(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions());

    private:
        int count_;
        rclcpp::Publisher<user_interface::msg::ArithmeticArgument>::SharedPtr pub_;
        rclcpp::TimerBase::SharedPtr timer_;
        void pub_callback();
};

Argument::Argument(const rclcpp::NodeOptions & node_options)
: Node("argument", node_options)// , min_random_num_(0.0), max_random_num_(0.0)
{
    pub_ = this -> create_publisher<user_interface::msg::ArithmeticArgument>("argument", 10);
    timer_ = this -> create_wall_timer(1s, bind(&Argument::pub_callback, this));
}

void Argument::pub_callback()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0, 100);
    user_interface::msg::ArithmeticArgument msg;
    msg.stamp = now();
    msg.argument_a = dis(gen);
    msg.argument_b = dis(gen);
    pub_ -> publish(msg);
}

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
    auto node = make_shared<Argument>();    // C++ 코드
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}