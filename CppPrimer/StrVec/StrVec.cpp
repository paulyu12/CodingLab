//
// Created by PaulYu on 2022/8/14.
//

#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il) : element(nullptr), first_free(nullptr), cap(nullptr) {
    for (auto s : il) {
        push_back(s);
    }
}

StrVec::StrVec(const StrVec &rhs)  {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    element = data.first;
    first_free = cap = data.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    element = data.first;
    first_free = cap = data.second;

    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::resize(size_t newSize) {
    resize(newSize, "");
}

void StrVec::resize(size_t newSize, const std::string &value) {
    if (newSize <= size()) {
        for (auto p = first_free; p != element + newSize;) {
            alloc.destroy(--p);
        }
        first_free = element + newSize;
    }
    else if (newSize <= capacity()) {
        for (auto p = first_free; p != element + newSize;) {
            alloc.construct(p ++, value);
        }
        first_free = element + newSize;
    }
    else {
        auto newData = alloc.allocate(newSize);
        auto p = std::uninitialized_copy(element, first_free, newData);
        while (p != newData + newSize) {
            alloc.construct(p ++, value);
        }

        free();
        element = newData;
        first_free = cap = newData + newSize;
    }
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free ++, s);
}

void StrVec::chk_n_alloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    std::string *pString = alloc.allocate(e - b);
    return std::make_pair(pString, std::uninitialized_copy(b, e, pString));
}

void StrVec::free() {
    if (element) {
        for (auto p = first_free; p != element;) {
            alloc.destroy(-- p);
        }
        alloc.deallocate(element, cap - element);
    }
}

void StrVec::reallocate() {
    size_t newSize = size() ? 2 * size() : 1;
    std::string *pString = alloc.allocate(newSize);

    std::string *dest = pString, *elem = element;

    while (elem != first_free) {
        alloc.construct(dest ++, std::move(*elem ++));
    }

    free();
    element = pString;
    first_free = dest;
    cap = pString + newSize;
}
