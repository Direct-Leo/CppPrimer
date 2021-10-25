/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_3
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

using std::string;
using std::map;
using std::vector;
using std::cout;using std::cin; using std::endl;


auto& addFamily(map<string, vector<string>> &mp, const string &family)
{
    vector<string> v;
    mp[family] = v;
    return mp;
}
auto& addChildren(map<string, vector<string>> &mp, const string &family, const string &child)
{
    mp[family].push_back(child);
    return mp;
}

int main()
{
    map<string, vector<string> > namemap;   
    string line ;
    while (std::getline(cin, line))
    {
        string family,child;
        std::istringstream is(line);
        is >> family ;
        addFamily(namemap, family);
        while (is >> child)
        {
            addChildren(namemap, family, child);
        }
        
    }
    

    return 0;
}