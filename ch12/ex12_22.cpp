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
#include <iostream>
#include <fstream>
#include <sstream>

using std::vector;
using std::string;
using std::initializer_list;

class ConstStrBlobPtr;

class StrBlob{
    friend class ConstStrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);
    
    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }

    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back() ;

    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;

    ConstStrBlobPtr begin() const; 
    ConstStrBlobPtr end() const;

private:

    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const ;
};


class ConstStrBlobPtr{
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0):
        wptr(a.data), curr(sz) {}
    const std::string& deref() const;
    ConstStrBlobPtr& incr();

    bool operator!=(ConstStrBlobPtr& p){ return p.curr != curr; } //operator overload
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


StrBlob::StrBlob() : data(std::make_shared<vector<string>>()) {} 
StrBlob::StrBlob(initializer_list<string> il) :
            data(std::make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const std::string& msg)const{
    if(i >= data->size())
        throw std::out_of_range(msg);
}

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
const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
const string& StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const
{
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg)const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

const std::string& ConstStrBlobPtr::deref()const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


