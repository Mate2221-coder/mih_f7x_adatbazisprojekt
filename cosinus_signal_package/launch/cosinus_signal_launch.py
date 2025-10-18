from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cosinus_signal_package',
            executable='cosinus_signal_node',
            name='cosinus_signal_node',
            output='screen',
            parameters=[{'frequency': 1.0, 'amplitude': 1.0}]
        )
    ])