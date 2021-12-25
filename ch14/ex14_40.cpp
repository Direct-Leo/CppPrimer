/*******************************************************
 * @file ex14_40.cpp
 * @author vleo
 * @date 2021.12.15
 * @remark a string check Class
 *******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using std::vector;
using std::cin; using std::cout; using std::endl;
using std::string;
using std::sort;
using std::stable_sort;
using std::for_each;

vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

class ShorterString{
public:
    bool operator()(const string& a, const string& b) const
    {
        return a.length() < b.length();
    }
};

class BiggerEqual{
public:
    BiggerEqual(size_t i = 0) : sz(i){}

    bool operator()(const string& s) const
    {
        return s.size() >= sz;
    }

private:
    size_t sz;
};

class StringPrint{
public:
    void operator()(const string& s)const
    {
        cout << s << " ";
    }

};

void elimDups(vector<string> &v)
{
    std::sort(v.begin(), v.end());
    auto unique_end = std::unique(v.begin(), v.end());
    v.erase(unique_end, v.end());
}

void biggies(vector<string> &v, vector<string>::size_type sz)
{
    elimDups(v);
    stable_sort(v.begin(), v.end(), ShorterString());
    auto it = std::find_if(v.begin(), v.end(), BiggerEqual(sz));
    
    auto count = v.end() - it;
    cout << "count: " << count <<endl;
    std::for_each(it, v.end(), StringPrint());
}

int main()
{
    biggies(vec, 4);
    return 0;
}