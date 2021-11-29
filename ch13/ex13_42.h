#ifndef EX_12_30_H
#define EX_12_30_H

#include <string>
using std::string;

#include "ex13_40.h"

#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using std::map;

#include <set>
using std::set;

class QueryResult;
class TextQuery{
public:
    using line_no = std::size_t;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrVec> file;
    map<string, shared_ptr<set<line_no>>> wm;

};

class QueryResult{
public:
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::line_no>> p,
                shared_ptr<StrVec> f) :
                sought(s), lines(p), file(f){}

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<StrVec> file;
};


#endif