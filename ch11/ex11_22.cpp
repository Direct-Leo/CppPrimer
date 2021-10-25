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
    std::map<string, vector<int>> mp;
    vector<int> v{4,5,6};
    mp.insert({"xiaofan",v}) ;
    std::map<string, vector<int> >::iterator it = mp.begin();

    // parameter : pair<string, vector<int> >
    // return : pair<map<string, vector<int>>::iterator, bool>

    return 0;
}