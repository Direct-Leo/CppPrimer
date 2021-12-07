/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_50
 * 
 */ 

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::sort;

class Foo{
public:
    Foo sorted() &&;
    Foo sorted() const&;

private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    std::cout << "&&" << std::endl;
    return *this;
}

Foo Foo::sorted() const&
{
    std::cout << "const &" << std::endl;
    return Foo(*this).sorted();
}

int main()
{
    Foo().sorted();
    Foo f;
    f.sorted();
    return 0;
}