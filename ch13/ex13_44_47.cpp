#include "ex13_44_47.h"
#include <algorithm>
#include <iostream>

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)} ;
}

void String::range_initializer(const char* first, const char* last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char* s)
{
    char* sl = const_cast<char*>(s);
    while(*sl)
    {
        ++sl;
    }
    range_initializer(s, ++sl); //注意。这里++sl,最终指针指向了[x][i][a][o][f][a][n][\0][这个位置]
}

String::String(const String& rhs)
{
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

String::String(String&& rhs) : elements(rhs.elements), end(rhs.end)
{
    std::cout << "no copy " << std::endl;
    rhs.elements = rhs.end = nullptr;
}

String& String::operator=(String && rhs)
{
    if(this != &rhs)
    {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    std::cout << "no copy " << std::endl;
    return *this;
}


void String::free()
{
    if(elements)
    {
        std::for_each(elements, end, [this](char& c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String& String::operator=(const String& rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}