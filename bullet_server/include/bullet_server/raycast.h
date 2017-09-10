#include <bullet/btBulletDynamicsCommon.h>
#include <bullet_server/Line.h>
// #include <geometry_msgs/Point.h>
#include <geometry_msgs/Point.h>
#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>

class Raycast
{
public:
  Raycast(const std::string name, const std::string frame_id,
      const std::vector<bullet_server::Line>& lines,
      const std::string topic_name,
      ros::NodeHandle& nh,
      btDiscreteDynamicsWorld* dynamics_world);

  bool update(tf2_ros::Buffer& tf_buffer);
private:
  ros::Publisher point_cloud_pub_;

  const std::string name_;
  const std::string frame_id_;
  // all lines are in frame_id_ tf frame
  const std::vector<bullet_server::Line> lines_;

  const btDiscreteDynamicsWorld* dynamics_world_;
};

