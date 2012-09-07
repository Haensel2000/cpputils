#include "print.h"

ostream& operator<<(ostream& os, const std::string& s) {
	os << s.c_str();
	return os;
}
