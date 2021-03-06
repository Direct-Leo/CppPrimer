#ifndef CP5_STRBLOB_H
#define CP5_STRBLOB_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob{
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    //ex_14_16
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    // ex_14_18
    friend bool operator<(const StrBlob&, const StrBlob&) ;
    friend bool operator>(const StrBlob&, const StrBlob&) ;
    friend bool operator<=(const StrBlob&, const StrBlob&) ;
    friend bool operator>=(const StrBlob&, const StrBlob&) ;


public:
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){}

    //copy constructor and copy assignment
    StrBlob(const StrBlob& sb) : data(make_shared<vector<string>>(*sb.data)) {}
    StrBlob& operator=(const StrBlob&);
    // move constructor and move assignment 
    StrBlob(StrBlob&& rhs) noexcept : data(std::move(rhs.data)) {}
    StrBlob& operator=(StrBlob&&) noexcept;

    string& operator[](size_t n);
    const string& operator[](size_t n) const;

    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

    size_type size() const {return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& t) {data->push_back(t); }
    void push_back(string&& s) {data->push_back(std::move(s)); }

    void pop_back();
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;

private:
    void check(size_type, const string&) const;

    shared_ptr<vector<string>> data;

};

// ===========================================================
//
//            operator
//
// ===========================================================
bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);








inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

inline string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::check(size_type i, const string& msg) const
{
    if(i >= data->size()) throw std::out_of_range(msg);
}

inline string& StrBlob::operator[](size_t n)
{
    check(n, "out of range");
    return data->at(n);
}

inline const string& StrBlob::operator[](size_t n)const
{
    check(n, "out of range");
    return data->at(n);
}









class StrBlobPtr{
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

    string& deref() const;
    StrBlobPtr& incr();

    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int); 
    StrBlobPtr operator--(int); 
    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);
    StrBlobPtr operator+(size_t)const;
    StrBlobPtr operator-(size_t)const;


    string& operator[](size_t n);
    const string& operator[](size_t n) const;

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;

    std::weak_ptr<vector<string>> wptr;
    size_t curr;

};

// =======================================================
//
//              operators
//
// =======================================================
bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);






inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr old = *this;
    ++*this;
    return old;
}

inline StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr old = *this;
    --*this;
    return old;
}

inline StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

inline StrBlobPtr& StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator+(size_t n) const
{
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

inline StrBlobPtr StrBlobPtr::operator-(size_t n) const
{
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}





inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if(!ret) throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

inline string& StrBlobPtr::operator[](size_t n)
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

inline const string& StrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}


//===========================================
//
//      ConstStrBlobPtr 
//
//
//===========================================

class ConstStrBlobPtr{
    friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

    const string& operator*() const;
    const string* operator->() const;
    ConstStrBlobPtr& operator++();
    ConstStrBlobPtr& operator--();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr operator--(int);
    ConstStrBlobPtr& operator+=(size_t);
    ConstStrBlobPtr& operator-=(size_t);
    ConstStrBlobPtr operator+(size_t) const;
    ConstStrBlobPtr operator-(size_t) const;

    const string& operator[](size_t n) const;


private:
    std::shared_ptr<vector<string>> check(size_t, const string&) const;

    std::weak_ptr<vector<string>> wptr;
    size_t curr;

};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

inline const string& ConstStrBlobPtr::operator*() const{
    auto p = check(curr, "dereference past end");
    return(*p)[curr];
}

inline const string* ConstStrBlobPtr::operator->() const{
    return &this->operator*();
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{
    --curr;
    check(curr, "increment past begin of ConstStrBlobPtr");
    return *this;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of ConstStrBlobPtr");
    return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of ConstStrBlobPtr");
    return *this;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n) const
{
    ConstStrBlobPtr ret = *this;
    ret += n;
    return ret;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n) const
{
    ConstStrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

inline std::shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_t i, const string& msg) const{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

inline const string& ConstStrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}





#endif