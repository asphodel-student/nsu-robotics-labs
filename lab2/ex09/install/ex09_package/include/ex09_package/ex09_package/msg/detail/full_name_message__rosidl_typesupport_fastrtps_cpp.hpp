// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ex09_package:msg/FullNameMessage.idl
// generated code does not contain a copyright notice

#ifndef EX09_PACKAGE__MSG__DETAIL__FULL_NAME_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define EX09_PACKAGE__MSG__DETAIL__FULL_NAME_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ex09_package/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ex09_package/msg/detail/full_name_message__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ex09_package
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ex09_package
cdr_serialize(
  const ex09_package::msg::FullNameMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ex09_package
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ex09_package::msg::FullNameMessage & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ex09_package
get_serialized_size(
  const ex09_package::msg::FullNameMessage & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ex09_package
max_serialized_size_FullNameMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ex09_package

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ex09_package
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ex09_package, msg, FullNameMessage)();

#ifdef __cplusplus
}
#endif

#endif  // EX09_PACKAGE__MSG__DETAIL__FULL_NAME_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
