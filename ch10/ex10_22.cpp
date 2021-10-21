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
#include <functional>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;
using namespace std::placeholders;

vector<string> vec{"the","quick","redredred","xiaowang","jumps","over","the","slow","red","turtle"};

bool check_size(const string &s, string::size_type sz)
{
    return s.size() > sz;
}

int main()
{
    string::size_type sz = 6;
    auto count = std::count_if(vec.begin(), vec.end(), std::bind(check_size,_1,sz));
    
    
    return 0;
}