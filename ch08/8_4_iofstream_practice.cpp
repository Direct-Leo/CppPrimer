#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>

using std::initializer_list;
using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;

vector<string> v;

vector<string> &func(const int &argc,char **argv)
{
    for(auto p = argv + 1;p != argv + argc; ++p)
    {
        std::ifstream input(*p);
        if(input)
        {
            string line;
            while (getline(input,line))
            {
                v.push_back(line);
            }
        }
        else
        {
            std::cerr << "couldn't open: " + string(*p);
        }
        
    }
    return v;
}

void print(std::ofstream & ofs,vector<string> &vec)
{
    for(auto i : vec)
    {
        ofs << i << endl;
    }
}

int main(int argc,char *argv[])
{
    func(argc,argv);
    std::ofstream myofs;
    myofs.open("to_be_written.txt");
    print(myofs,v);

    return 0;
}