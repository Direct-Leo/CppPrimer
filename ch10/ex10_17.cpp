#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"
#include "Sales_data.cpp"

bool compareIsbn(const Sales_data &sd1,const Sales_data &sd2)
{
    return (sd1.isbn() < sd2.isbn());
}

int main()
{
    Sales_data sd1("java"),sd2("python"),sd3("C++");
    std::vector<Sales_data> v{sd1,sd2,sd3};
    std::sort(v.begin(),v.end(),compareIsbn);
    return 0;
}