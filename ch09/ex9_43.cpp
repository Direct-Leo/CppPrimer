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

void func(string &str,string oldVal,string newVal)
{
    auto it = str.begin();
    while (it != str.end())
    {
        auto it_oldval = oldVal.begin();
        auto it_newval = newVal.begin();

        while(*it == *it_oldval && it_oldval != oldVal.end())
        {
            it = str.erase(it);
            ++it_oldval;
        }
        for (auto temp = oldVal.begin(); temp != oldVal.end(); ++temp)
        {
            it = str.insert(it,*temp);
        }
        

    }
    
}

int main()
{
    string test = "the tho value";
    func(test,"tho","thought");
    return 0;
}