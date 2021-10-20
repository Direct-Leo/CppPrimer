/* practice 8.1
 * 2021.10.14 by vleo
 */

#include <iostream>
#include <string>
#include "Sales_data.h"
#include "Sales_data.cpp"

istream &func(istream &is)
{
    std::string str;
    is >> str;
    std::cout << str << std::endl;
    is.clear();
    return is;
} 

int main()
{
    if(std::cin)
    {
        Sales_data total(std::cin);
        while (std::cin)
        {
            Sales_data trans(std::cin);
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
            
        }
        print(std::cout ,total) << std::endl;
    }
    else
    {
        std::cerr << "No data!" << std::endl;
    }

    std::cout << "hello" << std::ends << "hi";

    return 0;
}