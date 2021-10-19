/* Created by vleo on 21/10/18
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * delete even numbers from a vector,delete odd numbers from a list
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;

void delete_even_numbers(vector<int> &vec)
{
    auto it = vec.begin();
    while (it != vec.end())
    {
        if(*it % 2 == 0)
        {
            it = vec.erase(it);
        }
        else
            ++it;
    }
    
}
void delete_odd_numbers(list<int> &lst)
{
    auto it = lst.begin();
    while (it != lst.end())
    {
        if(*it % 2 != 0)
        {
            it = lst.erase(it);
        }
        else
            ++it;
    }
    
}


int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int>v;
    list<int> lst;
    v.assign(std::begin(ia),std::end(ia));
    lst.assign(std::begin(ia),std::end(ia));
    delete_even_numbers(v);
    delete_odd_numbers(lst);

    return 0;
}