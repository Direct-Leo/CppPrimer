/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_27
 * my own HasPtr
 */ 
#include <string>
#include <iostream>

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);

    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp):
        ps(new std::string(*hp.ps)), i(hp.i) {}
    
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr(){ delete ps; };
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

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

int main()
{
    HasPtr hp1("xiaofan"), hp2("xiaoli");
    swap(hp1,hp2);
    return 0;
}