/* Created by vleo on 21/11/29
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_39
 * my own HasPtr
 */ 

#include "ex13_49_StrVec.h"

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

StrVec::StrVec(StrVec&& s) noexcept : element(s.element),
                                      first_free(s.first_free),
                                      cap(s.cap)
{
    s.element = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
    if(this != &rhs)
    {
        free();
        element = rhs.element;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.element = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}