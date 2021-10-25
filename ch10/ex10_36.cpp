/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_29
 * replace find_if with partition to rewrite biggies
 */ 

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list ;
using std::forward_list;

list<int> lst{0,1,2,3,0,5,6,9,7};


int main()
{
    auto found = std::find(lst.rbegin(),lst.rend(),0);
    cout << *found << " in front of " << *found.base() << endl;

    return 0;
}