#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/image.hpp"

using namespace std::chrono_literals;

constexpr float limit = 0.731021;

class StopNearObstacle : public rclcpp::Node
{
public:
	StopNearObstacle() : Node("stop_near_obstacle")
	{
		publisher = this->create_publisher<geometry_msgs::msg::Twist>("/robot/cmd_vel", 10);

		subscription = this->create_subscription<sensor_msgs::msg::Image>(
            "/depth/image", 10, std::bind(&StopNearObstacle::depth_camera_callback, this, std::placeholders::_1));

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
	rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription;
	sensor_msgs::msg::Image current_state;
	double linear_speed, angular_speed;

	void depth_camera_callback(const sensor_msgs::msg::Image& msg)
	{
		this->current_state = msg;

		geometry_msgs::msg::Twist twist;

		const float* ptr = reinterpret_cast<const float*>(msg.data.data());
		auto index = (msg.height / 2 * (msg.width) + msg.width / 2);

		RCLCPP_INFO(get_logger(), "Depth value at the center: %f", ptr[index]);

		if (ptr[index] > limit)
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