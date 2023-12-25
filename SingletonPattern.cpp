#include<iostream>
#undef main
class Singleton {
private:
	Singleton() = default;
	Singleton(const Singleton& other) = delete; //��ֹʹ�ÿ������캯��
	Singleton& operator=(const Singleton&) = delete; //��ֹʹ�ÿ�����ֵ�����
public:
	static Singleton& getInstance() {
		static Singleton s;
		std::cout << "new singele" << std::endl;
		return s;
	}

};
#if 1
int main() {
	Singelton* s1 = Singleton::getInstance();
	Singelton* s2 = Singleton::getInstance();
	std::cout << s1 << "--------" << s2 << std::endl;
	return 0;
}
#endif