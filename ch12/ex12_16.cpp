/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex12_16
 * "word counter" practice
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::cout; using std::cin; using std::endl;

int main()
{
    unique_ptr<string> p1(new string("xiaofan")) ;
    unique_ptr<string> p2(p1); //无法引用函数。。。它们是已经删除的函数
    unique_ptr<string> p3 = p1;
    return 0;
}


