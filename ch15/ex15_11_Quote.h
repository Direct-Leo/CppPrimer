/*******************************************************
 * @file ex15_11_Quote.h
 * @author vleo
 * @date 2021.12.24
 * @remark Quote class 
 *******************************************************/

#ifndef CP5_EX15_11_QUOTE_H_
#define CP5_EX15_11_QUOTE_H_

#include <string>
#include <iostream>

namespace EX11{

    using std::string;
    using std::ostream; using std::endl; using std::cout;


class Quote{
public:
    Quote() = default;
    Quote(const string& b, double p) : bookNo(b), price(p) {}
    const string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const { return n * price; }

    virtual void debug() const { cout << "data members: \n" << "\tbookNo: " << bookNo << "\tprice: " << price << endl; }
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