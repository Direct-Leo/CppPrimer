/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_29
 * replace find_if with partition to rewrite biggies
 */ 

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list ;

vector<string> v;


int main()
{
    std::ifstream in("afile.txt");
    std::istream_iterator<string> str_it(in), eof;
    while (str_it != eof)
    {
        v.push_back(*str_it++);
    }
    

    return 0;
}