//
// Created by PaulYu on 2022/7/17.
//

#ifndef UNTITLED_QUERYRESULT_H
#define UNTITLED_QUERYRESULT_H

#include <string>
#include <vector>
#include <set>
#include "StrBlob.h"

using namespace std;

class QueryResult {
public:
    friend ostream &print(ostream &os, const QueryResult &qr);
    QueryResult(StrBlob file,
                shared_ptr<set<int>> fileNo,
                string &sought) : sought(sought), file(file), fileNo(fileNo) {}
private:
    string sought;
    StrBlob file;
    shared_ptr<set<int>> fileNo;
};


#endif //UNTITLED_QUERYRESULT_H
