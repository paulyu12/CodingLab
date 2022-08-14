//
// Created by PaulYu on 2022/8/14.
//

#ifndef CPP_PRACTICE_STRVEC_H
#define CPP_PRACTICE_STRVEC_H

#include <string>
#include <memory>

class StrVec {
public:
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string> il);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const { return first_free - element; }
    size_t capacity() const { return cap - element; }
    std::string* begin() const { return element; }
    std::string* end() const { return first_free; }
    void resize(size_t newSize);
    void resize(size_t newSize, const std::string &value);

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc();
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string *b, const std::string *e);
    void free();
    void reallocate();
    std::string *element;
    std::string *first_free;
    std::string *cap;

};


#endif //CPP_PRACTICE_STRVEC_H
