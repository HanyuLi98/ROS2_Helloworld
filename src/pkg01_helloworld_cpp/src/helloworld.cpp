
#include "rclcpp/rclcpp.hpp"


/*  方式一  不推荐
int main(int argc, char ** argv)
{

  //初始化ros2
  rclcpp::init(argc, argv);


  //第一个 ::：它用于指定 rclcpp 命名空间，表明 Node 类是在 rclcpp 命名空间中定义的。这告诉编译器你要使用 rclcpp 命名空间中的 Node 类。
  //第二个 ::：它用于指定 Node 类中的静态成员函数 make_shared。静态成员函数是不依赖于类的实例而存在的函数，因此你可以通过类名和 :: 运算符来访问它们。
  //创建节点指针                          # 节点名
  auto node = rclcpp::Node::make_shared("helloworld_node");
  //输出文本          #得到日志       #输出文本
  RCLCPP_INFO(node->get_logger(), "hello world!");
  //释放资源
  rclcpp::shutdown();
  return 0;
}
 */

//方式二  推荐


//自定义类

class MyNode:public rclcpp::Node{

public:   
      //构造函数 : 初始化列表调用基类Node构造函数 首先会调用基类的构造函数，然后才调用派生类的构造函数
      MyNode():Node("hello_node_cpp"){
            RCLCPP_INFO(this->get_logger(), "hello 继承方式");
      }

};


int main(int argc, char** argv){


    //初始化
  rclcpp::init(argc, argv);
    //实例化
  auto node = std::make_shared<MyNode>();
    //释放
  rclcpp::shutdown();
    return 0;


}