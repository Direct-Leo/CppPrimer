/*******************************************************
 * @file ex15_05.h
 * @author vleo
 * @date 2021.12.17
 * @remark Bulk_quote class 
 *******************************************************/

#ifndef EX15_05_H
#define EX15_05_H

#include "ex15_03.h"
#include <string>

namespace EX05{
    using std::string;
    using namespace EX03;

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

    virtual double net_price(size_t cnt) const 
    {
        if(cnt >= min_qty) return cnt * (1 - discount) * price;
        else return cnt * price;
    }


protected:
    size_t min_qty = 0;
    double discount = 0.0;

};

}
#endif