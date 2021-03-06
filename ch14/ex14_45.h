/*******************************************************
 * @file ex14_40.cpp
 * @author vleo
 * @date 2021.12.16
 * @remark my own version of a simple desk calculator
 *******************************************************/

#ifndef CP5_ex14_45_h
#define CP5_ex14_45_h

#include <iostream>
#include <string>

// added conversion operators to convert a Sales_data to string and to double.
class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    Sales_data(const std::string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p)
    {
    }
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const std::string& s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(std::istream& is);

    Sales_data& operator=(const std::string&);
    Sales_data& operator+=(const Sales_data&);
    explicit operator std::string() const { return bookNo; } // to string
    explicit operator double() const { return avg_price(); } // to double
    
    operator const int() { return avg_price(); }

    std::string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

#endif