//
// Created by PaulYu on 2022/8/8.
//

#include "HasPtr.h"

// 自定义 swap 函数
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    cout << "正在执行自定义 swap 函数" << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
}

// 自定义 < 运算符
bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *this->ps < *rhs.ps;
}

// 拷贝赋值运算符
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++ *rhs.use;   // 递增右侧对象的引用计数

    if (-- *use == 0) {  // 递减本对象的引用计数
        delete ps;
        delete use;
    }

    ps = rhs.ps;     // 拷贝成员
    use = rhs.use;
    i = rhs.i;

    return *this;
}

// 析构函数
HasPtr::~HasPtr()
{
    if (-- *use == 0) {
        delete ps;
        delete use;
    }
}

void HasPtr::printStr() const
{
    cout << *this->ps << endl;
}
