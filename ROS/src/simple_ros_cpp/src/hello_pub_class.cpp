#include "simple_ros_cpp/hello_pub_class.hpp"

int main()
{
    rclcpp::init(0, nullptr);
    auto node = make_shared<HelloPublisher>();    // C++ 코드
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}
