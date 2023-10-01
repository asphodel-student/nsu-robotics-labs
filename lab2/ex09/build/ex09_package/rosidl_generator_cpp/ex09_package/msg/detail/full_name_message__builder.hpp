// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ex09_package:msg/FullNameMessage.idl
// generated code does not contain a copyright notice

#ifndef EX09_PACKAGE__MSG__DETAIL__FULL_NAME_MESSAGE__BUILDER_HPP_
#define EX09_PACKAGE__MSG__DETAIL__FULL_NAME_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ex09_package/msg/detail/full_name_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ex09_package
{

namespace msg
{

namespace builder
{

class Init_FullNameMessage_first_name
{
public:
  explicit Init_FullNameMessage_first_name(::ex09_package::msg::FullNameMessage & msg)
  : msg_(msg)
  {}
  ::ex09_package::msg::FullNameMessage first_name(::ex09_package::msg::FullNameMessage::_first_name_type arg)
  {
    msg_.first_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ex09_package::msg::FullNameMessage msg_;
};

class Init_FullNameMessage_name
{
public:
  explicit Init_FullNameMessage_name(::ex09_package::msg::FullNameMessage & msg)
  : msg_(msg)
  {}
  Init_FullNameMessage_first_name name(::ex09_package::msg::FullNameMessage::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_FullNameMessage_first_name(msg_);
  }

private:
  ::ex09_package::msg::FullNameMessage msg_;
};

class Init_FullNameMessage_last_name
{
public:
  Init_FullNameMessage_last_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FullNameMessage_name last_name(::ex09_package::msg::FullNameMessage::_last_name_type arg)
  {
    msg_.last_name = std::move(arg);
    return Init_FullNameMessage_name(msg_);
  }

private:
  ::ex09_package::msg::FullNameMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ex09_package::msg::FullNameMessage>()
{
  return ex09_package::msg::builder::Init_FullNameMessage_last_name();
}

}  // namespace ex09_package

#endif  // EX09_PACKAGE__MSG__DETAIL__FULL_NAME_MESSAGE__BUILDER_HPP_
