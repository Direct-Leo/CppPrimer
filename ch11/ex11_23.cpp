/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_13
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using std::vector;
using std::string;
using std::cout;using std::cin; using std::endl;
using std::pair;
using std::multimap;


int main()
{
    multimap<string, string> families;
    for(string lastName,childName; cin >> lastName >> childName ;
        families.emplace(lastName,childName))
        ;
    

    return 0;
}