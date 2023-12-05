//通过工厂模式，我们可以将对象的创建逻辑封装在工厂类中，使得客户端代码与具体产品的实现解耦。
//与简单工厂模式不同的是，工厂模式是通过继承公共的工厂接口，然后通过不同的工厂去创建不同的对象。
//即不通过工厂类进行判断，而是通过工厂类的不同子类去决定当前生成哪个对象。
#include<iostream>
class Product {
public:
	virtual void operation() = 0;
};
class ConcreteProductA : public Product {
public:
	void operation() override {
		std::cout << "creat productA" << std::endl;
	}
};
class ConcreteProductB : public Product {
public:
	void operation() override {
		std::cout << "creat productB" << std::endl;
	}
};
class Factory {
public:
	virtual Product* create() = 0;
};
class FactoryA:public Factory {
public:
	Product* create() {
		return new ConcreteProductA();
	}
};
class FactoryB:public Factory {
public:
Product* create() {
		return new ConcreteProductB();
}
};

#if 0
int main() {
	Factory* p = new FactoryB();
	Factory* t = new FactoryA();
	Product* m = p->create();
	Product* n = t->create();
	m->operation();
	n->operation();
	return 0;
}
#endif