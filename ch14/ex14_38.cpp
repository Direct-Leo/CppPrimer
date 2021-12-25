/*******************************************************
 * @file ex14_38.cpp
 * @author vleo
 * @date 2021.12.14
 * @remark a string check Class
 *******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class StringNumCheck{
public:
    StringNumCheck(size_t len = 0) : len(len) {}
    

    bool operator()(const std::string& s)
    {
        return s.length() == len ;
    }

private:
    size_t len;
};

int main()
{
    std::ifstream fin("../data/ex14_38.txt");
    int count[11] = {0} ;
    std::string word ;
    while (fin >> word)
    {
        StringNumCheck test(word.length());
        if(test(word))
            ++count[word.length()];
    }
    
    for(auto it = std::begin(count) + 1; it != std::end(count); ++it)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}