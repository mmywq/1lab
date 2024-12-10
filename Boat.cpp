#include "Boat.h"
#include <iostream>
#include <fstream>
using namespace std;

Boat::Boat() : purpose("Unknown"), material("Unknown"), speed(0), capacity(0) {
    cout << "Вызван конструктор Boat по умолчанию" << endl;
}

Boat::Boat(const string& purpose, const string& material, float speed, int capacity)
    : purpose(purpose), material(material), speed(speed), capacity(capacity) {
    cout << "Вызван конструктор Boat с параметрами" << endl;
}

Boat::Boat(const Boat& other)
    : purpose(other.purpose), material(other.material), speed(other.speed), capacity(other.capacity) {
    cout << "Вызван конструктор копирования Boat" << endl;
}

void Boat::input() {
    cout << "Введите назначение катера: ";
    cin.ignore();
    getline(cin, purpose);
    cout << "Введите материал корпуса: ";
    getline(cin, material);
    cout << "Введите скорость: ";
    cin >> speed;
    cout << "Введите вместимость: ";
    cin >> capacity;
}

void Boat::output() const {
    cout << "Катер: назначение " << purpose << ", материал " << material
        << ", скорость " << speed << ", вместимость " << capacity << endl;
}

void Boat::saveToFile(ofstream& file) const {
    file << "Purpose: " << purpose << " "
        << "Material: " << material << " "
        << "Speed: " << speed << " "
        << "Capacity: " << capacity;
}

void Boat::loadFromFile(ifstream& file) {
    string label;
    file >> label >> purpose;
    file >> label >> material;
    file >> label >> speed;
    file >> label >> capacity;
}

string Boat::getPurpose() const { return purpose; }
void Boat::setPurpose(const string& purpose) { this->purpose = purpose; }

string Boat::getMaterial() const { return material; }
void Boat::setMaterial(const string& material) { this->material = material; }

float Boat::getSpeed() const { return speed; }
void Boat::setSpeed(float speed) { this->speed = speed; }

int Boat::getCapacity() const { return capacity; }
void Boat::setCapacity(int capacity) { this->capacity = capacity; }

Boat::~Boat() {
    cout << "Вызван деструктор Boat" << endl;
}
