#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Open/Closed Principle
class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() = default;
};

class CardPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Card payment: " << amount << " UAH" << endl;
    }
};

class PayPalPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "PayPal payment: " << amount << " UAH" << endl;
    }
};

// Liskov Substitution Principle
class Bird {
public:
    virtual void move() = 0;
    virtual ~Bird() = default;
};

class Sparrow : public Bird {
public:
    void move() override {
        cout << "Sparrow moves by flying." << endl;
    }
};

class Penguin : public Bird {
public:
    void move() override {
        cout << "Penguin moves by swimming." << endl;
    }
};

// Interface Segregation Principle
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

class HumanWorker : public Workable, public Eatable {
public:
    void work() override {
        cout << "Human worker is working." << endl;
    }

    void eat() override {
        cout << "Human worker is eating." << endl;
    }
};

class RobotWorker : public Workable {
public:
    void work() override {
        cout << "Robot worker is working." << endl;
    }
};

int main() {
    cout << "Open/Closed Principle example:" << endl;

    vector<unique_ptr<Payment>> payments;
    payments.push_back(make_unique<CardPayment>());
    payments.push_back(make_unique<PayPalPayment>());

    for (auto& payment : payments) {
        payment->pay(500);
    }

    cout << endl;

    cout << "Liskov Substitution Principle example:" << endl;

    vector<unique_ptr<Bird>> birds;
    birds.push_back(make_unique<Sparrow>());
    birds.push_back(make_unique<Penguin>());

    for (auto& bird : birds) {
        bird->move();
    }

    cout << endl;

    cout << "Interface Segregation Principle example:" << endl;

    HumanWorker human;
    RobotWorker robot;

    human.work();
    human.eat();
    robot.work();

    return 0;
}
