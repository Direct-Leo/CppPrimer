/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_39
 * my own HasPtr
 */ 

#ifndef MY_STRING_H
#define MY_STRING_H
#include <memory>

class String{
public:
    String() : String("") {}
    String(const char*);
    String(const String&);
    String& operator=(const String&);

    //move constructor
    String(String&&);
    String& operator=(String&&);
    
    ~String();

    const char* c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements; }

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char* elements;
    char* end;
    std::allocator<char> alloc;
};

#endif
