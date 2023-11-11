cmake_minimum_required(VERSION 3.5)

project(robot_app)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(stop_near_obstacle src/stop_near_obstacle.cpp)
ament_target_dependencies(stop_near_obstacle rclcpp geometry_msgs sensor_msgs)

install (TARGETS stop_near_obstacle DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()