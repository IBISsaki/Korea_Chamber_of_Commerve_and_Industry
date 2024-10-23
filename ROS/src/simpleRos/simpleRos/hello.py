import rclpy
from rclpy.node import Node

def print_hello():
    print("Hello, Ros2 nice to meet you!")
    print("This is simlink really!!!")

def main():
    rclpy.init()
    node = Node("hello")
    node.create_timer(1, print_hello)

    rclpy.spin(node)

if __name__ == "__main__":
    main()
