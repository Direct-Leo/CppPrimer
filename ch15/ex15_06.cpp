/*******************************************************
 * @file ex15_06.h
 * @author vleo
 * @date 2021.12.17
 * @remark Bulk_quote class 
 *******************************************************/

#include "ex15_05.h"




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