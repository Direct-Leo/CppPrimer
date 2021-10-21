/* Created by vleo on 21/10/20
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex10_27
 * unique_copy practice
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
using namespace std::placeholders;

vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
list<string> lst ;


int main()
{
    std::sort(vec.begin(),vec.end()); // important,without sort,unique_copy will be invalid
    std::unique_copy(vec.begin(), vec.end(), std::inserter(lst, lst.begin() ));

    return 0;
}