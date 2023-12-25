#include<iostream>
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
	Singleton::getInstance();
	Singleton::getInstance();
	return 0;
}
#endif