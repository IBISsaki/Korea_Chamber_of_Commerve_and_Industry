import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.qos import QoSHistoryPolicy, QoSReliabilityPolicy, QoSDurabilityPolicy
from std_msgs.msg import String

class Hello_pub(Node):
    def __init__(self):
        super().__init__("hellosub")
        self.qos_profile = QoSProfile(history = QoSHistoryPolicy.KEEP_ALL,
                                      reliability = QoSReliabilityPolicy.RELIABLE,
                                      durability = QoSDurabilityPolicy.TRANSIENT_LOCAL)
        self.create_timer(1, self.print_hello)
        self.pub = self.create_publisher(String, "send", self.qos_profile)
        self.number = 0

    def print_hello(self):
        msg = String()
        msg.data = f"hello, ros2! nice to meet you! + {self.number}"
        self.pub.publish(msg)
        self.get_logger().info(msg.data)
        self.number += 1

def main():
    rclpy.init()
    node = Hello_pub()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node   
    
if __name__ == "__main__":
    main()
