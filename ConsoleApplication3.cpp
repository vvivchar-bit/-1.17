#include <iostream>
#include <string>
using namespace std;

// Dependency Inversion Principle
class Notifier {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notifier() = default;
};

class EmailNotifier : public Notifier {
public:
    void send(const string& message) override {
        cout << "Email notification: " << message << endl;
    }
};

class SmsNotifier : public Notifier {
public:
    void send(const string& message) override {
        cout << "SMS notification: " << message << endl;
    }
};

class OrderService {
private:
    Notifier* notifier;

public:
    OrderService(Notifier* notifierObject) {
        notifier = notifierObject;
    }

    void completeOrder() {
        cout << "Order was completed." << endl;
        notifier->send("Order completed successfully.");
    }
};

// Law of Demeter
class Address {
private:
    string city;

public:
    Address(const string& cityName) {
        city = cityName;
    }

    string getCity() const {
        return city;
    }
};

class Customer {
private:
    string name;
    Address address;

public:
    Customer(const string& customerName, const Address& customerAddress)
        : name(customerName), address(customerAddress) {
    }

    string getName() const {
        return name;
    }

    string getCity() const {
        return address.getCity();
    }
};

class Order {
private:
    Customer customer;

public:
    Order(const Customer& orderCustomer)
        : customer(orderCustomer) {
    }

    string getCustomerName() const {
        return customer.getName();
    }

    string getCustomerCity() const {
        return customer.getCity();
    }
};

int main() {
    cout << "Dependency Inversion Principle example:" << endl;

    EmailNotifier emailNotifier;
    SmsNotifier smsNotifier;

    OrderService emailOrderService(&emailNotifier);
    OrderService smsOrderService(&smsNotifier);

    emailOrderService.completeOrder();
    smsOrderService.completeOrder();

    cout << endl;

    cout << "Law of Demeter example:" << endl;

    Address address("Kyiv");
    Customer customer("Vadim", address);
    Order order(customer);

    cout << "Customer name: " << order.getCustomerName() << endl;
    cout << "Customer city: " << order.getCustomerCity() << endl;

    cout << endl;
    cout << "The client code does not call order.getCustomer().getAddress().getCity()." << endl;
    cout << "It uses one simple method: order.getCustomerCity()." << endl;

    return 0;
}
