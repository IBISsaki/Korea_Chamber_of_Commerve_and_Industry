import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    param_dir = LaunchConfiguration('param_dir',
                                    default=os.path.join(
                                        get_package_share_directory('simpleRos'),
                                        'param',
                                        'simple_parameter.yaml'))
    return LaunchDescription([
        DeclareLaunchArgument('param_dir',
                              default_value=param_dir,
                              description="simple parameter"),
        Node(package="turtlesim",
             executable="turtlesim_node",
             parameters=[param_dir]
             ),
        ExecuteProcess(cmd=[['ros2 service call ', '/spawn ', 'turtlesim/srv/Spawn ', '"{x: 2, y: 2, theta: 0.2}"' ]], shell=True),
        
        Node(package="simpleRos",
            executable="move_turtle_ns",
            parameters=[param_dir],
            namespace="turtle1"
            ),
        
        Node(package="simpleRos",
            executable="move_turtle_time_ns",
            parameters=[param_dir],
            namespace="turtle2"
            ),
        
        ])