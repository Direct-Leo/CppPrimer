/* Created by vleo on 21/10/25
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex12_2
 * "word counter" practice
 */ 

/*  两个类放入一个文件时, 如果包含内联函数, 及友元(friend)类,
 *  则函数放置的顺序尤为重要, 类的前置声明(class forward declaration)也需要注意.
 *  否则会产生编译错误: 不完整的类声明(incomplete class declarations)
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

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
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
    std::string& front() const;
    std::string& back() const;

    StrBlobPtr begin(); 
    StrBlobPtr end();

private:

    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const ;
};


class StrBlobPtr{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0):
        wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();

    bool operator!=(const StrBlobPtr& p){ return p.curr != curr; } //operator overload
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

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
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

std::string& StrBlobPtr::deref()const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

int main()
{
    StrBlob SBL ;
    string line,word;
    std::ifstream ifs("lines.txt");
    while (getline(ifs,line))
    {
        std::istringstream iss(line);
        while (iss >> word)
        {
            SBL.push_back(word);
        }
    }
    for(StrBlobPtr pbeg(SBL.begin()), pend(SBL.end()); pbeg != pend; pbeg.incr())
    {
        std::cout << pbeg.deref() << " ";
    }
    

    return 0;
}
