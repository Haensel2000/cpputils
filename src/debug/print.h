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
#include <set>
#include <map>

using std::string;
using std::vector;
using std::set;
using std::ostream;

ostream& operator<<(ostream& os, const std::string& s);

namespace cpputils {

namespace debug {

template<class Container>
void print(ostream& os, const Container& v, const char* delim) {
	typename Container::const_iterator first = v.begin();
	if (first != v.end()) {
		os << *first;
		for (typename Container::const_iterator i = ++first; i != v.end();
				++i) {
			os << delim << *i;
		}
	}
}

class Printable {
public:

	virtual ~Printable() {
	}

	virtual void print(std::ostream& os) const = 0;

	const char* toStr() const;

};

}

}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	cpputils::debug::print(os, v, ", ");
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const set<T>& v) {
	cpputils::debug::print(os, v, ", ");
	return os;
}

template<class K, class V>
ostream& operator<<(ostream& os, const std::map<K, V>& v) {
	os << "{";
	typename std::map<K, V>::const_iterator first = v.begin();
	if (first != v.end()) {
		os << first->first << " : " << first->second;
		for (typename std::map<K, V>::const_iterator i = ++first; i != v.end();
				++i) {
			os << ", " << i->first << " : " << i->second;
		}
	}
	os << "}";
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
