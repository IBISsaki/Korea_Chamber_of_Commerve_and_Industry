#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class Serviceclient : public rclcpp::Node{
public:
    Serviceclient()
        : Node("service_client")
    {
        client_ = create_client<std_srvs::srv::SetBool>("setBool");

        while (!client_ -> wait_for_service(1s))
        {
            RCLCPP_INFO(get_logger(), "service not available");
        }
        request_ = std::make_shared<std_srvs::srv::SetBool::Request>();
        send_timer_ = create_wall_timer(3s, std::bind(&Serviceclient::send_request, this));
        update_timer_ = create_wall_timer(500ms, std::bind(&Serviceclient::update, this));
        // send_request();
    }

private:
    typedef std::shared_ptr<std_srvs::srv::SetBool::Request> BRequest;
    typedef std::shared_ptr<std_srvs::srv::SetBool::Response> BResponse;
    rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr client_;
    std::shared_ptr<std_srvs::srv::SetBool::Request> request_;
    rclcpp::TimerBase::SharedPtr send_timer_;
    rclcpp::TimerBase::SharedPtr update_timer_;
    bool bool_;

    void send_request()
    {
        // request_ <- data
        if (request_ -> data)
        {
            request_ -> data = true;
        }
        else
        {
            request_ -> data = false;
        }

        auto future = client_ -> async_send_request(request_, std::bind(&Serviceclient::done_callback, 
                                                                            this, std::placeholders::_1));
    }
    
    void done_callback(rclcpp::Client<std_srvs::srv::SetBool>::SharedFuture future)
    {
        auto response = future.get();
        RCLCPP_INFO(get_logger(), response -> message.c_str());
        RCLCPP_INFO(get_logger(), "%s", response -> success? "ture" : "false");
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
