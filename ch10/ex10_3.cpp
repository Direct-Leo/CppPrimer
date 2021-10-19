/* Created by vleo on 21/10/19
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * use accumulate method to calculate 
 * the sum of a vector<int>'s element
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

vector<int> v{45,56,58,78,79,78,77,77,77,76,77,77,76};


int main()
{
    int sum = std::accumulate(v.cbegin(),v.cend(),0);

    cout << sum << endl; //sum is 931

    return 0;
}