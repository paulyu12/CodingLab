// 一个带有拷贝构造的行为像指针的类型定义

//
// Created by PaulYu on 2022/8/8.
//

#ifndef CPP_PRACTICE_HASPTR_H
#define CPP_PRACTICE_HASPTR_H

#include <iostream>
#include <algorithm>

using namespace std;

// 这种类型最好使用 shared_ptr 管理指针，可以根据引用计数来管理和释放内存
// 但是如果想要自行管理内存，那么必须增加一个引用计数变量
class HasPtr {
public:
    // 构造函数
    HasPtr(const string &s = string()) :
            ps(new string(s)),
            i(0),
            use(new size_t(1)) {}

    // 拷贝构造函数
    HasPtr(const HasPtr &rhs) :
            ps(rhs.ps),
            i(rhs.i),
            use(rhs.use) { *use ++; }
    // 拷贝赋值运算符
    HasPtr& operator=(const HasPtr &rhs);
    // 重载 < 运算符
    bool operator<(const HasPtr &rhs) const;
    // 析构函数
    ~HasPtr();

    void printStr() const;

    // 自定义 swap 函数
    friend void swap(HasPtr &lhs, HasPtr &rhs);

private:
    string *ps;
    int i;
    size_t *use;
};

#endif //CPP_PRACTICE_HASPTR_H
