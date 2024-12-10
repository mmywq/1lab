#include "Keeper.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Boat.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

Keeper::Keeper() : objects(nullptr), size(0), capacity(0) {}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete objects[i];
    }
    delete[] objects;
}

void Keeper::expand() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Base** newObjects = new Base * [capacity];
    for (int i = 0; i < size; ++i) {
        newObjects[i] = objects[i];
    }
    delete[] objects;
    objects = newObjects;
}

void Keeper::addObject(Base* obj) {
    if (size == capacity) {
        expand();
    }
    objects[size++] = obj;
}

void Keeper::removeObject(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Индекс вне диапазона");
    }
    delete objects[index];
    for (int i = index; i < size - 1; ++i) {
        objects[i] = objects[i + 1];
    }
    --size;
}

void Keeper::editObject(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Индекс вне диапазона");
    }
    cout << "Редактирование объекта:" << endl;
    objects[index]->input();
}

void Keeper::display() const {
    if (size == 0) {
        cout << "Контейнер пуст." << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". ";
        objects[i]->output();
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream file(filename, ios::out);
    if (!file.is_open()) {
        throw runtime_error("Ошибка открытия файла для записи");
    }

    file << size << "\n"; // Сохранение количества объектов
    for (int i = 0; i < size; ++i) {
        Submarine* submarine = dynamic_cast<Submarine*>(objects[i]);
        Sailboat* sailboat = dynamic_cast<Sailboat*>(objects[i]);
        Boat* boat = dynamic_cast<Boat*>(objects[i]);

        if (submarine) {
            file << i + 1 << " S ";
            submarine->saveToFile(file);
            file << "\n";
        }
        else if (sailboat) {
            file << i + 1 << " B ";
            sailboat->saveToFile(file);
            file << "\n";
        }
        else if (boat) {
            file << i + 1 << " T ";
            boat->saveToFile(file);
            file << "\n";
        }
    }
}

void Keeper::loadFromFile(const string& filename) {
    ifstream file(filename, ios::in);
    if (!file.is_open()) {
        throw runtime_error("Ошибка открытия файла для чтения");
    }

    int newSize;
    file >> newSize;
    file.ignore();

    for (int i = 0; i < size; ++i) {
        delete objects[i];
    }
    delete[] objects;

    size = newSize;
    capacity = newSize;
    objects = new Base * [capacity];

    for (int i = 0; i < size; ++i) {
        int index;
        char type;
        file >> index >> type;

        Base* obj = nullptr;
        if (type == 'S') {
            obj = new Submarine();
        }
        else if (type == 'B') {
            obj = new Sailboat();
        }
        else if (type == 'T') {
            obj = new Boat();
        }

        if (obj) {
            obj->loadFromFile(file);
            objects[i] = obj;
        }
    }
}
