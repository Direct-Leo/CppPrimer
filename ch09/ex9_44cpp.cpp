/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_29
 * replace find_if with partition to rewrite biggies
 */ 

#include <string>
#include <iostream>
using std::string;

void Replace(string &s, const string &oldval, const string &newval)
{
    for(string::size_type i = 0; i != s.size(); ++i)
    {
        if(s.substr(i,oldval.size()) == oldval)
        {
            s.replace(i, oldval.size(), newval);
            i += newval.size();
        }
    }
}

int main()
{
    string str{"tho we are young, we need to go thru the dangerous path."};

    Replace(str,"tho","though");
    Replace(str, "thru","through");
    return 0;
}