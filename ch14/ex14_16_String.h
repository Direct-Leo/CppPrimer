/* Created by vleo on 21/12/8
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex14_16_String
 * 
 */ 

#ifndef MY_STRING_H
#define MY_STRING_H
#include <memory>

class String{
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    //ex14_18
    friend bool operator>(const String&, const String&);
    friend bool operator<(const String&, const String&);
    friend bool operator>=(const String&, const String&);
    friend bool operator<=(const String&, const String&);

public:
    String() : String("") {}
    String(const char*);
    String(const String&);
    String& operator=(const String&);

    //move constructor
    String(String&&);
    String& operator=(String&&);
    
    ~String();

    char* begin() const { return elements;}
    char* end() const { return last_elem; }

    char& operator[](size_t n) { return elements[n]; }
    const char& operator[](size_t n) const { return elements[n]; }

    const char* c_str() const { return elements; }
    size_t size() const { return last_elem - elements; }
    size_t length() const { return last_elem - elements; }

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char* elements;
    char* last_elem;
    std::allocator<char> alloc;
};

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
//ex14_18
bool operator>(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>=(const String&, const String&);
bool operator<=(const String&, const String&);
#endif
