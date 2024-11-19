import rclpy
from open_manipulator_msgs.srv import SetJointPosition
from rclpy.clock import Duration
from rclpy.node import Node
from rclpy.task import Future


class Patrol_manipulator(Node):
    def __init__(self):
        super().__init__("patrol_manipulator")
        self.client = self.create_client(SetJointPosition, "goal_joint_space_path")
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("service not available")
        self.request = SetJointPosition.Request()
        self.create_timer(1/60, self.update)
        self.joint_angles = self.request.joint_position.position
        self.prev_time = self.get_clock().now()
        self.stage = 0

    def send_request(self, path_time=0.5):
        self.request.joint_position.joint_name = ['joint1', 'joint2', 'joint3', 'joint4']
        self.request.joint_position.position = self.joint_angles
        self.request.path_time = path_time
        self.future = self.client.call_async(self.request)
        self.future.add_done_callback(self.done_callback)

    def done_callback(self, future : Future):
        response : SetJointPosition.Response = future.result()
        self.get_logger().info(f"{response.is_planned}")

    def update(self):
        if self.prev_time + Duration(seconds=3) > self.get_clock().now():
            # first move
            self.joint_angles = [0.0, 0.0, 0.0, 0.0 , 0.0]
            if self.stage == 0:
                self.send_request(2.0)
                self.stage += 1
        elif self.prev_time + Duration(seconds=5) > self.get_clock().now():
            # second move
            self.joint_angles = [1.411262 , 0.783864, -0.878971,-0.971010 , 0.0]
            if self.stage == 1:
                self.send_request(2.0)
                self.stage += 1
        elif self.prev_time + Duration(seconds=7) > self.get_clock().now():
            # second move
            self.joint_angles = [-0.003068, -0.015340, -1.466486, 1.411262 , 0.0]
            if self.stage == 2:
                self.send_request(2.0)
                self.stage += 1
        elif self.prev_time + Duration(seconds=9) > self.get_clock().now():
            # second move
            self.joint_angles = [-0.684155, 0.783864, -0.878971, -0.971010 , 0.0]
            if self.stage == 3:
                self.send_request(2.0)
                self.stage += 1

        elif self.prev_time + Duration(seconds=11) > self.get_clock().now():
            # second move
            self.joint_angles = [2.251884, 0.134990, -0.454058, 0.171806, 0.0]
            if self.stage == 4:
                self.send_request(2.0)
                self.stage += 1
        elif self.prev_time + Duration(seconds=13) > self.get_clock().now():
            self.prev_time = self.get_clock().now()
            self.stage = 0

def main():
    rclpy.init()
    node = Patrol_manipulator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()

if __name__ == "__main__":
    main()