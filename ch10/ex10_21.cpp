/* Created by vleo on 21/10/21
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_21
 * lambda practice
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


int main()
{
    int val = 5;
    auto f = [&val] () ->bool {
        if(val != 0)
        {
            --val;
            return false ;
        }
        else
        {
            return true;
        }
    };
    while (!f())
    {
        cout << val << endl;
    }
    
    
    return 0;
}