#include "triorb.h"

#include <mc_triorb/config.h>
#include <RBDyn/parsers/urdf.h>

namespace mc_robots
{

TriorbRobotModule::TriorbRobotModule(const std::string & name) : mc_rbdyn::RobotModule(TRIORB_DESCRIPTION_PATH, "triorb")
{
  // The 2-argument RobotModule constructor derives urdf_path as
  // <path>/urdf/triorb.urdf, which is exactly where mc_triorb_description
  // installs the URDF.

  // The URDF root link `world` is fixed in space; the base moves through its
  // base_x / base_y / base_yaw joints, so this is a fixed-base robot.
  bool fixed = true;

  // Makes all the basic initialization that can be done from an URDF file
  init(rbd::parsers::from_urdf_file(urdf_path, fixed));

  // Order of the actuated joints as seen by the control/sensor vectors. The
  // base driver feeds odometry (x, y, yaw) and reads back velocity commands in
  // this same order.
  _ref_joint_order = {"base_x", "base_y", "base_yaw"};

  // The base carries only primitive collision geometry defined inline in the
  // URDF, so there are no convex hulls or self-collisions to declare.
  _minimalSelfCollisions = {};
  _commonSelfCollisions = _minimalSelfCollisions;

  // Default posture: base at the origin, facing forward.
  _stance["base_x"] = {0.0};
  _stance["base_y"] = {0.0};
  _stance["base_yaw"] = {0.0};
}

} // namespace mc_robots
