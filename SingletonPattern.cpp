#include<iostream>
class Singleton {
private:
	Singleton() = default;
	Singleton(const Singleton& other) = delete; //禁止使用拷贝构造函数
	Singleton& operator=(const Singleton&) = delete; //禁止使用拷贝赋值运算符
public:
	static Singleton& getInstance() {
		static Singleton s;
		std::cout << "new singele" << std::endl;
		return s;
	}
};
#if 1
int main() {
	Singleton::getInstance();
	Singleton::getInstance();
	return 0;
}
#endif