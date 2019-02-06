// Generated by gencpp from file test_actionlib/testFeedback.msg
// DO NOT EDIT!


#ifndef TEST_ACTIONLIB_MESSAGE_TESTFEEDBACK_H
#define TEST_ACTIONLIB_MESSAGE_TESTFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test_actionlib
{
template <class ContainerAllocator>
struct testFeedback_
{
  typedef testFeedback_<ContainerAllocator> Type;

  testFeedback_()
    : test_feedback(0)  {
    }
  testFeedback_(const ContainerAllocator& _alloc)
    : test_feedback(0)  {
  (void)_alloc;
    }



   typedef int32_t _test_feedback_type;
  _test_feedback_type test_feedback;





  typedef boost::shared_ptr< ::test_actionlib::testFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_actionlib::testFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct testFeedback_

typedef ::test_actionlib::testFeedback_<std::allocator<void> > testFeedback;

typedef boost::shared_ptr< ::test_actionlib::testFeedback > testFeedbackPtr;
typedef boost::shared_ptr< ::test_actionlib::testFeedback const> testFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_actionlib::testFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_actionlib::testFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test_actionlib

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'test_actionlib': ['/home/turtle/catkin_ws/src/tutorial_behaviors/test_actionlib/curlpp/devel/share/test_actionlib/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test_actionlib::testFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_actionlib::testFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_actionlib::testFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_actionlib::testFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_actionlib::testFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_actionlib::testFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_actionlib::testFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fa3040db3efe13ae7d434a0ce44bd07b";
  }

  static const char* value(const ::test_actionlib::testFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfa3040db3efe13aeULL;
  static const uint64_t static_value2 = 0x7d434a0ce44bd07bULL;
};

template<class ContainerAllocator>
struct DataType< ::test_actionlib::testFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_actionlib/testFeedback";
  }

  static const char* value(const ::test_actionlib::testFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_actionlib::testFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
int32 test_feedback\n\
\n\
";
  }

  static const char* value(const ::test_actionlib::testFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_actionlib::testFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.test_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct testFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_actionlib::testFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_actionlib::testFeedback_<ContainerAllocator>& v)
  {
    s << indent << "test_feedback: ";
    Printer<int32_t>::stream(s, indent + "  ", v.test_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_ACTIONLIB_MESSAGE_TESTFEEDBACK_H