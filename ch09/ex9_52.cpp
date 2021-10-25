/* Created by vleo on 21/10/23
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex9_52
 * "find_first_not of" practice
 */ 

#include <string>
#include <iostream>
#include <vector>
#include <stack>
using std::string;
using std::vector;
using std::stack;
using std::cout;using std::cin; using std::endl;



int main()
{
    auto &expr = "This is (Fan(handsome)((((wowowo))))) and (owow) over" ;
    auto repl = '#';
    auto seen = 0;
    stack<char> stk;
    
    for(auto c : expr)
    {
        stk.push(c);
        if(c == '(')
            ++seen;
        if(seen && c == ')')
        {
            while (stk.top() != '(')
            {
                stk.pop();
            }
            stk.pop();
            stk.push(repl);
            --seen;
            
        }
    }

    return 0;
}