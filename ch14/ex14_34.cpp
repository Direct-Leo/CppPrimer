/*******************************************************
 * @file ex14_34.cpp
 * @author vleo
 * @date 2021.12.12
 * @remark a "if then else" operation
 *******************************************************/

struct Test
{
    int operator()(bool b, int ia, int ib)
    {
        return b ? ia : ib;
    }
};
