import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.qos import QoSHistoryPolicy, QoSReliabilityPolicy, QoSDurabilityPolicy
from std_msgs.msg import String, Header
from rclpy.clock import ClockType, Clock

class Mtpub(Node):
    def __init__(self):
        super().__init__("mtpub")
        self.qos_profile = QoSProfile(history = QoSHistoryPolicy.KEEP_LAST,
                                      reliability = QoSReliabilityPolicy.BEST_EFFORT,
                                      durability = QoSDurabilityPolicy.VOLATILE,
                                      depth = 10)
        self.create_timer(1, self.print_time)
        self.time_pub = self.create_publisher(Header, "time", self.qos_profile)
        self.clock = Clock(clock_type = ClockType.SYSTEM_TIME)
        self.number = 0
        self.create_timer(1, self.print_message2)
        self.msg2_pub = self.create_publisher(String, "message2", self.qos_profile)

    def print_time(self):
        msg = Header()
        msg.frame_id = "time"
        msg.stamp = self.clock.now().to_msg()
        print(f"sec: {msg.stamp.sec}, nanosec: {msg.stamp.nanosec}")
        self.time_pub.publish(msg)

    def print_message2(self):
        msg = String()
        msg.data = f"homework_mtpub + {self.number}"
        self.msg2_pub.publish(msg)
        print(msg.data)
        self.number += 1

def main():
    rclpy.init()
    node = Mtpub()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()   
    
if __name__ == "__main__":
    main()
