/* Created by vleo on 21/10/19
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * use fill_n func to fill a vector 
 * with the integer 0
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;

vector<int>v{0,1,2,3,4,5,6,7,8,9,10};


int main()
{
    std::fill_n(v.begin(),v.size(),0);
    
    return 0;
}