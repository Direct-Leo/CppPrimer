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



int main()
{
    string temp ;
    vector<string> v;
    while (cin >> temp)
    {
        if(std::find(v.begin(), v.end(), temp) == v.end())
        {
            v.push_back(temp);
        }
    }
    
    

    return 0;
}