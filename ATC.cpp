#include <iostream>
#include <string>

using namespace std;

class ATC {
private:
    string address;      // ���� ��� �������� ������ ���
    int numSubscribers;       // ���� ��� �������� ����� ���������
    double feePerSubscriber;  // ���� ��� �������� ����������� ����� (���������� ��� ����)

public:
    // ����������� ������
    ATC(string addr, int subscribers, double fee) {
        address = addr;
        numSubscribers = subscribers;
        feePerSubscriber = fee;
    }

    // ����� ��� �������� ����� ����� ����������� ����� ���� ��������
    double calculateTotalFee() const {
        return numSubscribers * feePerSubscriber;
    }

    // ������� (�������� ������ ��� ������)
    void setAddress(const string& addr) {
        address = addr;
    }

    void setNumSubscribers(int subscribers) {
        numSubscribers = subscribers;
    }

    void setFeePerSubscriber(double fee) {
        feePerSubscriber = fee;
    }

    // ����� ��� ����������� ���������� �� ���
    void displayInfo() const {
        cout << "Address: " << address << endl;
        cout << "Number of Subscribers: " << numSubscribers << endl;
        cout << "Fee per Subscriber: " << feePerSubscriber << endl;
    }
};
