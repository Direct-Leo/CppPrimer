/* Created by vleo on 21/10/23
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex9_47_2
 * "find_first_not of" practice
 */ 

#include <string>
#include <iostream>
#include <fstream>
using std::string;
using std::cout;using std::cin; using std::endl;



int main()
{
    string::size_type pos = 0;
    string ascender = "bdfhijkltABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    string descender = "gjpqy" ;

    std::ifstream ifs("word.txt");
    if(!ifs) return -1;
    string res;
    for(string temp; ifs >> temp; )
    {
        if(temp.find_first_not_of(ascender) != string::npos && 
           temp.find_first_not_of(descender) != string::npos &&
           temp.size() > res.size())
           res = temp;
    }
    cout << res << endl;

    return 0;
}