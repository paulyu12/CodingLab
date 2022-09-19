#include <mutex>

using namespace std;
std::mutex mt;

/**
 * @brief 双检查锁实现方案（线程安全）
 * 
 */
class Singleton
{
private:
    Singleton(){}
public:
    static Singleton* getInstance()
    {
        if(_instance == 0)
        {
            mt.lock();
            if(_instance == 0)
                _instance = new Singleton();
            mt.unlock();
        }
        return _instance;
    }
private:
    static Singleton* _instance;
};

Singleton* Singleton::_instance = 0;



/**
 * @brief 局部静态变量实现方案（线程安全）
 * 
 */
class Singleton2
{
public:
	// 注意返回的是引用
	static Singleton2& getInstance()
	{
		static Singleton2 value;  //静态局部变量
		return value;
	}

private:
	Singleton2() = default;
	Singleton2(const Singleton2& other) = delete; //禁止使用拷贝构造函数
	Singleton2& operator=(const Singleton2&) = delete; //禁止使用拷贝赋值运算符
};