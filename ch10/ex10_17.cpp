#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"
#include "Sales_data.cpp"



int main()
{
    Sales_data sd1("java"),sd2("python"),sd3("C++");
    std::vector<Sales_data> v{sd1,sd2,sd3};
    std::sort(v.begin(),v.end(),[](const Sales_data &lhs, const Sales_data &rhs)
                                {return lhs.isbn() < rhs.isbn(); });
    return 0;
}