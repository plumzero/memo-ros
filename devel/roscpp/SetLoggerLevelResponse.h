// Generated by gencpp from file roscpp/SetLoggerLevelResponse.msg
// DO NOT EDIT!


#ifndef ROSCPP_MESSAGE_SETLOGGERLEVELRESPONSE_H
#define ROSCPP_MESSAGE_SETLOGGERLEVELRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace roscpp
{
template <class ContainerAllocator>
struct SetLoggerLevelResponse_
{
  typedef SetLoggerLevelResponse_<ContainerAllocator> Type;

  SetLoggerLevelResponse_()
    {
    }
  SetLoggerLevelResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetLoggerLevelResponse_

typedef ::roscpp::SetLoggerLevelResponse_<std::allocator<void> > SetLoggerLevelResponse;

typedef boost::shared_ptr< ::roscpp::SetLoggerLevelResponse > SetLoggerLevelResponsePtr;
typedef boost::shared_ptr< ::roscpp::SetLoggerLevelResponse const> SetLoggerLevelResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roscpp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'roscpp': ['/home/libei/Public/rosdev/include/ros_comm/clients/roscpp/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::roscpp::SetLoggerLevelResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roscpp/SetLoggerLevelResponse";
  }

  static const char* value(const ::roscpp::SetLoggerLevelResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::roscpp::SetLoggerLevelResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetLoggerLevelResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roscpp::SetLoggerLevelResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::roscpp::SetLoggerLevelResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // ROSCPP_MESSAGE_SETLOGGERLEVELRESPONSE_H
