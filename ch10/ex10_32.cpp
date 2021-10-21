#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
//#include "Sales_data.h"
//#include "Sales_data.cpp"
#include "Sales_item.h"

// bool compareIsbn(const Sales_data &sd1,const Sales_data &sd2)
// {
//     return (sd1.isbn() < sd2.isbn());
// }

std::vector<Sales_item> v;

int main()
{
    Sales_item temp;
    std::istream_iterator<Sales_item> in_it(std::cin),eof;
    while (in_it != eof)
    {
        v.push_back(*in_it++);
    }
    
    std::sort(v.begin(),v.end(),compareIsbn);

    for(auto beg = v.begin(), end = beg; beg != v.end(); beg = end)
    {
        end = std::find_if(beg,v.end(), [beg](const Sales_item &item){
            return item.isbn() != beg->isbn();
        });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) ;
    }
    return 0;
}