/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_48
 * 
 */ 

#include "ex13_50.h"
#include "ex13_50.cpp"
#include <iostream>
#include <vector>
using std::vector;
using std::cout; using std::endl;

int main()
{
    vector<String> v;
    //v.reserve(10); // if make it into effect, there won't have copy anymore.
    v.push_back(std::move("xiaofan"));
    v.push_back(std::move("xiaowang"));
    v.push_back(std::move("xiaoli"));
    

    return 0;
}