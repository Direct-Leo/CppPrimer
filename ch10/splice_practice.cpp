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

forward_list<int> flst1, flst2;


int main()
{
    flst1.insert_after(flst1.before_begin(), {0,1,2,3,4,5});
    flst2.insert_after(flst2.before_begin(), {7,8,9,10,11}) ;

    auto it = flst1.before_begin();
    auto it2 = flst2.before_begin();
    std::advance(it2, 3);
    
    flst1.splice_after(it,flst2,it2,flst2.end());

    return 0;
}