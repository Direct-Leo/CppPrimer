/* Created by vleo on 21/10/22
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex9_43
 * replace find_if with partition to rewrite biggies
 */ 

#include <string>
#include <iostream>
using std::string;

void Replace(string &s, const string &oldval, const string &newval)
{
    for(auto beg = s.begin(); std::distance(beg, s.end()) >= 
                              std::distance(oldval.begin(), oldval.end());)
    {
        if(string{beg, beg + oldval.size()} == oldval)
        {
            beg = s.erase(beg, beg + oldval.size());
            beg = s.insert(beg, newval.cbegin(), newval.cend());
            std::advance(beg, newval.size());
        }
        else
            ++beg;
    }
}

int main()
{
    string str{"tho we are young, we need to go thru the dangerous path."};

    Replace(str,"tho","though");
    Replace(str, "thru","through");
    return 0;
}