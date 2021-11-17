/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_13
 * "word counter" practice
 */ 

#include <iostream>
#include <vector>
#include <initializer_list>

class X{
public:
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&)
    {
        std::cout << "X& operator=(const X&)" << std::endl ;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }

};

void func(const X& rx, X x)
{
    std::vector<X> vec;
    vec.reserve(3);
    vec.push_back(rx);
    vec.push_back(x);

    X n_x = x;
    vec.push_back(n_x);
}

int main()
{
    X* px = new X;
    func(*px, *px);
    delete px;

    return 0;
}

