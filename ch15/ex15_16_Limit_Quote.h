/*******************************************************
 * @file _ex15_15_Limit_Quote.h
 * @author vleo
 * @date 2021.12.24
 * @remark Quote class 
 *******************************************************/

#ifndef CP5_EX15_16_LIMIT_QUOTE_H_
#define CP5_EX15_16_LIMIT_QUOTE_H_

#include "ex15_15_Disc_Quote.h"
#include <string>


namespace EX16{

    using std::string;
    using std::cout; using std::endl;
    using namespace EX15;

class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const string& book, double p, size_t min, size_t max, double dist) : Disc_quote(book, p, min, dist), max_qty(max){}

    double net_price(size_t cnt) const final override{
        if(cnt > max_qty) return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
        else if (cnt >= quantity) return cnt * (1 - discount) * price;
        else return cnt * price;
    }

private:
    size_t max_qty = 0;

};



}

#endif // CP5_EX15_15_DISC_QUOTE_H_