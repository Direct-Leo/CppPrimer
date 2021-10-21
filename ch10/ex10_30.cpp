/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_29
 * replace find_if with partition to rewrite biggies
 */ 

#include <iostream>
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

vector<int> v;


int main()
{
    std::istream_iterator<int> it(cin), eof;
    while (it != eof)
    {
        v.push_back(*it++);
    }
    std::sort(v.begin(),v.end());
    // version 1:
    std::ostream_iterator<int> it_out(cout," ");
    // for(auto i : v)
    // {
    //     *it_out++ = i;
    // }

    // version 2:
    std::copy(v.begin(),v.end(),it_out);
    return 0;
}