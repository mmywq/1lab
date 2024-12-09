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
        cout << "\n����:\n";
        cout << "1. �������� ������\n";
        cout << "2. ������� ������\n";
        cout << "3. ������������� ������\n";
        cout << "4. �������� �������\n";
        cout << "5. ��������� � ����\n";
        cout << "6. ��������� �� �����\n";
        cout << "0. �����\n";
        cout << "��� �����: ";
        cin >> choice;

        try {
            if (choice == 1) {
                cout << "1. ��������� �����\n2. ��������\n3. �����\n��� �����: ";
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
                cout << "������� ����� �������: ";
                cin >> index;
                keeper.removeObject(index - 1);
            }
            else if (choice == 3) {
                int index;
                cout << "������� ����� �������: ";
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
            cout << "������: " << e.what() << endl;
        }
    }

    return 0;
}