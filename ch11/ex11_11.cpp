/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_3
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include "Sales_data.h"
#include "Sales_data.cpp"

using std::string;
using std::cout;using std::cin; using std::endl;
using std::pair;

//using cmpType = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
typedef bool (*cmpType)(const Sales_data &lhs, const Sales_data &rhs) ;


bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    std::multiset<Sales_data, cmpType> bookstore(compareIsbn);


    return 0;
}