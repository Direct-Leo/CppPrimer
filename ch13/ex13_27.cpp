/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_27
 * my own HasPtr
 */ 

#include <string>

class HasPtr{
public:

HasPtr(const std::string& s = std::string()) :
        i(0), ps(new std::string(s)), use(new std::size_t(1)) {}

HasPtr(HasPtr& hp) :
        i(hp.i), ps(hp.ps), use(hp.use) { ++*use; }
HasPtr& operator=(const HasPtr& rhs)
{
    ++*rhs.use;
    if(--*use == 0)
    {
        delete ps;
        delete use;
    }
    i = rhs.i;
    ps = rhs.ps;
    use = rhs.use;
    return *this;
}

~HasPtr()
{
    if(--*use == 0)
    {
        delete ps;
        delete use;
    }
}

private:
    int i;
    std::string* ps;
    std::size_t* use;
};



int main()
{
    
    return 0;
}



