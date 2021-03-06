/********************************************************
 * @file ex15_30_Basket_h
 * @author vleo
 * @date 2022.1.14
 * @remark 
 ********************************************************/

#ifndef CP5_EX15_30_BASKET_H
#define CP5_EX15_30_BASKET_H

#include <memory>
#include <set>
#include "ex15_30_Quote_Bulk_quote.h"

namespace EX30{
    using std::shared_ptr;

    class Basket{
    public:
        Basket() = default;
        void add_item(const Quote& sale) { items.insert(shared_ptr<Quote>(sale.clone())); }
        void add_item(Quote&& sale) { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }
        inline double total_receipt(std::ostream&) const;
    private:
        static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs){
            return lhs->isbn() < rhs->isbn();
        }
        std::multiset<shared_ptr<Quote>, decltype(compare)*> items{compare} ;
    };

    inline double Basket::total_receipt(std::ostream &os) const {
        auto sum = 0.0;
        for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
            sum += print_total(os, **iter, items.count(*iter));
        }
        os << "Total Sale: " << sum << endl;
        return sum;
    }
}


#endif