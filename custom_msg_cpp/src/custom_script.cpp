#include "ros/ros.h"
#include "custom_msg_cpp/custom.h"

#include <ctime>
#include <chrono>
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<custom_msg_cpp::custom>("custom", 10);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        custom_msg_cpp::custom msg;
        msg.robot_name.data = "Robot_1";
        auto end = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        msg.date_time.data = std::ctime(&end_time);

        msg.location.x = 5;
        msg.location.y = 5;
        msg.location.theta = 90;

        pub.publish(msg);
        loop_rate.sleep();

    }
    return 0;
}
