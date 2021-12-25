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

    
    auto data = {2, 6, 4, 8};
    int input;
    std::cin >> input;
    std::modulus<int> mod;

    auto predicator = [&](int i) { return mod(i, input) == 0 ; };

    auto is_divisiable = std::all_of(data.begin(), data.end(), predicator); 
    std::cout << (is_divisiable ? "yes" : "no") << std::endl;

    return 0;

}



