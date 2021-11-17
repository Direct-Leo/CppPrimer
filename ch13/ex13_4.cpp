/* Created by vleo on 21/11/16
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex13_4
 * "word counter" practice
 */ 

#include <iostream>
#include <memory>
using std::cin ; using std::cout; using std::endl;

class Point{
public:
    Point() = default;
    Point(const Point&);

private:
    int x,y;
};

Point::Point(const Point& p) : x(p.x), y(p.y) { cout << "copy constructor called once\n"; } 


Point global;
Point foo_bar(Point arg) //1
{
    Point local = arg, *heap = new Point(global); // 2, 3
    *heap = local;
    Point pa[4] = { local, *heap }; // 4, 5
    return *heap; // 6
}

int main()
{
    foo_bar(global);
    return 0;
}
