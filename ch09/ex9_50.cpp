/* Created by vleo on 21/10/23
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex9_47_2
 * "find_first_not of" practice
 */ 

#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::vector;
using std::cout;using std::cin; using std::endl;



int main()
{
    vector<string> v{"4","5","4","8","9","78"};
    int res = 0;
    double fres = 0.0;
    for(auto str : v)
    {
        res += std::stoi(str);
        fres += std::stod(str);
    }
    return 0;
}