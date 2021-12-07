#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::initializer_list;
using std::cin; using std::cout; using std::endl;
using std::string ;
using std::vector ;

struct PersonInfo
{
    string name;
    vector<string> phones;
};
vector<PersonInfo> People;


vector<PersonInfo> &read(int argc ,char **argv)
{

    for(auto p = argv + 1;p != argv + argc; ++p)
    {
        std::ifstream input(*p);
        if(input)
        {
            string line,word;
            PersonInfo info;
            while (getline(input,line))
            {
                std::istringstream record(line);
                record >> info.name;
                while (record >> word)
                {
                    info.phones.push_back(word);
                }
                People.push_back(info);
            }
            
        }
    }
    return People;
}


void write(std::ofstream &ofs,vector<PersonInfo> &vec)
{
    std::ostringstream os_name,os_phone;
    for(const auto info : vec)
    {
        os_name << info.name << " ";
        for(auto phone_num : info.phones)
        {
            os_phone << phone_num << endl ;
        }
    }
    ofs << os_name.str() << "\n";
    ofs << os_phone.str() ;

}


int main(int argc,char *argv[])
{
    std::ofstream myofs;
    read(argc,argv);
    myofs.open("final_out_new");
    write(myofs,People);

    return 0;
}