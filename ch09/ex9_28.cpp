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

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;

void func(forward_list<string> &flst,string str1,string str2)
{
    auto pre = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if(*curr == str1)
        {
            flst.insert_after(curr,str2);
            return;
        }
        pre =  curr;
        ++curr;
    }
    flst.insert_after(pre,str2);
    return;
}

int main()
{
    string str1 = "xiaofan";
    string str2 = "xiaowei";
    forward_list<string> flst{"xiaogao","xiaozhao","xiaozheng","xiaofang","xiaoliu"};
    func(flst,str1,str2);

    return 0;
}