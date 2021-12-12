/*******************************************************
 * @file StrBlobPtr_pointer.h
 * @author vleo
 * @date 2021.12.12
 * @remark a class that holds a pointer to a StrBlobPtr
 *******************************************************/

#ifndef STRBLOBPTR_POINTER_H
#define STRBLOBPTR_POINTER_H

class StrBlobPtr;

class StrBlobPtr_pointer{

public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr* p) : pointer(p) {}

    StrBlobPtr& operator*();
    StrBlobPtr* operator->();

private:
    StrBlobPtr* pointer = nullptr;

};



#endif