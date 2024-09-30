#include "ATC.cpp"  // ���������� ���� � �������
#include <iostream>
#include <stdexcept> // ��� ��������� ����������
#include <limits>    // ��� numeric_limits
#include <sstream>   // ��� ������������� stringstream

using namespace std;

// ������� ��� �������� ����� ����� � ������� ���������� ��� ������
template <typename T>
void validateInput(T& var) {
    string input;
    getline(cin, input);  // ������ ��� ������

    // ���������� stringstream ��� ��������� �����
    stringstream ss(input);
    if (!(ss >> var) || !(ss.eof())) {  // ���������, ������� �� ������� � ��� �� ������ ��������
        throw runtime_error("������ �����: ������� ������������ ��������.");
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        // ���� ������
        string adress;
        cout << "������� �����: ";
        getline(cin, adress);  // ������ ����� �������, ������� �������

        // ���� ���������� ����������� � ���������
        int subs;
        cout << "������� ���������� �����������: ";
        validateInput(subs);
        if (subs < 0) {
            throw runtime_error("���������� ����������� �� ����� ���� �������������.");
        }

        // ���� ���� � ���������
        float fee;
        cout << "������� ����: ";
        validateInput(fee);
        if (fee < 0) {
            throw runtime_error("���� �� ����� ���� �������������.");
        }

        // ������� ������ ������ ATC � ���������� �������
        ATC atc(adress, subs, fee);

        // ���������� ���������� �� ���
        atc.displayInfo();

        // ������� ����� ����� ����������� ����� ���� ���������
        cout << "Total Fee for all Subscribers: " << atc.calculateTotalFee() << endl;
        cout << endl << endl;

        // ��������� ������
        cout << "�������� ������ ��� ������" << endl;

        // ���� ������ ������
        string adress2;
        cout << "������� ����� �����: ";
        getline(cin, adress2);  // ������ ����� ����� �������, ������� �������

        // ���� ������ ���������� ����������� � ���������
        int subs2;
        cout << "������� ���������� �����������: ";
        validateInput(subs2);
        if (subs2 < 0) {
            throw runtime_error("���������� ����������� �� ����� ���� �������������.");
        }

        // ���� ����� ���� � ���������
        float fee2;
        cout << "������� ����� ����: ";
        validateInput(fee2);
        if (fee2 < 0) {
            throw runtime_error("���� �� ����� ���� �������������.");
        }

        // �������� ����� ��� � ���������� ���������
        atc.setAddress(adress2);
        atc.setNumSubscribers(subs2);
        atc.setFeePerSubscriber(fee2);

        // ���������� ����������� ����������
        atc.displayInfo();
        cout << "Total Fee for all Subscribers: " << atc.calculateTotalFee() << endl;

    }
    catch (const runtime_error& e) {
        // ������������ ����������, ������� ��������� �� ������
        cerr << "������: " << e.what() << endl;
        return 1; // ��������� ��������� � ����� ������
    }

    return 0;
}
