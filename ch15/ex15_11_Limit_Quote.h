/*******************************************************
 * @file ex15_11_Limit_Quote.h
 * @author vleo
 * @date 2021.12.24
 * @remark limit_Bulk_quote class 
 *******************************************************/

#ifndef CP5_EX15_11_LIMIT_QUOTE_H_
#define CP5_EX15_11_LIMIT_QUOTE_H_

#include "ex15_11_Bulk_Quote.h"
#include <string>

namespace EX11{
    using std::string;
    using std::cout; using std::endl;

class Limit_quote : public Bulk_quote{
public:
    Limit_quote() = default;
    Limit_quote(const string& book, double p, size_t qnt, size_t max, double disc) : Bulk_quote(book, p, qnt, disc), max_qnt(max){}

    double net_price(size_t cnt) const final override
    {
        if(cnt > max_qnt) return max_qnt * (1 - discount) * price + (cnt - max_qnt) * price;
        else if (cnt >= min_qty) return cnt * (1 - discount) * price;
        else return cnt * price;
    }

    virtual void debug() const final{
        Bulk_quote::debug();
        cout << "\tmax_qnt: " << max_qnt << endl;
    }

private:
    size_t max_qnt = 0;

};

}

#endif //CP5_EX15_11_LIMIT_QUOTE_H_