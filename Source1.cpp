#include "ATC.cpp"  // Подключаем файл с классом
#include <iostream>
#include <stdexcept> // Для обработки исключений
#include <limits>    // Для numeric_limits
#include <sstream>   // Для использования stringstream

using namespace std;

// Функция для проверки ввода числа и выброса исключения при ошибке
template <typename T>
void validateInput(T& var) {
    string input;
    getline(cin, input);  // Читаем всю строку

    // Используем stringstream для обработки ввода
    stringstream ss(input);
    if (!(ss >> var) || !(ss.eof())) {  // Проверяем, успешно ли считано и нет ли лишних символов
        throw runtime_error("Ошибка ввода: Введено некорректное значение.");
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        // Ввод адреса
        string adress;
        cout << "Введите адрес: ";
        getline(cin, adress);  // Читаем адрес целиком, включая пробелы

        // Ввод количества подписчиков с проверкой
        int subs;
        cout << "Введите количество подписчиков: ";
        validateInput(subs);
        if (subs < 0) {
            throw runtime_error("Количество подписчиков не может быть отрицательным.");
        }

        // Ввод цены с проверкой
        float fee;
        cout << "Введите цену: ";
        validateInput(fee);
        if (fee < 0) {
            throw runtime_error("Цена не может быть отрицательной.");
        }

        // Создаем объект класса ATC с начальными данными
        ATC atc(adress, subs, fee);

        // Отображаем информацию об АТС
        atc.displayInfo();

        // Выводим общую сумму абонентской платы всех абонентов
        cout << "Total Fee for all Subscribers: " << atc.calculateTotalFee() << endl;
        cout << endl << endl;

        // Изменение данных
        cout << "Измените данные для класса" << endl;

        // Ввод нового адреса
        string adress2;
        cout << "Введите новый адрес: ";
        getline(cin, adress2);  // Читаем новый адрес целиком, включая пробелы

        // Ввод нового количества подписчиков с проверкой
        int subs2;
        cout << "Введите количество подписчиков: ";
        validateInput(subs2);
        if (subs2 < 0) {
            throw runtime_error("Количество подписчиков не может быть отрицательным.");
        }

        // Ввод новой цены с проверкой
        float fee2;
        cout << "Введите новую цену: ";
        validateInput(fee2);
        if (fee2 < 0) {
            throw runtime_error("Цена не может быть отрицательной.");
        }

        // Изменяем адрес АТС и количество абонентов
        atc.setAddress(adress2);
        atc.setNumSubscribers(subs2);
        atc.setFeePerSubscriber(fee2);

        // Отображаем обновленную информацию
        atc.displayInfo();
        cout << "Total Fee for all Subscribers: " << atc.calculateTotalFee() << endl;

    }
    catch (const runtime_error& e) {
        // Обрабатываем исключения, выводим сообщение об ошибке
        cerr << "Ошибка: " << e.what() << endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    return 0;
}
