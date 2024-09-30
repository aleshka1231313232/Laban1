#include <iostream>
#include <string>

using namespace std;

class ATC {
private:
    string address;      // Поле для хранения адреса АТС
    int numSubscribers;       // Поле для хранения числа абонентов
    double feePerSubscriber;  // Поле для хранения абонентской платы (одинаковая для всех)

public:
    // Конструктор класса
    ATC(string addr, int subscribers, double fee) {
        address = addr;
        numSubscribers = subscribers;
        feePerSubscriber = fee;
    }

    // Метод для подсчета общей суммы абонентской платы всех клиентов
    double calculateTotalFee() const {
        return numSubscribers * feePerSubscriber;
    }

    // Сеттеры (свойства только для записи)
    void setAddress(const string& addr) {
        address = addr;
    }

    void setNumSubscribers(int subscribers) {
        numSubscribers = subscribers;
    }

    void setFeePerSubscriber(double fee) {
        feePerSubscriber = fee;
    }

    // Метод для отображения информации об АТС
    void displayInfo() const {
        cout << "Address: " << address << endl;
        cout << "Number of Subscribers: " << numSubscribers << endl;
        cout << "Fee per Subscriber: " << feePerSubscriber << endl;
    }
};
