/* Created by vleo on 21/10/23
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex9_47_2
 * "find_first_not of" practice
 */ 

#include <string>
#include <iostream>
using std::string;
using std::cout;using std::cin; using std::endl;



int main()
{
    string::size_type pos = 0;
    string str = "ab2c3d7R4E6";
    string numbers = "0123456789" ;
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"} ;
    while ( (pos = str.find_first_not_of(alphabet, pos)) != string::npos )
    {
        cout << "find a numeric character from str, it is " << str[pos] << endl ;
        ++pos ;
    }
    pos = 0;
    while ( (pos = str.find_first_not_of(numbers, pos)) != string::npos )
    {
        cout << "find a alphabetic character from str, it is " << str[pos] << endl ;
        ++pos ;
    }
    

    return 0;
}