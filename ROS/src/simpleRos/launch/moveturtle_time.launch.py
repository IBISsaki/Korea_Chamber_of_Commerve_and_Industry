from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package = "turtlesim", executable = "turtlesim_node"), 
        Node(package = "simpleRos", executable = "move_turtle_time")
    ])
