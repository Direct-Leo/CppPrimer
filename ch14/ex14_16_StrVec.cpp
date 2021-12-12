/* Created by vleo on 21/12/8
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex14_16_StrVec
 * 
 */ 

#include "ex14_16_StrVec.h"
#include <algorithm>

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b,
                                                           const std::string* e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
    if(element)
    {
        for(auto p = first_free; p != element;) alloc.destroy(--p);
        alloc.deallocate(element, cap - element);
    }
}

StrVec::StrVec(const StrVec& rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    element = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    element = data.first;
    first_free = cap = data.second ;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = element;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    element = newdata;
    first_free = dest;
    cap = element + new_cap;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap)
{
    if(new_cap <= capcity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string& s)
{
    if(count > size())
    {
        if(count > capcity()) reserve(count * 2);
        for(size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    }
    else if(count < size())
    {
        while(first_free != element + count) alloc.destroy(--first_free);
    }
}


/*  ==============================================
 *
 *          operator
 * 
 * ===============================================
 */

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
    return(lhs.size() == rhs.size() &&
           std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end());
}

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs < rhs);
}

bool operator<=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs > rhs);
}

StrVec& StrVec::operator=(const std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(),il.end());
    free();
    element = data.first;
    first_free = data.second;
    return *this;
}