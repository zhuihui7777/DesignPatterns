//观察者模式的含义：定义了对象之间的一对多依赖，让多个观察者对象同时监听某一个主题对象，
//当主题对象发生变化时，它的所有依赖者（观察者）都会收到通知并更新。
//观察者模式的优点：
//1.观察者和被观察者之间是抽象耦合的。
//2.建立一套触发机制。
//观察者模式的缺点：
//1.如果一个被观察者对象有很多直接和间接的观察者的话，将所有的观察者都通知到会花费很多时间。
//2.如果在观察者和观察目标之间有循环依赖的话，观察目标会触发它们之间进行循环调用，导致系统崩溃。
//观察者模式的使用场景：
//1.关联行为场景。需要注意的是，关联行为是可拆分的，而不是“组合”关系。
//2.事件多级触发场景。
//3.跨系统的消息交换场景，如消息队列的处理机制。
//观察者模式的注意事项：
//1.广播链的问题。观察者模式可以用链式结构来解决耦合问题，但是会导致事件的传递链过长，影响效率。
//2.异步处理问题。观察者模式不能保证同步，需要自己考虑同步的问题。
//3.过多的细节问题。观察者模式中的观察者和被观察者之间是抽象耦合的，但是具体的观察者和被观察者之间还是有很大的过多细节问题需要考虑。
//4.性能问题。观察者模式中有一个通知观察者的顺序问题，需要考虑效率和稳定性的问题，可以采用异步的方式。

#include <iostream>
#include <list>
class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};;
class Subject{
public:
	virtual void attach(Observer* observer) = 0;
	virtual void detach(Observer* observer) = 0;
	virtual void notify() = 0;
	virtual ~Subject() {}
};
class WeatherData : public Subject {
private:
	std::list<Observer*> observers;
	int temperature;
public:
	void attach(Observer* observer) {
		observers.push_back(observer);
	}
	void detach(Observer* observer) {
		observers.remove(observer);
	}
	void notify() {
		std::list<Observer*>::iterator it = observers.begin();
		for (; it != observers.end(); it++) {
			(*it)->update();
		}
	}
	void setTemperature(int temperature) {
		this->temperature = temperature;
		this->notify();
	}
	int getTemperature() {
		return temperature;
	}
};
class CurrentConditionsDisplay :public Observer {
private:
	WeatherData* weatherData;
public:
    CurrentConditionsDisplay(WeatherData* weatherData) {
		this->weatherData = weatherData;
		weatherData->attach(this);
	}
	void update() {
		std::cout << "Current temperature is " << weatherData->getTemperature() << std::endl;
	}
};
#if 0
int main() {
	WeatherData* weatherData = new WeatherData();
	CurrentConditionsDisplay* currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
	weatherData->setTemperature(10);
	weatherData->setTemperature(20);
	weatherData->setTemperature(30);
	return 0;
}
#endif


