// Generated by gencpp from file test_actionlib/testResult.msg
// DO NOT EDIT!


#ifndef TEST_ACTIONLIB_MESSAGE_TESTRESULT_H
#define TEST_ACTIONLIB_MESSAGE_TESTRESULT_H


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
struct testResult_
{
  typedef testResult_<ContainerAllocator> Type;

  testResult_()
    : test_result()  {
    }
  testResult_(const ContainerAllocator& _alloc)
    : test_result(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _test_result_type;
  _test_result_type test_result;





  typedef boost::shared_ptr< ::test_actionlib::testResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_actionlib::testResult_<ContainerAllocator> const> ConstPtr;

}; // struct testResult_

typedef ::test_actionlib::testResult_<std::allocator<void> > testResult;

typedef boost::shared_ptr< ::test_actionlib::testResult > testResultPtr;
typedef boost::shared_ptr< ::test_actionlib::testResult const> testResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_actionlib::testResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_actionlib::testResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test_actionlib

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'test_actionlib': ['/home/turtle/catkin_ws/src/tutorial_behaviors/test_actionlib/curlpp/devel/share/test_actionlib/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test_actionlib::testResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_actionlib::testResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_actionlib::testResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_actionlib::testResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_actionlib::testResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_actionlib::testResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_actionlib::testResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "453d8fb4bed17e1365cd8990de5cf609";
  }

  static const char* value(const ::test_actionlib::testResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x453d8fb4bed17e13ULL;
  static const uint64_t static_value2 = 0x65cd8990de5cf609ULL;
};

template<class ContainerAllocator>
struct DataType< ::test_actionlib::testResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_actionlib/testResult";
  }

  static const char* value(const ::test_actionlib::testResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_actionlib::testResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#result\n\
string test_result\n\
";
  }

  static const char* value(const ::test_actionlib::testResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_actionlib::testResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.test_result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct testResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_actionlib::testResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_actionlib::testResult_<ContainerAllocator>& v)
  {
    s << indent << "test_result: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.test_result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_ACTIONLIB_MESSAGE_TESTRESULT_H
