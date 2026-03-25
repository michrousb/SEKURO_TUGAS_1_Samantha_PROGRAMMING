#include "rclcpp/rclcpp.hpp" /*import library ROS untuk C++*/
#include "std_msgs/msg/string.hpp" /*import tipe pesan string bawaan ROS2*/

class CameraNode : public rclcpp::Node{ 
    /*constructor, namanya sama dengan class*/
    public: 
        CameraNode(): Node("camera_node"), frame_counter(0){ 

            /*PUBLISHER*/
            camera_publisher = this->create_publisher<std_msgs::msg::String>(
                "front_camera",
                10
            );

            /*TIMER*/
            timer_ = this->create_wall_timer(
                std::chrono::seconds(1),
                std::bind(&CameraNode::publish_frame, this) 
            );

    } 

    private:
        int frame_counter;

        /*deklarasi atribut*/
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr camera_publisher;
        rclcpp::TimerBase::SharedPtr timer_;

        void publish_frame(){
            auto msg = std_msgs::msg::String();
            msg.data = "Frame from front camera " + std::to_string(frame_counter);
            camera_publisher->publish(msg);
            RCLCPP_INFO(this->get_logger(), "Published message: %s", msg.data.c_str());

            frame_counter++;
        }

};

int main(int argc, char * argv[])
{
    // mulai sistem ROS2 C++
    rclcpp::init(argc, argv);


    // buat node tetap hidup
    rclcpp::spin(std::make_shared<CameraNode>());

    // matiin sistem ROS2 saat program selesai
    rclcpp::shutdown();

    return 0;
}