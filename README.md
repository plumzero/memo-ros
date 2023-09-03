
*小新总能把豹男带偏。*

不依赖于环境的源码 ROS 测试环境。

### 关于 ROS

- [简要概述](docs/01_简要概述.md)
- [总体框架](docs/02_总体框架.md)
- [搭建使用](docs/03_搭建使用.md)

### 测试版本

- boost: 1.81
- bzip2: 1.0.6
- lz4: 1.1.3
- console_bridge: 1.0.2
- [ros_common:noetic-devel](https://github.com/ros/ros_comm)
- [roscpp_core:noetic-devel](https://github.com/ros/roscpp_core)
- [pluginlib: noetic-devel(unused)](https://github.com/ros/pluginlib)
- ros: noetic-devel
- [rosconsole:noetic-devel](https://github.com/ros/rosconsole)
- [ros_comm_msgs:kinetic-devel](https://github.com/ros/ros_comm_msgs)

### 关于 lz4

lz4 不能用太高的版本，否则不兼容。这里使用 1.1.3

将 lz4 库中的如下文件 放入 include/ros_comm/utilities/roslz4/src 目录下。
```s
  lz4.c
  lz4.h
  lz4hc.c
  lz4hc.h
  lz4io.c
  lz4io.h
```
xxhash.c 和 xxhash.h 仍然使用 ros_common 环境下的同名文件，这个很有必要。

### 生成依赖文件或目标文件

1 console_bridge
```s
  cd console_bridge
  mkdir build; cd build
  cmake ..
```
将 console_bridge_export.h  console.cpp  console.h 拷贝到 include/console_bridge 目录下即可。

生成的 .h 文件即是目标文件。

2 ros_comm_msgs/rosgraph_msgs

- cd ros_comm_msgs/rosgraph_msgs/
- mkdir build; cd build
- cmake ..
- make
- 执行完毕之后，会在当前目录下看到一个 devel 目录，进入到 devel/include 下，rosgraph_msgs 目录即是目标文件。将其拷贝到本工程的 devel 目录下。

3 ros_comm/clients/roscpp

在生成目标文件之前，需要对 ros_comm/clients/roscpp/CMakeLists.txt 文件进行修改，设置依赖的 boost 库路径。修改后的文件在[这里](include/ros_comm/clients/roscpp/CMakeLists.txt)。

- cd ros_comm/clients/roscpp/
- mkdir build; cd build
- cmake ..
- make
- 执行完毕之后，会在当前目录下看到一个 devel 目录，进入到 devel/include 下，目录中的文件即是目标文件。将其拷贝到本工程的 devel 目录下。

### 参考

- [接口说明](http://docs.ros.org/en/diamondback/api/rosbag/html/c++/classrosbag_1_1Bag.html)
