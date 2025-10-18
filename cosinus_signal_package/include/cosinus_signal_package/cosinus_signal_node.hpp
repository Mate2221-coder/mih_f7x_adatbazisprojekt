#ifndef COSINUS_SIGNAL_NODE_HPP
#define COSINUS_SIGNAL_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <cmath>

class CosinusSignalNode : public rclcpp::Node
{
public:
    CosinusSignalNode();

private:
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    double frequency_;
    double amplitude_;
    double phase_;
    double time_;
};

#endif 