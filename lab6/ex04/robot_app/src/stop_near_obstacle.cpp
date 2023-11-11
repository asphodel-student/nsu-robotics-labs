#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;

class StopNearObstacle : public rclcpp::Node
{
public:
	StopNearObstacle() : Node("stop_near_obstacle")
	{
		publisher = this->create_publisher<geometry_msgs::msg::Twist>("/robot/cmd_vel", 10);
		// timer = this->create_wall_timer(5ms, std::bind(&StopNearObstacle::timer_callback, this));

		subscription = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/robot/scan", 10, std::bind(&StopNearObstacle::lazer_callback, this, std::placeholders::_1));

		linear_speed = this->declare_parameter<double>("linear_speed");
		angular_speed = this->declare_parameter<double>("angular_speed");

		geometry_msgs::msg::Twist twist;

		twist.linear.x = this->linear_speed;
		twist.angular.z = this->angular_speed;

		publisher->publish(twist);
	}

private:
	rclcpp::TimerBase::SharedPtr timer;
	rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
	rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription;
	sensor_msgs::msg::LaserScan current_state;

	double linear_speed, angular_speed;

	void lazer_callback(const sensor_msgs::msg::LaserScan& msg)
	{
		this->current_state = msg;

		geometry_msgs::msg::Twist twist;

		if (current_state.ranges[179] >= 0.4)
		{
			twist.linear.x = this->linear_speed;
			twist.angular.z = this->angular_speed;
		}
		else
		{
			twist.linear.x = 0;
			twist.angular.z = 0;
		}

		publisher->publish(twist);
	}
};

int main(int argc, char** argv)
{
	rclcpp::init(argc, argv);

	rclcpp::spin(std::make_shared<StopNearObstacle>());

	rclcpp::shutdown();
    
	return 0;
}