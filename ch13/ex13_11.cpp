/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_8
 * "word counter" practice
 */ 

#ifndef CP5_EX13_11_H
#define CP5_EX13_11_H

#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp):
        ps(new std::string(*hp.ps)), i(hp.i) {}
    
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr(){};
private:
    std::string *ps;
    int i;
};

HasPtr&
HasPtr::operator=(const HasPtr &rhs)
{
    std::string* new_ps = new std::string(*rhs.ps);
    delete ps;
    ps = new_ps;
    i = rhs.i;
    return *this;
}

#endif