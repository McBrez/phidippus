// Standard includes
#include <sstream>

// Project includes
#include <util.hpp>

namespace util {

template<typename T, int n>
  std::string vectorToString(const Vector<T, n> &vector) {
	  std::stringstream ss; 
		ss << vector;
		return ss.str();
  }
  
  
  std::string vector3fToString(const Vector3f& vector) {
	  std::stringstream ss; 
		ss << vector;
		return ss.str();
	}

}