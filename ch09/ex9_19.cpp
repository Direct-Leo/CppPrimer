/* Created by vleo on 21/10/18
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * Rewrite the program from the previous exercise to use a list
 */ 


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
using std::deque;

int main()
{
    string str;
    list<string> lst;
    while (cin >> str)
    {
        lst.push_front(str);
    }
    for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << endl;
    }
    
    
    return 0;
}