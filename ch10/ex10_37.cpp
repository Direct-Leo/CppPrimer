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

vector<int> v{0,1,2,3,4,5,6,7,8,9};
vector<int> v1(5);

int main()
{
    std::reverse_copy(v.cbegin() + 3, v.cbegin() + 7, v1.begin()) ;
    return 0;
}