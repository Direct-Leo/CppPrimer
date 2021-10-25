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
using std::multimap;


int main()
{
    multimap<string, string> authors{
        {"xiaofan", "CPP"},
        {"xiaofan", "python"},
        {"xiaoli","JAVA"},
        {"xiaofan","c#"}
    };

    string author = "xiaofan";
    string work = "CPP";
    for(auto found = authors.find(author); found != authors.end() && found->first == author;)
    {
        if(found->second == work)
        {
            found = authors.erase(found);
        }
        else
        {
            ++found;
        }
        
    }
    return 0;
}