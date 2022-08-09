/*************************************************************************
    > File Name: 3_28.cpp
    > Author:
    > Mail:
    > Created Time: Wed 12 Apr 2017 07:38:46 PM CST
 ************************************************************************/
#include "Sales_item.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool compareIsbn(const Sales_item &a, const Sales_item &b) {
    if (a.isbn() < b.isbn())
        return true;
    else
        return false;
}

int main()
{
    vector<Sales_item> salesItemVector;

    Sales_item trans;
    while (cin >> trans) {
        if (trans.isbn() == "-1") {
            break;
        }
        salesItemVector.push_back(trans);
    }

    sort(salesItemVector.begin(), salesItemVector.end(), compareIsbn);

    for (auto &ele : salesItemVector) {
        cout << ele;
    }

    vector<Sales_item>::iterator b_it = salesItemVector.begin();

    while (b_it != salesItemVector.end()) {
        vector<Sales_item>::iterator it = find_if(b_it, salesItemVector.end(), [b_it](const Sales_item &obj) {
           return b_it->isbn() != obj.isbn();
        });

        Sales_item s;
        auto result = accumulate(b_it, it, s);
        cout << b_it->isbn() << result << endl;

        b_it = it;
    }

    return 0;
}
