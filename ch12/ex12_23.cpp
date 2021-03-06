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
    const char* c1 = "Hello ";
    const char* c2 = "World";
    unsigned len =  strlen(c1) + strlen(c2) +1;
    char* r = new char[len]();
    strcat_s(r, len, c1);
    strcat_s(r, len, c2);
    std::cout << r << std::endl;

    ///// string
    std::string s1 = "Hello ";
    std::string s2 = "World";
    strcpy_s(r, len, (s1+s2).c_str());
    std::cout << r << std::endl;

    delete[] r;
    return 0;
}
