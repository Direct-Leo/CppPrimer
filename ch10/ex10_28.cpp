/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_28
 * unique_copy practice
 */ 

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list ;
using std::deque;
using namespace std::placeholders;

vector<int> v{0,1,2,3,4,5,6,7,8,9};
list<int> lst ;
deque<int> dq;
vector<int> vcp;


int main()
{
    std::copy(v.begin(), v.end(), std::back_inserter(lst)) ;
    std::copy(v.begin(), v.end(), std::front_inserter(dq)) ;
    std::copy(v.begin(), v.end(), std::inserter(vcp,vcp.end())) ;


    return 0;
}