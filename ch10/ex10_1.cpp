/* Created by vleo on 21/10/19
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * calculate a given value's number of occurrences 
 * in a vector
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;

vector<int> v;


int main()
{
    int count = 0;
    int temp,val;

    while (cin >> temp)
    {
        v.push_back(temp);
    }
    cin >> val;
    count = std::count(v.begin(),v.end(),val);

    cout << count << endl;
    return 0;
}