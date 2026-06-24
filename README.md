mc_triorb
==

An [mc_rtc] robot module for the **TriOrb** omnidirectional mobile base.

The base is modelled from [`mc_triorb_description`](../mc_triorb_description) as a
fixed `world` root carrying the body through three actuated joints:

| Joint      | Type       | Axis      | Meaning              |
|------------|------------|-----------|----------------------|
| `base_x`   | prismatic  | world `x` | base position along X |
| `base_y`   | prismatic  | world `y` | base position along Y |
| `base_yaw` | continuous | world `z` | base heading          |

Because the planar pose is exposed as three regular joints, the controller's QP
sees the base position directly — no floating base is needed. The
`base_x, base_y, base_yaw` ordering is the reference joint order, which is also
the order the TriOrb base driver/plugin uses to feed odometry and read back
velocity commands.

Building
--

The module finds its URDF through the [`mc_triorb_description`](../mc_triorb_description)
package via mc_rtc's `find_description_package` macro, so that package must be
built and installed (to the same prefix) first. Then:

```bash
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=<your mc_rtc install prefix>
cmake --build .
cmake --install .
ctest          # runs loader_triorb, which loads the URDF through mc_rtc
```

(The `loader_triorb` test resolves the URDF from the installed description
package, so install before running `ctest`.)

Using it
--

Once installed into your mc_rtc prefix, select the robot by name `triorb`, e.g.
set `MainRobot: triorb` in your controller configuration, or load it from code:

```cpp
auto rm = mc_rbdyn::RobotLoader::get_robot_module("triorb");
```

[mc_rtc]: https://jrl-umi3218.github.io/mc_rtc/
