/*******************************************************
 * @file ex15_03.h
 * @author vleo
 * @date 2021.12.17
 * @remark Quote class and print_total function
 *******************************************************/

#ifndef EX15_03_H
#define EX15_03_H

#include <string>
#include <iostream>

inline namespace EX03{

    using std::string;
    using std::ostream; using std::endl;


class Quote{
public:
    Quote() = default;
    Quote(const string& b, double p) : bookNo(b), price(p) {}
    const string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;


private:
    string bookNo;

protected:
    double price = 0.0;

};

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << endl;
    return ret; 
}


}

#endif