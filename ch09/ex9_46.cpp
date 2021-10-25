/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_29
 * replace find_if with partition to rewrite biggies
 */ 

#include <string>
#include <iostream>
using std::string;

string func(string name, const string &front, const string &behind)
{
    string res(name);
    res.insert(0,front);
    res.insert(res.size(),behind);
    return res;
}


int main()
{
    string name = "xiaowang";
    name = func(name, "Mr.","III");
    return 0;
}