#pragma once

// Standard includes
#include <string>

// Eigen includess
#include <Dense>

using Eigen::Vector;
using Eigen::Vector3f;

namespace util{
template<typename T, int n>
  std::string vectorToString(const Vector<T, n> &vector);
  
  std::string vector3fToString(const Vector3f& vector);
}

