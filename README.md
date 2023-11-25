
*小新总能把豹男带偏。*

*一切都仿佛加速之后的宁静。*

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
- libgpg-error
- libassuan
- gpgme

### 使用

```s
  mkdir build
  cd build
  cmake ..
  make -j8
```

ROS 是一个分布式的通信框架，它通过以下方式进行节点之间的通信。

各节点首先与主节点 master (通过 XMLRPC、XML、RPC、HTTP 等)建立连接，向主节点中注册自己的节点信息。之后各节点之间通过 TCP、UDP 等进行数据的传输。

ROS 网络通信时的环境变量 `ROST_MASTER_URI` 和 `ROS_HOSTNAME`。也可以通过如下方式进行更改:
```sh
  export ROST_MASTER_URI=http://localhost:11311
  export ROS_HOSTNAME=localhost
```
