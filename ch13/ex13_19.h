/* Created by vleo on 21/11/17
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_19
 * Does your Employee class need to define its own versions of the copy-control
 * members?
 * If so, why? If not, why not?
 * Implement whatever copy-control members you think Employee needs.
 * 
 * Answer: No, there is not reasonable, 
 * employee can't be copied in our real world
 */ 

#ifndef EX_13_19_H
#define EX_13_19_H
#include <string>
using std::string;


class Employee{
public:
    Employee();
    Employee(const string&);
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;

    const unsigned int id() const{ return id_; } ;


private:
    string name_;
    unsigned int id_;
    static unsigned int basis;
};

#endif





