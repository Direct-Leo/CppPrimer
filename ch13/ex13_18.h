/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_18
 * "word counter" practice
 */ 

#ifndef EX_13_18_H
#define EX_13_18_H
#include <string>
#include <iostream>
using std::cin; using std::cout; using std::endl;

class Employee{
public:
    Employee(): name(""), id(unique_num()) {}
    Employee(const std::string& ep_name) : name(ep_name), id(unique_num()) {}

    unsigned int unique_num();


    std::string name;
    unsigned int id;

    static unsigned int basis;
};

unsigned int Employee::basis = 0;

unsigned int
Employee::unique_num()
{
    return basis++;
}

#endif





