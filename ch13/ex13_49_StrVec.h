/* Created by vleo on 21/11/29
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_34_36_37
 * 
 */ 

#ifndef EX13_49_StrVec_H
#define EX13_49_StrVec_H

#include <memory>
#include <string>

class StrVec{
public:
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);

    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;

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


#endif