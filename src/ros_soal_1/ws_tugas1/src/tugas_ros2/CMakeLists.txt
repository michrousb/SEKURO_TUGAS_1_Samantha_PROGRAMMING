cmake_minimum_required(VERSION 3.8)
project(tugas_ros2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# executable camera node
add_executable(camera_node src/camera.cpp)
ament_target_dependencies(camera_node rclcpp std_msgs)


# executable detect node
add_executable(detect_objects_node src/detect_objects.cpp)
ament_target_dependencies(detect_objects_node rclcpp std_msgs)

# install executables

install(TARGETS
  camera_node
  detect_objects_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
