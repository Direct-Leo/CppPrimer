/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_3
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using std::string;
using std::map;
using std::vector;
using std::list;
using std::cout;using std::cin; using std::endl;
using std::pair;


vector<int> vi;

int main()
{
    //ex 11_9
    map<string, list<std::size_t> > mp;

    //ex 11_10
    map<vector<int>::iterator, int> mv;
    map<list<int>::iterator, int> ml;

    mv.insert(pair< vector<int>::iterator, int > (vi.begin(), 0)) ;

    //"<"operation has not been defined,so it is wrong
    list<int> li;
    ml.insert(pair<list<int>::iterator, int> (li.begin(), 0)); 

    return 0;
}