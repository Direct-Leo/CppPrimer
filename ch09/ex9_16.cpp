/*  @file   Exercise9.16
 *  @author vleo
 *  @date   2021.10.17 
 */

#include <iostream>
#include <vector>
#include <string>
#include <list>

using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;
using std::list;
int i = 0;

bool compare(list<int>& lst,vector<int>& v)
{
    for(auto it_list = lst.begin();it_list != lst.end(); ++it_list)
    {
        auto it_vec = v.begin() + i;
        if(*it_list != *it_vec)
        {
            return false;
        }
        ++i;
    }
    return true;
}


int main()
{
    list<int> lst{4,5,6,7,8,9};
    vector<int> v{4,5,6,7,8,9};
    cout << std::boolalpha << compare(lst,v);
    
    return 0;
}