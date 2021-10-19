/* Created by vleo on 21/10/19
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * check the program and fix it
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

vector<int> vec;
list<int> lst;


int main()
{
    /// (a)
    int i;
    while (cin >> i)
    {
        lst.push_back(i);
    }
    std::copy(lst.cbegin(),lst.cend(),vec.begin());
    /* Fixed: add 'vec.resize(lst.size());'
     *    or: use 'copy(lst.cbegin(), lst.cend(), back_inserter(vec));'
     */

    /// (b)
    vector<int>v;
    v.reserve(10);
    std::fill_n(v.begin(),10,0);

    /* Fixed: use 'v.resize(10)'
     *    or: use 'fill_n(std::back_inserter(v),10,0)'
     */
    return 0;
}