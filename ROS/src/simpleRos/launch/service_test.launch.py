from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package = "simpleRos", executable = "service_server"), 
        Node(package = "simpleRos", executable = "service_client")
    ])
