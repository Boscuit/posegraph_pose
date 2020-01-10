#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "spp");
  ros::NodeHandle n;
  ros::Publisher staticpose_pub = n.advertise<geometry_msgs::PoseStamped>("staticpose",1);
  ros::Rate loop_rate(10);

  int count=0;
  while (ros::ok())
  {
    geometry_msgs::PoseStamped staticpose;
    staticpose.header.stamp = ros::Time::now();;
    staticpose.header.frame_id = "camera";
    staticpose.pose.position.x = -0.02901135;
    staticpose.pose.position.y = 0.03019926;
    staticpose.pose.position.z = -0.05879022;
    staticpose.pose.orientation.x = 0.7153;
    staticpose.pose.orientation.y = -0.0051;
    staticpose.pose.orientation.z = 0.0278;
    staticpose.pose.orientation.w = 0.6983;

    geometry_msgs::PoseStamped groundtruth;
    groundtruth.header.stamp = ros::Time::now();;
    groundtruth.header.frame_id = "map";
    groundtruth.pose.position.x = 0;
    groundtruth.pose.position.y = 0;
    groundtruth.pose.position.z = 0;
    groundtruth.pose.orientation.x = 0;
    groundtruth.pose.orientation.y = 0;
    groundtruth.pose.orientation.z = 0;
    groundtruth.pose.orientation.w = 0;

    //ROS_INFO("%s", staticpose);
    staticpose_pub.publish(staticpose);
    staticpose_pub.publish(groundtruth);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
