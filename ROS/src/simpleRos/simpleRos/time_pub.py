import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.qos import QoSHistoryPolicy, QoSReliabilityPolicy, QoSDurabilityPolicy
from std_msgs.msg import String, Header
from rclpy.clock import ClockType, Clock

class time_pub(Node):
    def __init__(self):
        super().__init__("timesub")
        self.qos_profile = QoSProfile(history = QoSHistoryPolicy.KEEP_LAST,
                                      reliability = QoSReliabilityPolicy.BEST_EFFORT,
                                      durability = QoSDurabilityPolicy.VOLATILE,
                                      depth = 10)
        self.create_timer(1, self.print_hello)
        self.pub = self.create_publisher(Header, "time", self.qos_profile)
        # self.clock = self.get_clock()
        # ROS_TIME, STEADY_TIME, SYSTEM_TIME(default)
        self.clock = Clock(clock_type = ClockType.SYSTEM_TIME)

    def print_hello(self):
        msg = Header()
        msg.frame_id = "time"
        msg.stamp = self.clock.now().to_msg()
        print(f"sec: {msg.stamp.sec}, nanosec: {msg.stamp.nanosec}")
        self.pub.publish(msg)

def main():
    rclpy.init()
    node = time_pub()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node   
    
if __name__ == "__main__":
    main()
