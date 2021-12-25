/*******************************************************
 * @file ex14_39.cpp
 * @author vleo
 * @date 2021.12.15
 * @remark a string check Class
 *******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class StringNumCheck{
public:
    StringNumCheck(size_t l = 0, size_t u = 0) : lower(l), upper(u) {}
    
    bool operator()(const std::string& s)
    {
        return s.length() >= lower && s.length() <= upper;
    }

private:
    size_t lower;
    size_t upper;
};

int main()
{
    std::ifstream fin("../data/ex14_38.txt");
    StringNumCheck test9(1,9);
    StringNumCheck test10(10,100);

    size_t q9 = 0,q10 = 0;
    for(std::string word; fin >> word;)
    {
        if(test9(word)) ++q9;
        if(test10(word)) ++q10;
    }

    std::cout << q9 << " " << q10;
    return 0;
}