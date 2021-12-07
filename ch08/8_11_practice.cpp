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
    vector<string> phone;
};





int main(int argc,char *argv[])
{
    string line,word;
    vector<PersonInfo> people;
    std::istringstream record(line);
    while (getline(cin,line))
    {
        record.str(line);
        PersonInfo info;
        record >> info.name; 
        while (record >> word)
        {
            info.phone.push_back(word);
        }
        people.push_back(info);
        record.clear();
    }
    

    return 0;
}