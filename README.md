
### 内容

- [安装使用](00_安装使用.md)
- [命令行工具](01_命令行工具.md)
- [节点通信](02_节点通信.md)
- [使用问题](03_使用问题.md)

### ROS1 和 ROS2

ROS 和 ROS2.0 的区别:

| ROS1 | ROS2 |
|:-----|:-----|
| 中心化网络 | 去中心化网络 |
| XMLRPC/TCP/UDP | DDS |
| Linux | Linux/Windows/Mac/RTOS |
|       | 向下兼容 ROS1 |

目前多使用 ROS1 ，ROS2 仍待发展完善。

![](img/ROS1-2.png)

### 自动驾驶

感知层
- 摄像机
- 激光雷达
- 高精地图

决策层
- 环境预测
- 动作规划
- 路径规划
- 行为决策