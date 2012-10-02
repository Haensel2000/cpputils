/*
 * print.h
 *
 *  Created on: Aug 21, 2012
 *  Author: Hannes Widmoser
 */

#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;

ostream& operator<<(ostream& os, const std::string& s);

namespace cpputils {

namespace debug {

template<class T>
void print(ostream& os, vector<T>& v, const char* delim) {
	typename vector<T>::iterator first = v.begin();
	if (first != v.end()) {
		os << *first;
		for (typename vector<T>::iterator i = ++first; i != v.end(); ++i) {
			os << delim << *i;
		}
	}
}

class Printable {
public:

	virtual ~Printable() {
	}

	virtual void print(std::ostream& os) const = 0;

};

}

}

template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
	cpputils::debug::print(os, v, ", ");
	return os;
}

std::ostream& operator<<(std::ostream& os, const cpputils::debug::Printable& p);
std::ostream& operator<<(std::ostream& os, const cpputils::debug::Printable* p);

template<class T>
const char* dstr(T obj) {
	std::stringstream s;
	s << obj;
	return s.str().c_str();
}

#endif /* PRINT_H_ */
