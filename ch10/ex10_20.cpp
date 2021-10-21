/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_18
 * replace find_if with partition to rewrite biggies
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

vector<string> vec{"the","quick","redredred","xiaowang","jumps","over","the","slow","red","turtle"};



int main()
{
    auto count = std::count_if(vec.begin(), vec.end(), 
                            [](string &str)
                            { return str.size() > 6;} );
    return 0;
}