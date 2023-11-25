//�۲���ģʽ�ĺ��壺�����˶���֮���һ�Զ��������ö���۲��߶���ͬʱ����ĳһ���������
//������������仯ʱ���������������ߣ��۲��ߣ������յ�֪ͨ�����¡�
//�۲���ģʽ���ŵ㣺
//1.�۲��ߺͱ��۲���֮���ǳ�����ϵġ�
//2.����һ�״������ơ�
//�۲���ģʽ��ȱ�㣺
//1.���һ�����۲��߶����кܶ�ֱ�Ӻͼ�ӵĹ۲��ߵĻ��������еĹ۲��߶�֪ͨ���Ứ�Ѻܶ�ʱ�䡣
//2.����ڹ۲��ߺ͹۲�Ŀ��֮����ѭ�������Ļ����۲�Ŀ��ᴥ������֮�����ѭ�����ã�����ϵͳ������
//�۲���ģʽ��ʹ�ó�����
//1.������Ϊ��������Ҫע����ǣ�������Ϊ�ǿɲ�ֵģ������ǡ���ϡ���ϵ��
//2.�¼��༶����������
//3.��ϵͳ����Ϣ��������������Ϣ���еĴ�����ơ�
//�۲���ģʽ��ע�����
//1.�㲥�������⡣�۲���ģʽ��������ʽ�ṹ�����������⣬���ǻᵼ���¼��Ĵ�����������Ӱ��Ч�ʡ�
//2.�첽�������⡣�۲���ģʽ���ܱ�֤ͬ������Ҫ�Լ�����ͬ�������⡣
//3.�����ϸ�����⡣�۲���ģʽ�еĹ۲��ߺͱ��۲���֮���ǳ�����ϵģ����Ǿ���Ĺ۲��ߺͱ��۲���֮�仹���кܴ�Ĺ���ϸ��������Ҫ���ǡ�
//4.�������⡣�۲���ģʽ����һ��֪ͨ�۲��ߵ�˳�����⣬��Ҫ����Ч�ʺ��ȶ��Ե����⣬���Բ����첽�ķ�ʽ��

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


