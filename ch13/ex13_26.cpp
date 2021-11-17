/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_26
 * 
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
    friend class StrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob() : data(std::make_shared<vector<string>>()) {} 
    StrBlob(initializer_list<string> il) :
            data(std::make_shared<vector<string>>(il)) {}
    
    // copy constructor
    StrBlob(const StrBlob& sb) : data(std::make_shared<vector<string>>(*sb.data)) {}

    // copy assignment operators
    StrBlob& operator=(const StrBlob& sb);

    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }

    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back() ;

    std::string& front();
    std::string& back();
    std::string& front() const;
    std::string& back() const;

    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() { auto ret = StrBlobPtr(*this, data->size());
                       return ret; }

private:

    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const
    {
        if(i >= data->size()) 
            throw std::out_of_range(msg);
    }
};


class StrBlobPtr{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0):
        wptr(a.data), curr(sz) {}
    std::string &deref() const;
    StrBlobPtr &incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
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

// assignment operator
StrBlob&
StrBlob::operator=(const StrBlob& sb)
{
    data = std::make_shared<vector<string>> (*sb.data);
    return *this;
}


std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg)const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string &StrBlobPtr::deref()const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

