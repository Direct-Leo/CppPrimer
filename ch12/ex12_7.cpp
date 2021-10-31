/* Created by vleo on 21/10/24
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_38
 * "word counter" practice
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;
using std::cin; using std::cout; using std::endl;
using std::shared_ptr;

shared_ptr<vector<int>>dynamic_vector_generator();
shared_ptr<vector<int>> dynamic_vector_processor(shared_ptr<vector<int>> sp);
void dynamic_vector_printer(shared_ptr<vector<int>> sp);


int main()
{

    dynamic_vector_printer(
        dynamic_vector_processor(dynamic_vector_generator())
    );
    
    return 0;
}


shared_ptr<vector<int>> dynamic_vector_generator()
{
    auto sp = std::make_shared<vector<int>>();
    return sp;
}

shared_ptr<vector<int>> dynamic_vector_processor(shared_ptr<vector<int>> sp)
{
    int temp = 0;
    while (cin >> temp)
    {
        sp->push_back(temp);
    }
    return sp;
}

void dynamic_vector_printer(shared_ptr<vector<int>> sp)
{
    if(sp)
    {
        for(const auto& i : *sp)
        {
            cout << i << " " ;
        }
    }
}


