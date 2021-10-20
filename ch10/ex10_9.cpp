/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * implement my elimDups
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;

vector<string> vec;

void elimDups(vector<string> &words)
{
    string temp;
    while (cin >> temp)
    {
        words.push_back(temp);
    }
    // after cin:
    cout << "after cin : ";
    for(auto str : words)
    {
        cout << str << " ";
    }
    cout << endl ;

    // after sort:
    sort(words.begin(),words.end());
    cout << "after sort : " ;
    for(auto str : words)
    {
        cout << str << " " ;
    }
    cout << endl ;
    
    // after unique:
    auto end_unique = std::unique(words.begin(),words.end());
    cout << "after unique: ";
    for(auto str : words)
    {
        cout << str << " ";
    }
    cout << endl;

    // after erase:
    words.erase(end_unique,words.end());
    cout << "after erase: ";
    for(auto str : words)
    {
        cout << str << " ";
    }
}

int main()
{
    elimDups(vec);
    return 0;
}