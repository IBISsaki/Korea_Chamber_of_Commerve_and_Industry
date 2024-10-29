#ifndef CHECKER__CHECKER_HPP_
#define CHECKER__CHECKER_HPP_

#include <memory>
#include <string>
#include <utility>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "msg_srv_action/rclcpp_action.hpp"

class Checker : public rclcpp::Node
{
public:
    using ArithmeticChecker = msg_srv_action_interface_example::action::ArithmeticChecker;
    using GoalHandleArithmeticChecker = rclcpp_action::ClientGoalHandle<ArithmeticChecker>;

    explicit Checker(
        float goal_sum
        const rclcpp::NodeOption & node_options = rclcpp::NodeOptions());
    virtual ~Checker();

private:
    void send_goal_total_sum(float goal_sum);

    void get_arithmetic_action_goal(
        std::shared_future<rclcpp_action::ClientGoalHandle<ArithmeticChecker>::SharedPtr> future);

    void get_artithmetic_action_feedback(
        GoalHandleArithmeticChecker::SharedPtr,
        const std::shared_ptr<const ArithmeticChecker::Feedback> feedback);

    void get_arithmetic_action_result(
        const GoalHandleArithmeticChecker::WrappedResult & result);
    rclcpp_action::Client<ArithmeticChecker>::SharedPtr arithmetic_Action_client;
};

#endif  // CHECKER__CHECKER_HPP_