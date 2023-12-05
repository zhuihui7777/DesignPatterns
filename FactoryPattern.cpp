//ͨ������ģʽ�����ǿ��Խ�����Ĵ����߼���װ�ڹ������У�ʹ�ÿͻ��˴���������Ʒ��ʵ�ֽ��
//��򵥹���ģʽ��ͬ���ǣ�����ģʽ��ͨ���̳й����Ĺ����ӿڣ�Ȼ��ͨ����ͬ�Ĺ���ȥ������ͬ�Ķ���
//����ͨ������������жϣ�����ͨ��������Ĳ�ͬ����ȥ������ǰ�����ĸ�����
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