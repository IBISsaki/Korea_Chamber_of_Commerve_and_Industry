import rclpy
from rclpy.node import Node
from rclpy.qos import  (QoSHistoryPolicy, 
                        QoSReliabilityPolicy, 
                        QoSDurabilityPolicy, 
                        QoSProfile
                        )
from std_msgs.msg import String

class Msub(Node):
    def __init__(self):
        super().__init__("msub")
        self.qos_profile = QoSProfile(history = QoSHistoryPolicy.KEEP_LAST,
                                      reliability = QoSReliabilityPolicy.BEST_EFFORT,
                                      durability = QoSDurabilityPolicy.VOLATILE,
                                      depth = 10)
        self.create_subscription(String, "message", self.sub_callback, self.qos_profile)

    def sub_callback(self, msg: String):
        print(msg.data)

def main():
    rclpy.init()
    node = Msub()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()   
    
if __name__ == "__main__":
    main()
