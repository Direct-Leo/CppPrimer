/* Created by vleo on 21/10/18
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

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;

vector<int> v{45,56,58,78,79,78,77,77,77,76,77,77,76};


int main()
{
    int count = 0;
    count = std::count(v.begin(),v.end(),77);
    cout << count << endl;
    return 0;
}