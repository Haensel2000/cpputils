#include "print.h"

using namespace cpputils::debug;

const char* cpputils::debug::Printable::toStr() const {
	std::stringstream s;
	s << this;
	return s.str().c_str();
}

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
