//
// Created by PaulYu on 2022/7/17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "TextQuery.h"

TextQuery::TextQuery(ifstream &infile) : file() {
    string str;
    while (getline(infile, str)) {
        file.push_back(str);

        istringstream is(str);
        string word;
        int n = file.size() - 1;
        while (is >> word) {
            auto &lineSetPtr = fileNo[word];
            if (!lineSetPtr) {
                lineSetPtr.reset(new set<int>());
            }

            lineSetPtr->insert(n);
        }
    }
}

QueryResult TextQuery::query(string str) {
    static shared_ptr<set<int>> nodata(new set<int>());
    if (this->fileNo.find(str) == this->fileNo.end()) {
        return QueryResult(this->file, nodata, str);
    }
    else {
        return QueryResult(this->file, this->fileNo.at(str), str);
    }
}
