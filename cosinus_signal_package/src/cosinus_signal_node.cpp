#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <cmath>

class CosinusSignalNode : public rclcpp::Node
{
public:
    CosinusSignalNode()
        : Node("cosinus_signal_node"), frequency_(1.0), amplitude_(1.0), phase_(0.0), time_(0.0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float64>("cosinus_signal", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&CosinusSignalNode::publish_cosinus_signal, this));
    }

private:
    void publish_cosinus_signal()
    {
        auto message = std_msgs::msg::Float64();
        message.data = amplitude_ * std::cos(2 * M_PI * frequency_ * time_ + phase_);
        publisher_->publish(message);
        time_ += 0.1; //a jelközötti táv nöbélese
    }

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    double frequency_;
    double amplitude_;
    double phase_;
    double time_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CosinusSignalNode>());
    rclcpp::shutdown();
    return 0;
}