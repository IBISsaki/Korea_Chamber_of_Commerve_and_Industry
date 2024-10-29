#include <memory>
#include "checker/checker.hpp"

Checker::Checker(float goal_sum, const rclcpp::NodeOption & node_options)
: Node("checker", node_options)
{
    arithmetic_action_client_ = rclcpp_action::create_client<ArithmeticChecker>(
        this -> get_node_base_interface(),
        this -> get_node_graph_interface(),
        this -> get_node_logging_interface(),
        this -> get_node_waitables_interface(),
        "arithmetic_checker");

    send_goal_total_sum(goal_sum);
}

Checker::~Checker()
{
}

