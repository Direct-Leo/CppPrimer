/* Created by vleo on 21/10/19
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * find a string in a forward_list to insert a string after it,
 * if not,insert a string to the end
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

vector<double> v{1.2,5.5,3.3,6.4};


int main()
{
    int sum = std::accumulate(v.cbegin(),v.cend(),0);
    cout << sum << endl; //sum is 15

    double dsum = std::accumulate(v.cbegin(),v.cend(),0.0);
    cout << dsum << endl; //sum is 16.4

    return 0;
}