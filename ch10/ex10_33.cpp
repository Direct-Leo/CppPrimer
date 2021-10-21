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

vector<int> v;


int main()
{
    std::ifstream myifstream("odd_and_even.txt");
    std::ofstream ofs_odd("odd.txt"),ofs_even("even.txt");


    std::istream_iterator<int> it(myifstream), ieof;
    std::ostream_iterator<int> out_odd(ofs_odd," "), out_even(ofs_even, "\n");

    std::for_each(it, ieof, [&out_odd, &out_even] (const int i){
        *(i & 0x1 ? out_odd : out_even)++ = i;
    });
    return 0;
}