/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_13
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "Sales_data.h"
#include "Sales_data.cpp"

using std::vector;
using std::string;
using std::cout;using std::cin; using std::endl;
using std::pair;
using std::multiset;

multiset<Sales_data, bool(*)(const Sales_data &lhs, const Sales_data &rhs) > bookStore;

int main()
{
    
    multiset<Sales_data, bool(*)
    (const Sales_data &lhs, const Sales_data &rhs)>::
    iterator it = bookStore.begin();

    return 0;
}