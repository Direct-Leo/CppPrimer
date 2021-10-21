/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_24
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

vector<int> vecint{4,5,3,2,4,7,8,9,10};

bool check_size(const int &val, const string &s)
{
    return val > s.size();
}

int main()
{
    string str = "xiaofan";
    auto it = std::find_if(vecint.begin(), vecint.end(), std::bind(check_size, _1, str)) ;
    cout << *it << endl;
    
    return 0;
}