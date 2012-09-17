#include "print.h"

std::ostream& operator<<(std::ostream& os, const std::string& s) {
	os << s.c_str();
	return os;
}
