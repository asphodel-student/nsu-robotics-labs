#include <functional>
#include <memory>
#include <string>

#include "turtlesim/msg/pose.hpp"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"


class MoveToGoalNode : public rclcpp::Node
{
public:
    MoveToGoalNode(int argc, char** argv) : Node("move_2_goal")
    {
        if (argc != 4)
        {
            std::cout << "Invalid arguments!" << std::endl;
            std::exit(-1);
        }

        _publisher = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);     
        _subscription = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose", 10, 
                                                std::bind(&MoveToGoalNode::updatePoseCallback, this, std::placeholders::_1));

        _goal.x     = std::stof(argv[1]);
        _goal.y     = std::stof(argv[2]);
        _goal.theta = std::stof(argv[3]);
    }

private:
    turtlesim::msg::Pose _msg;
    turtlesim::msg::Pose _goal;

    float getEuclidianDistance()
    {
        return std::sqrt(std::pow(_goal.x - _msg.x, 2) + std::pow(_goal.y - _msg.y, 2));
    }

    float getLinearVelocity(float constant=1)
    {
        return constant * getEuclidianDistance();
    }

    float getSteeringAngle()
    {
        return std::atan2(_goal.y - _msg.y, _goal.x - _msg.x);
    }

    float getAngularVelocity(float constant=4)
    {
        return constant * (getSteeringAngle() - _msg.theta);
    }

    void updatePoseCallback(const turtlesim::msg::Pose& msg) 
    { 
        _msg = msg;

        geometry_msgs::msg::Twist res;

        res.linear.y = res.linear.z = 0;
        res.angular.x = res.angular.y = 0;
       
        res.linear.x = getLinearVelocity();
        res.angular.z = getAngularVelocity();

        _publisher->publish(res);

        if (getEuclidianDistance() < 0.1)
        {
            res.linear.x = 0;
            res.angular.z = 0;

            _publisher->publish(res);

            rclcpp::shutdown();
        }
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _publisher;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr _subscription;
};


int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<MoveToGoalNode>(argc,argv));

  rclcpp::shutdown();

  return 0;
}