/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_11
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

vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
vector<string> vec1 = vec;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &v)
{
    std::sort(v.begin(),v.end());
    auto unique_end = std::unique(v.begin(),v.end());
    v.erase(unique_end,v.end()); 
}

int main()
{
    elimDups(vec);
    std::stable_sort(vec.begin(),vec.end(),isShorter);

    elimDups(vec1);
    std::sort(vec1.begin(),vec1.end(),isShorter);
    return 0;
}