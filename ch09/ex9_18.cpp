/* Created by vleo on 21/10/18
 * Copyright(c) 2021 vleo. All rights reserved 
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
    deque<string> dq;
    while (cin >> str)
    {
        dq.push_front(str);
    }
    for(deque<string>::iterator it = dq.begin(); it != dq.end(); ++it)
    {
        cout << *it << endl;
    }
    
    
    return 0;
}