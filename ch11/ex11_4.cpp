/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_3
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using std::string;
using std::map;
using std::cout;using std::cin; using std::endl;



int main()
{
    map<string, string::size_type> word_count ;
    string word ;
    while (cin >> word)
    {
        for(auto &ch : word) ch = tolower(ch) ;
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end()) ;
        ++word_count[word];
    }
    

    return 0;
}