import rclpy


""" 方式一 不推荐

def main():
    rclpy.init()
                        #节点名字
    node = rclpy.create_node("helloworld_node_py")

    node.get_logger().info("hello world!(python)")

    rclpy.shutdown()

if __name__ == '__main__':
    main()
 """

from rclpy.node import Node
 #方式二 推荐

#自定义类
class Mynode(Node):

    def __init__(self):
        super().__init__("hello_node_py")
        self.get_logger().info("hello world! python 继承")


def main():
    #初始化
    rclpy.init()
    #创建对象    
    node = Mynode()
    #资源释放
    rclpy.shutdown()  
