/* Created by vleo on 21/10/25
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex11_33
 * "word counter" practice
 */ 

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdexcept>


using std::vector;
using std::string;
using std::cout;using std::cin; using std::endl;
using std::pair;
using std::map;
using std::multimap;
using std::ifstream;
using std::istringstream;


map<string, string>buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key ;
    string value ;
    while (map_file >> key && getline(map_file, value))
    {
        if(value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    }
    return trans_map ; 
}
const string &
transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if(map_it != m.cend())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (std::getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word,trans_map);
        }
        cout << endl ;
    }
}

int main()
{
    ifstream word_map("word_map.txt");
    ifstream word("word.txt");
    word_transform(word_map, word);

    return 0;
}