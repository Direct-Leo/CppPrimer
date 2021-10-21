/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_24
 * replace find_if with partition to rewrite biggies
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <functional>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;
using namespace std::placeholders;

vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

void elimDups(vector<string> &v)
{
    std::sort(v.begin(),v.end());
    auto unique_end = std::unique(v.begin(),v.end());
    v.erase(unique_end,v.end()); 
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz ;
}

void biggies(vector<string> &v, vector<string>::size_type sz)
{
    elimDups(v);
    std::stable_sort(v.begin(),v.end(),
                    [](const string &a,const string &b)            
                    { return a.size() < b.size(); });
    auto it = std::partition(v.begin(), v.end(), 
                            std::bind(check_size, _1, sz));

    auto count = v.end() - it;
    cout << "count: " << count << endl;
    std::for_each(it, v.end(),
                    [](const string &str)            
                    { cout << str << " " ;}); 

}


int main()
{
    biggies(vec,4);
    
    return 0;
}