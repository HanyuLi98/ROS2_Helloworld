import rclpy

def main():
    rclpy.init()
                        #节点名字
    node = rclpy.create_node("helloworld_node_py")

    node.get_logger().info("hello world!(python)")

    rclpy.shutdown()

if __name__ == '__main__':
    main()
