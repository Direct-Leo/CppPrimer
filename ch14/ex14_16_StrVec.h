/* Created by vleo on 21/12/8
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex14_16_StrVec
 * 
 */ 

#ifndef EX13_39_H
#define EX13_39_H

#include <memory>
#include <string>

class StrVec{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    //ex14_18
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);

public:
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec& operator=(const std::initializer_list<std::string>);
    std::string& operator[](size_t n){ return element[n]; }
    const std::string& operator[](size_t n)const { return element[n]; }

    ~StrVec();

    void push_back(const std::string&);
    size_t size() const { return first_free - element; }
    size_t capcity() const { return cap - element; }
    std::string* begin() const { return element; }
    std::string* end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string&);

private:
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,
                                                       const std::string*);
    
    void free();
    void chk_n_alloc()
    {
        if(size() == capcity())
            reallocate();
    }
    void reallocate();
    void alloc_n_move(size_t new_cap);

private:
    std::string* element;
    std::string* first_free;
    std::string* cap;
    std::allocator<std::string> alloc;
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);

bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);

#endif