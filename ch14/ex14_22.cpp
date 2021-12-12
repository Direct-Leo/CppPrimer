/* Created by vleo on 21/12/12
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex14_22
 * 
 */ 

#include "ex14_22.h"

Sales_data::Sales_data(std::istream& is) : Sales_data()
{
    is >> *this;
}

std::istream& operator>>(std::istream& is, Sales_data& item)
{
    double price = 0.0f;
    is >> item.bookNo >> item.units_sold >> price;
    if(is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
       << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}

Sales_data& Sales_data::operator=(const std::string& isbn)
{
    *this = Sales_data(isbn);
    return *this;
}