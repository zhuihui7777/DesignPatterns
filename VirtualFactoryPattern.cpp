#include <iostream>
//���󹤳�ģʽ���������һϵ�в�Ʒ�����⣬�����������������Ʒ������A��B��������ģʽֻ�����ĳһ����Ʒ���������ᵼ�¹������ࡣ
// �����ƷA
class AbstractProductA {
public:
    virtual void operationA() = 0;
};

// �����ƷA1
class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "ConcreteProductA1::operationA()" << std::endl;
    }
};

// �����ƷA2
class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "ConcreteProductA2::operationA()" << std::endl;
    }
};

// �����ƷB
class AbstractProductB {
public:
    virtual void operationB() = 0;
};

// �����ƷB1
class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "ConcreteProductB1::operationB()" << std::endl;
    }
};

// �����ƷB2
class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "ConcreteProductB2::operationB()" << std::endl;
    }
};

// ���󹤳�
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// ���幤��1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// ���幤��2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};
#if 1
int main() {
    // ʹ�þ��幤��1������Ʒ
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    productA1->operationA();
    productB1->operationB();

    // ʹ�þ��幤��2������Ʒ
    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();
    productA2->operationA();
    productB2->operationB();

    delete productA1;
    delete productB1;
    delete productA2;
    delete productB2;
    delete factory1;
    delete factory2;

    return 0;
}
#endif
