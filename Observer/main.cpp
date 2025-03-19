#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// 观察者接口
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(int state) = 0;  // 观察者的更新接口
};

// 被观察者（Subject）
class Subject {
private:
    std::vector<Observer*> observers;  // 存储观察者

public:
    void attach(Observer* observer) {  // 订阅
        observers.push_back(observer);
    }

    void detach(Observer* observer) {  // 取消订阅
        auto it = std::find(observers.begin(), observers.end(), observer);
        if(it!=observers.end())
            observers.erase(it);
    }

    void notify(int state) {  // 通知所有观察者
        for (Observer* observer : observers) {
            observer->update(state);
        }
    }
};

// 具体被观察者
class ConcreteSubject : public Subject {
private:
    int state;

public:
    void setState(int newState) {
        state = newState;
        notify(state);  // 状态变更后通知观察者
    }
};

// 具体观察者
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    explicit ConcreteObserver(const std::string& n) : name(n) {}

    void update(int state) override {
        std::cout << "Observer " << name << " received update: State = " << state << std::endl;
    }
};

// 主函数示例
int main() {
    ConcreteSubject subject;

    ConcreteObserver observer1("A"), observer2("B");
    
    subject.attach(&observer1);
    subject.attach(&observer2);

    std::cout << "Setting state to 1...\n";
    subject.setState(1);

    subject.detach(&observer1);  // 移除 observer1
    std::cout << "Setting state to 2...\n";
    subject.setState(2);

    return 0;
}
