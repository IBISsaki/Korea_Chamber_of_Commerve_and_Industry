#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class ServiceServer : public rclcpp::Node{
    public:
        ServiceServer()
            : Node("service_server")
        {
            server_ = create_service<std_srvs::srv::SetBool>("setBool", 
            std::bind(&ServiceServer::service_callback, this, std::placeholders::_1, std::placeholders::_2));
        }

    private:
        typedef std::shared_ptr<std_srvs::srv::SetBool::Request> BRequest;
        typedef std::shared_ptr<std_srvs::srv::SetBool::Response> BResponse;
        rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr server_;
        bool bool_;
        void service_callback(const BRequest request, BResponse response)
        {
            std::string str = request -> data ? std:: string("true") : std::string("false");
            RCLCPP_INFO(this -> get_logger(), str.c_str());
            rclcpp::sleep_for(2s);
            if (request -> data != bool_){
                bool_ = !bool_;
                response -> success = true;
                response -> message = str + "setting success!!";
            }
            else
            {
                response -> success = false;
                response -> message = str + "setting fail!!";
            }

        }
};


int main()
{
    rclcpp::init(0, nullptr);
    auto node = make_shared<ServiceServer>();    // C++ 코드
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}
