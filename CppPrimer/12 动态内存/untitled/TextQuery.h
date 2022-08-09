//
// Created by PaulYu on 2022/7/17.
//

#ifndef UNTITLED_TEXTQUERY_H
#define UNTITLED_TEXTQUERY_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include "QueryResult.h"
#include "StrBlob.h"

using namespace std;

class TextQuery {
public:
    TextQuery(ifstream &infile);
    QueryResult query(string str);
private:
    StrBlob file;
    map<string, shared_ptr<set<int>>> fileNo;
};


#endif //UNTITLED_TEXTQUERY_H
