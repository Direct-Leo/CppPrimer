/*******************************************************
 * @file ex15_25_cpp
 * @author vleo
 * @date 2021.12.26
 * @remark Quote class 
 *******************************************************/



#include <string>
using std::string;

class Quote {
public:
    Quote() = default;
    Quote(string const& b, double p) : bookNo(b), price(p) { }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    //Disc_quote() = default;
    Disc_quote(string const& b, double p, size_t q, double d) : Quote(b, p), quantity(q), discount(d){ }
    virtual double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(string const& book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) { }
    virtual double net_price(std::size_t cnt) const override {
        if (cnt >= quantity) return cnt * (1 - discount) * price;
        else return cnt * price;
    }
};

int main()
{
    Bulk_quote b_quote;
}