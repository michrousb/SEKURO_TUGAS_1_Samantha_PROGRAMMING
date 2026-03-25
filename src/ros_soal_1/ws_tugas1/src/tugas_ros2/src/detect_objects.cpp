#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class detectObjectsNode : public rclcpp::Node
{
public: 
    detectObjectsNode(): Node("detect_objects_node")
    {
        camera_subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "front_camera",
            10,
            std :: bind(&detectObjectsNode::detect_callback, this,_1) /*(function yg mau dipakai, function milik object ini, placeholder(yg neruisn pesan ke msg, krn msg baru ada di dlm function jd hrs taro di temp dlu)*/
        );
        
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr camera_subscriber_;

    void detect_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received frame: %s", msg->data.c_str());
        RCLCPP_INFO(this->get_logger(), "Detecting objects from front camera...");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);                    // mulai sistem ROS2 C++

    rclcpp::spin(std::make_shared<detectObjectsNode>());                          // bikin node tetap hidup

    rclcpp::shutdown();                          // matiin sistem ROS2 saat program selesai
    return 0;
}