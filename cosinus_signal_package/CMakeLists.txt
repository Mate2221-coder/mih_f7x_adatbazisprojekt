cmake_minimum_required(VERSION 3.5)
project(cosinus_signal_package)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Include directories
include_directories(include)

# Add the executable
add_executable(cosinus_signal_node src/cosinus_signal_node.cpp)

# Specify libraries to link against
ament_target_dependencies(cosinus_signal_node rclcpp std_msgs)

# Install the executable
install(TARGETS
  cosinus_signal_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# Install message files
install(DIRECTORY msg
  DESTINATION share/${PROJECT_NAME}
)

# Install resource files
install(DIRECTORY resource
  DESTINATION share/${PROJECT_NAME}
)

# Install include files
install(DIRECTORY include/
  DESTINATION include
)

# ament package
ament_package()