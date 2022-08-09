/*************************************************************************
    > File Name: 3_28.cpp
    > Author:
    > Mail:
    > Created Time: Wed 12 Apr 2017 07:38:46 PM CST
 ************************************************************************/
#include "Sales_item.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    Sales_item total;
    if (cin >> total) {
        Sales_item trans;
        while (cin >> trans) {
            if (total.isbn() == trans.isbn())
                total = total + trans;
            else {
                cout << total << endl;
                total = trans;
            }
        }

        cout << total << endl;
    }

    return 0;
}
