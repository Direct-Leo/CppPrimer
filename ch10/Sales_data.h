#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

// struct Sales_data
// {
//     std::string bookNo;
//     unsigned units_sold = 50 ;
//     double revenue  = 6.0;

//     std::string isbn() const {return bookNo;}
//     Sales_data& combine(const Sales_data&);
//     double avg_price() const ;

//     //new constructor function
//     Sales_data() = default ;
//     Sales_data(const std::string &s) : bookNo(s){}
//     Sales_data(const std::string &s, unsigned n, double p) : bookNo(s),units_sold(n),revenue(n*p) {}
//     Sales_data(std::istream &);


// };

class Sales_data{

    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);

    public:
        // Sales_data() = default;
        // Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(n*p){}
        // Sales_data(const std::string &s) : bookNo(s){}
        // Sales_data(std::istream &is) { read(is,*this); }

        // delegating constructor
        Sales_data(const std::string &s,unsigned n,double p) : bookNo(s),units_sold(n),revenue(n*p) { std::cout << "3 parameters constructor started\n"; }
        Sales_data() : Sales_data("",0,0) { std::cout << "default construcor started\n" ;}
        explicit Sales_data(const std::string &s) : Sales_data(s,0,0) { std::cout << "one parameter(string) constructor started\n" ;}
        Sales_data(std::istream &is) : Sales_data("",0,0) {std::cout << "one parameter(istream) constructor started\n" ;read(is,*this) ;}


        std::string isbn() const { return bookNo; }
        Sales_data &combine(const Sales_data&);

    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0; 
        inline double avg_price()const {return units_sold ? revenue/units_sold : 0 ;}

};

Sales_data add(const Sales_data&, const Sales_data&) ;
std::ostream &print(std::ostream& ,const Sales_data&) ;
std::istream &read(std::istream&, Sales_data&);

#endif
