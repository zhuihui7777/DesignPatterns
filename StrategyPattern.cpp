//策略模式：定义了算法族，分别封装起来，让他们之间可以互相替换，此模式让算法的变化独立于使用算法的客户	
//优点：将算法的使用和算法的实现分离开来，实现算法的变化独立于算法的使用者	
//缺点：策略模式将造成产生很多策略类,客户必须知道所有的策略类，并自行决定使用哪一个策略类
		
#include <iostream>
using namespace std;
class Quark {
public:
	virtual void quark() = 0;
};
class QuarkCat : public Quark {
public:
	void quark() {
		cout << "I am a cat" << endl;
	}
};
class QuarkDog : public Quark {
public:
	void quark() {
		cout << "I am a dog" << endl;
	}
};
class Cat {

public:
	Quark* quarkBehavior;
	void set(Quark* q1) {
		quarkBehavior = q1;
	}
	void quark() {
		quarkBehavior->quark();
	}
};
class WuYue :public Cat {
public:
	WuYue() {
		quarkBehavior = new QuarkCat();
	}
};
#if 0
int main() {
	Cat* cat = new WuYue();
	cat->quark();
	cat->set(new QuarkDog());
	cat->quark();
	return 0;
}
#endif