/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_13
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

vector<string> words{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

bool func(const string &str)
{
    return str.size() >= 5 ;
}

int main()
{
    auto it = std::partition(words.begin(),words.end(),func);
    for(auto temp = words.begin(); temp != it; ++temp)
    {
        cout << *temp << " ";
    }
    return 0;
}