#include <iostream>
#include <chrono>
#include <rclcpp/rclcpp.hpp>

using namespace std;
using namespace std::chrono_literals;

void print_Hello();

int main()
{
    rclcpp::init(0, nullptr);
    // node = Node("hello") 파이썬 코드
    auto node = make_shared<rclcpp::Node> ("hello");    // C++ 코드
    auto timer = node -> create_wall_timer(1s, print_Hello);
    rclcpp::spin(node);
    rclcpp::shutdown();
    

    return 0;
}

void print_Hello()
{
    static int count = 0 ;
    cout << "Hello, World!!!!!" << count << endl;
    count++;
}