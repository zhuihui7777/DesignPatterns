//通过简单工厂模式，我们可以将对象的创建逻辑封装在工厂类中，使得客户端代码与具体产品的实现解耦。
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
	static Product* createProduct(int type) {
		if (type == 1) {
			return new ConcreteProductA();
		}
		else if (type == 2) {
			return new ConcreteProductB();
		}
		return nullptr;
	}
};

#if 0
int main() {
	Product* m= Factory::createProduct(1);
	Product* n= Factory::createProduct(2);
	m->operation();
	n->operation();
	return 0;
}
#endif