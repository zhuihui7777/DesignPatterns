//װ����ģʽ:װ����ģʽ���Զ�̬�ظ�һ���������һЩ�����ְ�𣬾����ӹ�����˵��װ����ģʽ�����������Ϊ��
//װ����ģʽ��һ�ֶ���ṹ��ģʽ��
//�ŵ㣺
//װ����ģʽ�����ṩ�ȼ̳и��������ԡ�
//װ����ģʽ���Զ�̬����չһ��ʵ����Ĺ��ܡ�
//װ����ģʽ���Զ�һ��������ж��װ�Σ��������ͬ��Ϊ����ϣ��õ����ܸ���ǿ��Ķ���
//���幹���������װ������Զ����仯���û����Ը�����Ҫ�����µľ��幹����;���װ���࣬��ʹ��ʱ�ٶ��������ϣ�ԭ�д�������ı䣬���ϡ�����ԭ�򡱡�
//ȱ�㣺
//ʹ��װ����ģʽ����ϵͳ���ʱ�������ܶ�С������Щ�����������������֮���໥���ӵķ�ʽ������ͬ�����������ǵ����������ֵ������ͬ������С����Ĳ����Ʊػ�ռ�ø����ϵͳ��Դ����һ��������Ӱ���������ܡ�
//װ����ģʽ�ṩ��һ�ֱȼ̳и����������Ľ����������ͬʱҲ��ζ�űȼ̳и������ڳ����Ŵ�Ҳ�����ѣ����ڶ��װ�εĶ��󣬵���ʱѰ�Ҵ��������Ҫ���Ų飬��Ϊ������
//װ����ģʽ������ȱ����ǣ�װ����������ʱ��������ܶ���ظ����󣬶��Ҳ����Ŵ�
//���䣺
//װ����ģʽ�ı����ǣ���̬��ϡ�
//װ����ģʽ�Ľṹ�����ģʽ�Ľṹ���ƣ������ߵ�Ŀ�Ĳ�һ����װ����ģʽ��Ŀ����Ҫ��̬�ظ�������ӹ��ܣ������ģʽ��Ŀ�����ڽ�������ϳ����νṹ��
//װ����ģʽ�ĺ������ڳ���װ�������ơ�
//װ����ģʽ�Ĺؼ����ڳ���װ����Decorator����ƣ�����ʹ���������ʾ��
//Beverage�����ϵĻ��࣬Ȼ���м������ϻ�̳и���
//CondimentDecorator��װ���ߵĻ��࣬������Լӵĵ��ϣ���Щ������Ϊװ���߿��Լ��뵽�����У�ʵ�ֶ����ϵ�װ��
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