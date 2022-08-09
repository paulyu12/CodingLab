#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<string> words;
    string w;

    while (cin >> w && w != "-1") {
        if (find(words.begin(), words.end(), w) == words.end()) {
            words.push_back(w);
        }

    }

    for (const auto &ele : words) {
        cout << ele << endl;
    }

    return 0;
}