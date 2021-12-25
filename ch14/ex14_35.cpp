/*******************************************************
 * @file ex14_35.cpp
 * @author vleo
 * @date 2021.12.12
 * @remark a PrintString Class
 *******************************************************/

#include <iostream>
#include <string>


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
    std::cout << gtipt() << std::endl;
    return 0;
}
