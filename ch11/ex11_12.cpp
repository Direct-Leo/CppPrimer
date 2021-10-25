/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_3
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;using std::cin; using std::endl;
using std::pair;

vector<pair<string, int>> v;

int main()
{
    string str;
    int val;
    while (cin >> str)
    {
        cin >> val;
        v.push_back(std::make_pair(str, val));
    }

    return 0;
}