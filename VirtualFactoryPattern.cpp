#include <iostream>
//抽象工厂模式解决了生产一系列产品的问题，工厂可以生产多个商品，比如A和B。而工厂模式只解决了某一个商品的生产，会导致工厂过多。
// 抽象产品A
class AbstractProductA {
public:
    virtual void operationA() = 0;
};

// 具体产品A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "ConcreteProductA1::operationA()" << std::endl;
    }
};

// 具体产品A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "ConcreteProductA2::operationA()" << std::endl;
    }
};

// 抽象产品B
class AbstractProductB {
public:
    virtual void operationB() = 0;
};

// 具体产品B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "ConcreteProductB1::operationB()" << std::endl;
    }
};

// 具体产品B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "ConcreteProductB2::operationB()" << std::endl;
    }
};

// 抽象工厂
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// 具体工厂1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// 具体工厂2
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
    // 使用具体工厂1创建产品
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    productA1->operationA();
    productB1->operationB();

    // 使用具体工厂2创建产品
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
