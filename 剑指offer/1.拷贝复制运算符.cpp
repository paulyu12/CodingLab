class Demo {
public:
    Demo() : pData(nullptr) {}
    Demo(int *ptr) : pData(ptr) {}
    Demo(int data) : pData(new int(data)) {}

    // 拷贝构造函数
    Demo(const Demo &rhs) {
        pData = new int(*rhs.pData);
    }

    // 拷贝赋值运算符
    Demo &operator=(const Demo &rhs) {
        if (this != &rhs) {
            Demo temp(rhs);

            int *d = temp.pData;
            temp.pData = this->pData;
            this->pData = d;
        }

        return *this;
    }

    // 析构函数
    ~Demo() {
        if (pData) {
            delete pData;
            pData = nullptr;
        }
    }

    int getVal() {
        return *pData;
    }

private:
    int *pData;
};