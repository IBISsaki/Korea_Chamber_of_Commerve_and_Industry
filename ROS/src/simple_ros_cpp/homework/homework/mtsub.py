import rclpy
from rclpy.node import Node
from rclpy.qos import  (QoSHistoryPolicy, 
                        QoSReliabilityPolicy, 
                        QoSDurabilityPolicy, 
                        QoSProfile
                        )
from std_msgs.msg import String, Header
from rclpy.clock import ClockType, Clock

class Mtsub(Node):
    def __init__(self):
        super().__init__("mtsub")
        self.qos_profile = QoSProfile(history = QoSHistoryPolicy.KEEP_LAST,
                                      reliability = QoSReliabilityPolicy.BEST_EFFORT,
                                      durability = QoSDurabilityPolicy.VOLATILE,
                                      depth = 10)
        self.time_pub = self.create_subscription(Header, "time", self.time_sub_callback, self.qos_profile)
        self.clock = Clock(clock_type = ClockType.SYSTEM_TIME)
        self.msg_pub = self.create_subscription(String, "message", self.msg_sub_callback, self.qos_profile)
        self.number = 0

    def time_sub_callback(self, msg: Header):
        print(f"sec: {msg.stamp.sec}, nanosec: {msg.stamp.nanosec}")
        print("second", msg.frame_id, msg.stamp.sec, msg.stamp.nanosec)

    def msg_sub_callback(self, msg: String):
        print(msg.data)

def main():
    rclpy.init()
    node = Mtsub()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()   
    
if __name__ == "__main__":
    main()
