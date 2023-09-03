
*小新总能把豹男带偏。*

不依赖于环境的源码 ROS 测试环境。

### 说明

- [简要概述](docs/01_简要概述.md)
- [总体框架](docs/02_总体框架.md)
- [基础环境](docs/03_基础环境.md)
- [环境搭建](docs/04_环境搭建.md)

### 版本

- boost: 1.83.0
- bzip2: 1.0.6
- lz4: 1.1.3
- console_bridge: 1.0.2
- [ros_common:noetic-devel](https://github.com/ros/ros_comm)
- [roscpp_core:noetic-devel](https://github.com/ros/roscpp_core)
- [pluginlib: noetic-devel(unused)](https://github.com/ros/pluginlib)
- ros: noetic-devel
- [rosconsole:noetic-devel](https://github.com/ros/rosconsole)
- [ros_comm_msgs:kinetic-devel](https://github.com/ros/ros_comm_msgs)

### 使用

```s
  mkdir build
  cd build
  cmake ..
  make -j8
```
