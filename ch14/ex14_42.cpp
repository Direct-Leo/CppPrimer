/*******************************************************
 * @file ex14_40.cpp
 * @author vleo
 * @date 2021.12.15
 * @remark a string check Class
 *******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

int main()
{
    using namespace std::placeholders;

    std::vector<int> ivec{1, 111, 1111, 11111};
    int count = std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
    std::cout << count << std::endl;

    std::vector<std::string> svec{"pooh", "haha", "pooh", "asdd", "pooh"};
    auto found = std::find_if(svec.begin(), svec.end(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
    std::cout << *found << std::endl;

    std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));
    for(int i : ivec)
        std::cout << i << " ";

    return 0;

}



