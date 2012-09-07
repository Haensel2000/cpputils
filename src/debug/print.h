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
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;

ostream& operator<<(ostream& os, const std::string& s);

template<class T>
ostream& operator<<(ostream& os, vector<T> v) {
	typename vector<T>::iterator first = v.begin();
	if (first != v.end()) {
		os << *first;
		for (typename vector<T>::iterator i = ++first;
				i != v.end(); ++i) {
			os << *i << ", ";
		}
	}
	return os;
}

namespace cpputils {

namespace debug {



}

}

#endif /* PRINT_H_ */
