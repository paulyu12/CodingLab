//
// Created by PaulYu on 2022/4/20.
//

#include "Sales_item.h"

Sales_item Sales_item::operator+(Sales_item &val) {
    this->m_num += val.m_num;

    return *this;
}

std::ostream &operator<<(std::ostream &os, Sales_item &salesItem) {
    os << salesItem.m_isbn << std::string(": ") << std::to_string(salesItem.m_num) << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Sales_item &salesItem) {
    is >> salesItem.m_isbn >> salesItem.m_num;
    return is;
}