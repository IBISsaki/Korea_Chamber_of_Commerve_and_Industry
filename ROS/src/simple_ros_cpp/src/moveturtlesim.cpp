#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/color.hpp"
#include "turtlesim/msg/pose.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class MoveTurtle : public rclcpp::Node{
    public:
        MoveTurtle()
            : Node("hello_sub")
        {
            auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10))
                                .reliability(RMW_QOS_POLICY_RELIABILITY_RELIABLE)
                                .durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);
            pose_sub_ = create_subscription<turtlesim::msg::Pose>(
                "turtle1/pose", 
                qos_profile, 
                bind(&MoveTurtle::pose_sub_callback, 
                    this, 
                    placeholders::_1));
            color_sub_ = create_subscription<turtlesim::msg::Color>(
                "turtle1/color", 
                qos_profile, 
                bind(&MoveTurtle::color_sub_callback, 
                    this, 
                    placeholders::_1));
            pub_ = create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
            twist_pub_timer_ = create_wall_timer(100ms, bind(&MoveTurtle::twist_pub, this));
            // update_timer_ = create_wall_timer(chrono::milliseconds(17),....);
            update_timer_ = create_wall_timer(17ms, bind(&MoveTurtle::update, this));
        }

    private:
        int count_;
        turtlesim::msg::Pose pose_;
        turtlesim::msg::Color color_;
        geometry_msgs::msg::Twist twist_;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub_;
        rclcpp::Subscription<turtlesim::msg::Color>::SharedPtr color_sub_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
        rclcpp::TimerBase::SharedPtr twist_pub_timer_;
        rclcpp::TimerBase::SharedPtr update_timer_;
        void pose_sub_callback(const turtlesim::msg::Pose::SharedPtr msg)
        {
            pose_ = *msg;
        }
        void color_sub_callback(const turtlesim::msg::Color::SharedPtr msg)
        {
            color_ = *msg;
        }
        void twist_pub()
        {
            pub_ -> publish(twist_);
        }
        void update()
        {
            twist_.linear.x += 0.002;
            twist_.angular.z = 1.0;
        }
};


int main()
{
    rclcpp::init(0, nullptr);
    auto node = make_shared<MoveTurtle>();    // C++ 코드
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}
