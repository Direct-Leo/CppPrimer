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

std::vector<int>* dynamic_vector_generator();
std::vector<int>* dynamic_vector_processor(std::vector<int>* ptr_v);
void dynamic_vector_printer(std::vector<int>* ptr_v);


int main()
{

    dynamic_vector_printer(
        dynamic_vector_processor(dynamic_vector_generator())
    );
    
    return 0;
}


std::vector<int>* dynamic_vector_generator()
{
    auto v_ptr = new vector<int>();
    return v_ptr;
}

std::vector<int>* dynamic_vector_processor(std::vector<int>* ptr_v)
{
    int temp = 0;
    while (cin >> temp)
    {
        ptr_v->push_back(temp);
    }
    return ptr_v;
}

void dynamic_vector_printer(std::vector<int>* ptr_v)
{
    if(ptr_v)
    {
        for(const auto& i : *ptr_v)
        {
            cout << i << " " ;
        }
        delete ptr_v ;
    }
}


