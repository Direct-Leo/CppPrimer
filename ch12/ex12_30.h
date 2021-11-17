#ifndef EX_12_30_H
#define EX_12_30_H

#include <string>
using std::string;

#include <vector>
using std::vector;

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
    using line_no = vector<string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;

};

class QueryResult{
public:
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::line_no>> p,
                shared_ptr<vector<string>> f) :
                sought(s), lines(p), file(f){}

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};


#endif