/* Created by vleo on 21/11/16
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_5
 * "word counter" practice
 */ 

#ifndef CP5_EX13_05_H
#define CP5_EX13_05_H

#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp):
        ps(new std::string(*hp.ps)), i(hp.i) {}

private:
    std::string *ps;
    int i;
};

#endif