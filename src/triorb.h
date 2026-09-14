#pragma once

#include <mc_rbdyn/RobotModuleMacros.h>
#include <mc_rtc/logging.h>
#include <mc_rbdyn/RobotModule.h>
#include <mc_robots/api.h>

namespace mc_robots
{

/** Robot module for the TriOrb omnidirectional base.
 *
 * The base is modelled as a fixed `world` root with three actuated joints that
 * carry the body in the plane:
 *   - base_x   (prismatic, world X)
 *   - base_y   (prismatic, world Y)
 *   - base_yaw (continuous, world Z)
 *
 * The planar pose reported by the base driver maps directly onto these three
 * joints, so the controller sees the base position through the QP without
 * needing a floating base.
 */
struct MC_ROBOTS_DLLAPI TriorbRobotModule : public mc_rbdyn::RobotModule
{
  TriorbRobotModule(const std::string & name);
};

} // namespace mc_robots

extern "C"
{
  ROBOT_MODULE_API void MC_RTC_ROBOT_MODULE(std::vector<std::string> & names)
  {
    names = {"TriOrb"};
  }
  ROBOT_MODULE_API void destroy(mc_rbdyn::RobotModule * ptr)
  {
    delete ptr;
  }
  ROBOT_MODULE_API mc_rbdyn::RobotModule * create(const std::string & n)
  {
    ROBOT_MODULE_CHECK_VERSION("TriOrb")
    if(n == "TriOrb")
    {
      return new mc_robots::TriorbRobotModule("triorb");
    }
    else
    {
      mc_rtc::log::error("triorb module cannot create an object of type {}", n);
      return nullptr;
    }
  }
}
