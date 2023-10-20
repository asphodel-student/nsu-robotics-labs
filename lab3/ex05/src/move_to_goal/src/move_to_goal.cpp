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

    float xSpeed, ySpeed, aSpeed, destinationTheta;
    bool isStarted = false;

    float getEuclidianDistance()
    {
        return std::sqrt(std::pow(_goal.x - _msg.x, 2) + std::pow(_goal.y - _msg.y, 2));
    }

    void updatePoseCallback(const turtlesim::msg::Pose& msg) 
    { 
        _msg = msg;

        geometry_msgs::msg::Twist res;

        // Задаем начальную скорость при движении и угол поворота
        if (!isStarted)
        {
            xSpeed = _goal.x - _msg.x;
            ySpeed = _goal.y - _msg.y;
            this->destinationTheta = (_msg.theta + (_goal.theta * 3.14 / 180));
          
            isStarted = true;
        }

        // Когда доехали до точки, останавливаемся и начинаем поворачиваться
        if (getEuclidianDistance() < 0.2)
        {
            xSpeed = ySpeed = 0;
            aSpeed = 0.25;
        }

        res.linear.x    = xSpeed;
        res.linear.y    = ySpeed;
        res.angular.z   = aSpeed;
        
        _publisher->publish(res);

        // Ждем, пока повернемся на нужный угол
        if (aSpeed != 0)
        {
            if (std::abs(_msg.theta - destinationTheta) < 0.01)
            {
                res.angular.z = 0.0;
                _publisher->publish(res);
            }
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