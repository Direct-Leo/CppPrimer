/* Created by vleo on 21/10/25
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex12_2
 * "word counter" practice
 */ 

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using std::vector;
using std::string;
using std::initializer_list;


class StrBlob{
public:
    using size_type = vector<string>::size_type;

    StrBlob() : data(std::make_shared<vector<string>>()) {} 
    StrBlob(initializer_list<string> il) :
            data(std::make_shared<vector<string>>(il)) {}
    
    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }

    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back() ;

    std::string& front();
    std::string& back();
    std::string& front() const;
    std::string& back() const;

private:

    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const
    {
        if(i >= data->size()) 
            throw std::out_of_range(msg);
    }
};

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}
string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}





