/*
 * main.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: hannes
 */

#include <iostream>
#include <vector>
#include <debug/print.h>
//extern NBlock* programBlock;
//extern int yyparse();

using std::vector;

void test()
{
    std::cout << string("Hello World!") << std::endl;

    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    std::cout << v << std::endl;
}


