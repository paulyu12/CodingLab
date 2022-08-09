#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

int main()
{
    string familyName, childName;
    map<string, vector<string>> m_map;

    while (cin >> familyName >> childName && familyName != "-1") {
        cout << familyName << childName << endl;

        if (m_map.find(familyName) != m_map.end()) {
            m_map[familyName].push_back(childName);
        }
        else {
            m_map[familyName] = vector<string>{childName};
        }
    }

    for (const auto &ele : m_map) {
        cout << ele.first << ": ";
        for (const auto &cn : ele.second) {
            cout << cn << ", ";
        }

        cout << endl;
    }

    return 0;
}