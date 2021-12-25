/*******************************************************
 * @file ex15_15_Bulk_Quote.h
 * @author vleo
 * @date 2021.12.24
 * @remark Quote class 
 *******************************************************/

#ifndef CP5_EX15_15_BULK_QUOTE_H_
#define CP5_EX15_15_BULK_QUOTE_H_

#include "ex15_15_Disc_Quote.h"
#include <string>


namespace EX15{

    using std::string;

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default ;
    Bulk_quote(const string& b, double p, size_t q, double d) : Disc_quote(b, p, q, d) {}
    virtual double net_price(size_t cnt) const override {
        if(cnt >= quantity) return cnt * (1 - discount) * price;
        else return cnt * price;
    }
};

}

#endif // CP5_EX15_15_DISC_QUOTE_H_