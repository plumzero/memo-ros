#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>

#include <functional>

using namespace sensor_msgs;
using namespace message_filters;

void callback(const ImageConstPtr& image, const CameraInfoConstPtr& cam_info)
{
  // Solve all of perception here...
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "vision_node");

  ros::NodeHandle nh;

  message_filters::Subscriber<Image> image_sub(nh, "image", 1);
  message_filters::Subscriber<CameraInfo> info_sub(nh, "camera_info", 1);
  message_filters::TimeSynchronizer<Image, CameraInfo> sync(image_sub, info_sub, 10);
  sync.registerCallback(std::bind(&callback, std::placeholders::_1, std::placeholders::_2));

  ros::spin();

  return 0;
}