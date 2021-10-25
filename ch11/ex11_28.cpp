/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_13
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using std::vector;
using std::string;
using std::cout;using std::cin; using std::endl;
using std::pair;
using std::map;


int main()
{
    map<int, vector<int>> mp;
    mp.emplace(58,26);
    map<int, vector<int>>::iterator it_mp = mp.find(58);

    return 0;
}