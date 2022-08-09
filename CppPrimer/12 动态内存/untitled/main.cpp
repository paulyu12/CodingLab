#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <sstream>
#include "TextQuery.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"

using namespace std;

string make_plural(size_t sz, const string &word, const string &extra) {
    return sz > 1 ? word + extra : word;
}

ostream &print(ostream &os, const QueryResult &qr) {
    cout << qr.sought << " occurs " << qr.fileNo->size() << make_plural(qr.fileNo->size(), " time", "s") << endl;

    auto fileNoSet = *(qr.fileNo);
    for (const auto line : fileNoSet) {
        cout << "\t(line " << line << ") " << qr.file.at(line) << endl;
    }

    return os;
}

void runQuery(ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        cout << "enter a word to seek, enter q to quit" << endl;

        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }

        print(cout, tq.query(s));
    }
}

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &rhs) {
        this->ps = new string(rhs.ps);
        this->i = rhs.i;
    }
private:
    string *ps;
    int i;
};

int main() {
    ifstream infile("a.txt");
    runQuery(infile);

    return 0;
}
