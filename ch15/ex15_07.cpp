/*******************************************************
 * @file ex15_06.h
 * @author vleo
 * @date 2021.12.17
 * @remark limit_Bulk_quote class 
 *******************************************************/

#include "ex15_05.h"

class Limit_quote : public Quote{
public:
    Limit_quote() = default;
    Limit_quote(const string& book, double p, size_t qnt, double disc) : Quote(book, p), max_qnt(qnt), discount(disc) {}

    double net_price(size_t cnt) const override
    {
        if(cnt < max_qnt) return (1 - discount) * cnt * price; 
        else return (cnt - max_qnt) * price + max_qnt * (1 - discount) * price;
    }

protected:
    size_t max_qnt = 0;
    double discount = 0.0;

};






int main()
{
    Quote quote1("007", 10.0);
    EX05::Bulk_quote bk_quote1("005", 10.0, 5, 0.2);
    Quote& qt_ref = quote1;
    Quote* bkqt_pointer = &bk_quote1;

    print_total(std::cout, qt_ref, 50);
    print_total(std::cout, *bkqt_pointer, 50);
    return 0;
}