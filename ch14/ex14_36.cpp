/*******************************************************
 * @file ex14_36.cpp
 * @author vleo
 * @date 2021.12.12
 * @remark a PrintString Class
 *******************************************************/

#include <iostream>
#include <string>
#include <vector>

class GetInput{
public:
    GetInput(std::istream& i = std::cin) : is(i) {}
    std::string operator()() const
    {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    }

private:
    std::istream& is;

};

int main()
{
    GetInput gtipt;
    std::vector<std::string> v;
    for(std::string temp; !(temp = gtipt()).empty();) v.push_back(temp);
    for(const auto& str : v)
        std::cout << str << " ";
    std::cout << std::endl;
    return 0;
}
