/*******************************************************
 * @file ex14_37.cpp
 * @author vleo
 * @date 2021.12.12
 * @remark a IsEqual Class
 *******************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

class IsEqual{
public:
    IsEqual(int v) : value(v) {}
    bool operator()(int elem) { return elem == value; }

private:
    int value;
};

int main()
{
    std::vector<int> v = {3, 4, 3, 5, 7};
    std::replace_if(v.begin(), v.end(), IsEqual(3), 8);
    for(auto i : v)
        std::cout << i << " ";
    return 0;
}