/* practice 7.27 
 * 2021.10.12 by vleo
 */

#include <iostream>
#include <string>
#include "Sales_data.h"
#include "Sales_data.cpp"
#include "Screen.h"
#include "Screen.cpp"

int main()
{
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n" ;
    myScreen.display(std::cout);
    std::cout << "\n"; 

}