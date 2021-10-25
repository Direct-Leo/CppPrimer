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

using std::vector;
using std::string;
using std::cout;using std::cin; using std::endl;
using std::pair;

vector<pair<string, int>> v1,v2,v3,v4;

int main()
{
    string str;
    int val;
    // while (cin >> str)
    // {
    //     cin >> val;
    //     v1.push_back(std::make_pair(str, val));
    // }
    // while (cin >> str)
    // {
    //     cin >> val;
    //     v2.push_back(pair<string, int>(str,val)) ;
    // }
    // while (cin >> str)
    // {
    //     cin >> val;
    //     v3.push_back(pair<string, int>{str,val}) ;
    // }
    
    while (cin >> str >> val)
    {
        v4.emplace_back(str, val);
    }
    
    

    return 0;
}