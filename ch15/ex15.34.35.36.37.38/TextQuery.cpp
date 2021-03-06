#include "textquery.h"
#include "make_plural.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
    string text;
    while(getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word){
            word = cleanup_str(word);
            auto& lines = wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

string TextQuery::cleanup_str(const string& word)
{
    string ret;
    for(auto it = word.begin(); it != word.end(); ++it){
        if(!ispunct(*it))
            ret += tolower(*it);
    }
    return ret; 
}

QueryResult
TextQuery::query(const string& sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(cleanup_str(sought));

    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

ostream& print(ostream& os, const QueryResult& qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
    << make_plural(qr.lines->size(), "time", "s") << endl;

    for(auto num : *qr.lines)
    {
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}
/*
void TextQuery::display_map()
{
    auto iter = TextQuery::wm.cbegin(), iter_end = wm.cend();

    for( ; iter != iter_end; ++iter)
    {
        cout << "word: " << iter->first << " {";

        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(),
                        loc_iter_end = text_locs->cend();
        while(loc_iter != loc_iter_end)
        {
            cout << *loc_iter;
            if(++loc_iter != loc_iter_end)
                cout << ", ";
        }

        cout << "}\n";
    }
    cout << endl;
}
*/