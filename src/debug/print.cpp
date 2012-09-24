#include "print.h"

std::ostream& operator<<(std::ostream& os, const std::string& s) {
	os << s.c_str();
	return os;
}

std::ostream& operator<<(std::ostream& os, const cpputils::debug::Printable& p) {
	p.print(os);
	return os;
}

std::ostream& operator<<(std::ostream& os, const cpputils::debug::Printable* p) {
	p->print(os);
	return os;
}
