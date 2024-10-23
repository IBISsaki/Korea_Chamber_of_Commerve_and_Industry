// #include <random.hpp>
#include "rclcpp/rclcpp.hpp"
#include "user_interface/srv/add_and_odd.hpp"
#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono_literals;

class Serviceclient : public rclcpp::Node{
public:
    Serviceclient()
        : Node("service_client")
    {
        // random_device rd;
        // mt19937 gen(rd());
        // uniform_int_distribution<int> dis(5, 20);
        client_ = create_client<user_interface::srv::AddAndOdd>("AddAndOdd");

        while (!client_ -> wait_for_service(1s))
        {
            RCLCPP_INFO(get_logger(), "service not available");
        }
        request_ = std::make_shared<user_interface::srv::AddAndOdd::Request>();
        send_timer_ = create_wall_timer(3s, std::bind(&Serviceclient::send_request, this));
        update_timer_ = create_wall_timer(500ms, std::bind(&Serviceclient::update, this));
    }

private:
    typedef std::shared_ptr<user_interface::srv::AddAndOdd::Request> BRequest;
    typedef std::shared_ptr<user_interface::srv::AddAndOdd::Response> BResponse;
    rclcpp::Client<user_interface::srv::AddAndOdd>::SharedPtr client_;
    std::shared_ptr<user_interface::srv::AddAndOdd::Request> request_;
    rclcpp::TimerBase::SharedPtr send_timer_;
    rclcpp::TimerBase::SharedPtr update_timer_;
    std::random_device rd;
    bool bool_;

    void send_request()
    {
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dis(5, 20);
        request_ -> inta = dis(gen);
        request_ -> intb = dis(gen);

        auto future = client_ -> async_send_request(request_, std::bind(&Serviceclient::done_callback, 
                                                                            this, std::placeholders::_1));
    }
    
    void done_callback(rclcpp::Client<user_interface::srv::AddAndOdd>::SharedFuture future)
    {
        auto response = future.get();
        RCLCPP_INFO(get_logger(), "%d", response -> stamp.sec);
        RCLCPP_INFO(get_logger(), "%d", response -> stamp.nanosec);
        RCLCPP_INFO(get_logger(), "%d", response -> sum);
        RCLCPP_INFO(get_logger(), response -> odd.c_str());
    }

    void update()
    {
        RCLCPP_INFO(get_logger(), "updating now!!!");
    }
};


int main()
{
    rclcpp::init(0, nullptr);
    auto node = make_shared<Serviceclient>();    // C++ 코드
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}
