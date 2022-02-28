#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>

turtlesim::PoseConstPtr pose_pt;
turtlesim::Pose goal;

void poseCallback(const turtlesim::PoseConstPrt& pose)	{
	pose_pt = pose;
}

int main()	{
	ros::init();
	ros::NodeHandle nh;
	ros::Subscriber pose_sub = nh.subscribe("turtle1/pose", 1, poseCallback);
	ros::Publisher twist_pub = nh.advertise<geometry_msgs:Twist>("turtle1/cmd_vel", 1);

	return 0;
}
