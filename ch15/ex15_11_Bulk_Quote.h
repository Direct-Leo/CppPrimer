/*******************************************************
 * @file ex15_11_Bulk_Quote.h
 * @author vleo
 * @date 2021.12.24
 * @remark Bulk_quote class 
 *******************************************************/

#ifndef CP5_EX15_11_BULK_QUOTE_H_
#define CP5_EX15_11_BULK_QUOTE_H_

#include "ex15_11_Quote.h"
#include <string>

namespace EX11{
    using std::string;
    

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

    virtual double net_price(size_t cnt) const override
    {
        if(cnt >= min_qty) return cnt * (1 - discount) * price;
        else return cnt * price;
    }

    virtual void debug() const override{
        Quote::debug();
        cout << "\tminq_qty: " << min_qty << "\tdiscount: " << discount << endl;
    }

protected:
    size_t min_qty = 0;
    double discount = 0.0;

};

}
#endif