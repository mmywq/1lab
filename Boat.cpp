#include "Boat.h"
#include <iostream>
#include <fstream>
using namespace std;

Boat::Boat() : purpose("Unknown"), material("Unknown"), speed(0), capacity(0) {
    cout << "������ ����������� Boat �� ���������" << endl;
}

Boat::Boat(const string& purpose, const string& material, float speed, int capacity)
    : purpose(purpose), material(material), speed(speed), capacity(capacity) {
    cout << "������ ����������� Boat � �����������" << endl;
}

Boat::Boat(const Boat& other)
    : purpose(other.purpose), material(other.material), speed(other.speed), capacity(other.capacity) {
    cout << "������ ����������� ����������� Boat" << endl;
}

void Boat::input() {
    cout << "������� ���������� ������: ";
    cin.ignore();
    getline(cin, purpose);
    cout << "������� �������� �������: ";
    getline(cin, material);
    cout << "������� ��������: ";
    cin >> speed;
    cout << "������� �����������: ";
    cin >> capacity;
}

void Boat::output() const {
    cout << "�����: ���������� " << purpose << ", �������� " << material
        << ", �������� " << speed << ", ����������� " << capacity << endl;
}

void Boat::saveToFile(ofstream& file) const {
    size_t purposeSize = purpose.size();
    file.write(reinterpret_cast<const char*>(&purposeSize), sizeof(purposeSize));
    file.write(purpose.data(), purposeSize);

    size_t materialSize = material.size();
    file.write(reinterpret_cast<const char*>(&materialSize), sizeof(materialSize));
    file.write(material.data(), materialSize);

    file.write(reinterpret_cast<const char*>(&speed), sizeof(speed));
    file.write(reinterpret_cast<const char*>(&capacity), sizeof(capacity));
}

void Boat::loadFromFile(ifstream& file) {
    size_t purposeSize;
    file.read(reinterpret_cast<char*>(&purposeSize), sizeof(purposeSize));
    purpose.resize(purposeSize);
    file.read(&purpose[0], purposeSize);

    size_t materialSize;
    file.read(reinterpret_cast<char*>(&materialSize), sizeof(materialSize));
    material.resize(materialSize);
    file.read(&material[0], materialSize);

    file.read(reinterpret_cast<char*>(&speed), sizeof(speed));
    file.read(reinterpret_cast<char*>(&capacity), sizeof(capacity));
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
    cout << "������ ���������� Boat" << endl;
}