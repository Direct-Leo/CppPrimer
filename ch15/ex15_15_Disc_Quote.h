/*******************************************************
 * @file ex15_15_Disc_Quote.h
 * @author vleo
 * @date 2021.12.24
 * @remark Quote class 
 *******************************************************/

#ifndef CP5_EX15_15_DISC_QUOTE_H_
#define CP5_EX15_15_DISC_QUOTE_H_

#include "ex15_03.h"
#include <string>


namespace EX15{

    using std::string;

class Disc_quote : public EX03::Quote {
public:
    Disc_quote() = default ;
    Disc_quote(const string& b, double p, size_t q, double d) : EX03::Quote(b, p), quantity(q), discount(d) {}
    virtual double net_price(size_t) const = 0;

protected:
    size_t quantity = 0;
    double discount = 0.0;
};



}

#endif // CP5_EX15_15_DISC_QUOTE_H_