/* Created by vleo on 21/10/18
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * calculate a given value's number of occurrences 
 * in a list
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;
using std::forward_list;

list<string> lst;


int main()
{
    int count = 0;
    string temp,word;

    while (cin >> temp)
    {
        lst.push_back(temp);
    }
    cin >> word;
    count = std::count(lst.begin(),lst.end(),word);

    cout << count << endl;
    return 0;
}