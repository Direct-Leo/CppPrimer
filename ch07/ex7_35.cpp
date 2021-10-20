/* practice 7.35
 * 2021.10.12 by vleo
 */

#include <iostream>
#include <string>
#include "Sales_data.h"
#include "Sales_data.cpp"


typedef std::string Type;
Type initVal();
class Exercise{
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal() ;

private:
    int val;
};
Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}