/* Created by vleo on 21/10/25
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex12_2
 * "word counter" practice
 */ 

#include <iostream>
#include <string>
#include <cstring>


int main()
{
    std::string a;
    std::cin >> a;
    char* p = new char[2];
    strcpy(p, a.c_str());
    std::cout << p << std::endl;
    delete []p; // delete will be failed if the size is bigger than 2
    return 0;
}
