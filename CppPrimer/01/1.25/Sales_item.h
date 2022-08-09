//
// Created by PaulYu on 2022/4/20.
//

#ifndef UNTITLED_SALES_ITEM_H
#define UNTITLED_SALES_ITEM_H

#include <string>
#include <iostream>

class Sales_item {
    friend std::ostream &operator<<(std::ostream &os, Sales_item &salesItem);
    friend std::istream &operator>>(std::istream &is, Sales_item &salesItem);
public:
    Sales_item() = default;
    Sales_item(std::string isbn) : m_isbn(isbn), m_num(0) {

    }
    std::string isbn() {
        return m_isbn;
    }

    Sales_item operator+(Sales_item &val);


private:
    std::string m_isbn;
    unsigned int m_num;
};

#endif //UNTITLED_SALES_ITEM_H
