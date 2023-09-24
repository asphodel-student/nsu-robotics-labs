#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/string.hpp"

class TextToCmdVelNode : public rclcpp::Node
{
public:
    TextToCmdVelNode() : Node("text_to_cmd_vel")
    {
        // Создаем подписчика на топик "cmd_text"
        cmd_text_subscription_ = this->create_subscription<std_msgs::msg::String>("cmd_text", 10,
            [this](const std_msgs::msg::String::SharedPtr msg) 
            {
                
                geometry_msgs::msg::Twist cmd_vel;
                if (msg->data == "turn_right") {
                    cmd_vel.angular.z = -1.5; 
                } else if (msg->data == "turn_left") {
                    cmd_vel.angular.z = 1.5;
                } else if (msg->data == "move_forward") {
                    cmd_vel.linear.x = 1.0; 
                } else if (msg->data == "move_backward") {
                    cmd_vel.linear.x = -1.0; 
                }

                cmd_vel_publisher_->publish(cmd_vel);
            });

        // Создаем издателя для топика "/turtle1/cmd_vel"
        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(
            "/turtle1/cmd_vel", 10);
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr cmd_text_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TextToCmdVelNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
