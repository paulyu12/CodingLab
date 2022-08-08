// 一个带有拷贝构造的行为像指针的类型定义

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
    HasPtr& HasPtr(HasPtr &rhs) : 
        ps(rhs.ps),
        i(rhs.i),
        use(rhs.use) { *use ++; }
    // 拷贝赋值运算符
    HasPtr& operator=(const HasPtr &rhs);
    // 重载 < 运算符
    bool operator<(const HasPtr &lhs, const HasPtr &rhs);
    // 析构函数
    ～HasPtr();

    // 自定义 swap 函数
    friend swap(const HasPtr &lhs, const HasPtr &rhs);

private:
    string *ps;
    int i;
    size_t *use;
}

// 自定义 swap 函数
void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "正在执行自定义 swap 函数" << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
}

// 自定义 < 运算符
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return lhs.i < rhs.i;
}

// 拷贝赋值运算符
HasPtr& HasPrt::operator=(const HasPtr &rhs)
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
