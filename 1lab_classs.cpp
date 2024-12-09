#include "Keeper.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Boat.h"
#include <iostream>
using namespace std;

int main() {
    Keeper keeper;
    int choice;
    setlocale(LC_ALL, "RU");
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить объект\n";
        cout << "2. Удалить объект\n";
        cout << "3. Редактировать объект\n";
        cout << "4. Показать объекты\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        try {
            if (choice == 1) {
                cout << "1. Подводная лодка\n2. Парусник\n3. Катер\nВаш выбор: ";
                cin >> choice;

                Base* obj = nullptr;
                if (choice == 1) obj = new Submarine();
                else if (choice == 2) obj = new Sailboat();
                else if (choice == 3) obj = new Boat();
                else continue;

                obj->input();
                keeper.addObject(obj);
            }
            else if (choice == 2) {
                int index;
                cout << "Введите номер объекта: ";
                cin >> index;
                keeper.removeObject(index - 1);
            }
            else if (choice == 3) {
                int index;
                cout << "Введите номер объекта: ";
                cin >> index;
                keeper.editObject(index - 1);
            }
            else if (choice == 4) {
                keeper.display();
            }
            else if (choice == 5) {
                keeper.saveToFile("data.txt");
            }
            else if (choice == 6) {
                keeper.loadFromFile("data.txt");
            }
            else if (choice == 0) {
                break;
            }
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}