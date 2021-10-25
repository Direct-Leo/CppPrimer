/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_38
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

using std::string;
using std::map;
using std::unordered_map;
using std::cout;using std::cin; using std::endl;



int main()
{
    unordered_map<string, string::size_type> word_count ;
    string word ;
    while (cin >> word)
    {
        ++word_count[word];
    }
    for(const auto &w : word_count )
    {
        cout << w.first << " occurs " << w.second 
        << ((w.second > 1) ? " times" : " time") << endl;
    }

    return 0;
}