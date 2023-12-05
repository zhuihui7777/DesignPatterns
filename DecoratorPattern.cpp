//装饰者模式:装饰者模式可以动态地给一个对象添加一些额外的职责，就增加功能来说，装饰者模式比生成子类更为灵活。
//装饰者模式是一种对象结构型模式。
//优点：
//装饰者模式可以提供比继承更多的灵活性。
//装饰者模式可以动态地扩展一个实现类的功能。
//装饰者模式可以对一个对象进行多次装饰，创造出不同行为的组合，得到功能更加强大的对象。
//具体构件类与具体装饰类可以独立变化，用户可以根据需要增加新的具体构件类和具体装饰类，在使用时再对其进行组合，原有代码无须改变，符合“开闭原则”。
//缺点：
//使用装饰者模式进行系统设计时将产生很多小对象，这些对象的区别在于它们之间相互连接的方式有所不同，而不是它们的类或者属性值有所不同，大量小对象的产生势必会占用更多的系统资源，在一定程序上影响程序的性能。
//装饰者模式提供了一种比继承更加灵活机动的解决方案，但同时也意味着比继承更加易于出错，排错也很困难，对于多次装饰的对象，调试时寻找错误可能需要逐级排查，较为烦琐。
//装饰者模式的最大的缺点就是：装饰链条过长时，会产生很多的重复对象，而且不易排错！
//补充：
//装饰者模式的本质是：动态组合。
//装饰者模式的结构与组合模式的结构类似，但两者的目的不一样，装饰者模式的目的是要动态地给对象添加功能，而组合模式的目的在于将对象组合成树形结构。
//装饰者模式的核心在于抽象装饰类的设计。
//装饰者模式的关键在于抽象装饰类Decorator的设计，其典型代码如下所示：
//Beverage是饮料的基类，然后有几种饮料会继承该类
//CondimentDecorator是装饰者的基类，代表可以加的调料，这些调料作为装饰者可以加入到饮料中，实现对饮料的装饰
#include <iostream>
#include <string>
class Beverage {
protected:
	std::string description = "unknown Beverage";
public:
	virtual std::string getDescription() = 0;
	virtual double cost() = 0;
	virtual ~Beverage() {}
};
class CondimentDecorator :public Beverage {
public:
	virtual std::string getDescription() = 0;
	virtual ~CondimentDecorator() {}
};
class DarkRoast :public Beverage {
public:
	DarkRoast() {
		description = "DarkRoast";
	}
	std::string getDescription() {
		return description;
	}
	double cost() {
		return 1.0;
	}
};
class Milk :public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Milk(Beverage* beverage) {
		this->beverage = beverage;
	}
	std::string getDescription() {
		return beverage->getDescription() + ", Milk";
	}
	double cost() {
		return beverage->cost() + 0.1;
	}
};
class Mocha :public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Mocha(Beverage* beverage) {
		this->beverage = beverage;
	}
	std::string getDescription() {
		return beverage->getDescription() + ", Mocha";
	}
	double cost() {
		return beverage->cost() + 0.2;
	}
};
#if 0
int main() {
	Beverage* beverage = new DarkRoast();
	beverage = new Milk(beverage);
	beverage = new Mocha(beverage);
	beverage = new Milk(beverage);
	std::cout << beverage->getDescription() << std::endl;
	std::cout << beverage->cost() << std::endl;
	delete beverage;
	return 0;
}
#endif