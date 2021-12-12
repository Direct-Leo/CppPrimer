#include "ex14_16_StrBlob.h"
#include "ex14_16_StrBlob.cpp"
#include "ex14_32.h"
#include <iostream>

StrBlobPtr& StrBlobPtr_pointer::operator*()
{
    return *(this->pointer);
}

StrBlobPtr* StrBlobPtr_pointer::operator->()
{
    return &this->operator*();
}

int main()
{
    StrBlob sb{"Hello", "world"};
    StrBlobPtr iter = sb.begin();
    StrBlobPtr_pointer p(&iter);
    std::cout << p->deref() << std::endl;
}