#include "Submarine.h"
#include <iostream>
#include <fstream>
using namespace std;

Submarine::Submarine() : length(0), width(0), crew(0), underwaterTime(0), maxSpeed(0), weapons("None") {
    cout << "Вызван конструктор Submarine по умолчанию" << endl;
}

Submarine::Submarine(float length, float width, int crew, int underwaterTime, int maxSpeed, const std::string& weapons)
    : length(length), width(width), crew(crew), underwaterTime(underwaterTime), maxSpeed(maxSpeed), weapons(weapons) {
    cout << "Вызван конструктор Submarine с параметрами" << endl;
}

Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew),
    underwaterTime(other.underwaterTime), maxSpeed(other.maxSpeed), weapons(other.weapons) {
    cout << "Вызван конструктор копирования Submarine" << endl;
}

void Submarine::input() {
    cout << "Введите длину: ";
    cin >> length;
    cout << "Введите ширину: ";
    cin >> width;
    cout << "Введите экипаж: ";
    cin >> crew;
    cout << "Введите время под водой: ";
    cin >> underwaterTime;
    cout << "Введите максимальную скорость: ";
    cin >> maxSpeed;
    cout << "Введите вооружение: ";
    cin.ignore();
    getline(cin, weapons);
}

void Submarine::output() const {
    cout << "Подводная лодка: длина " << length << ", ширина " << width
        << ", экипаж " << crew << ", время под водой " << underwaterTime
        << ", скорость " << maxSpeed << ", вооружение " << weapons << endl;
}

void Submarine::saveToFile(ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(reinterpret_cast<const char*>(&width), sizeof(width));
    file.write(reinterpret_cast<const char*>(&crew), sizeof(crew));
    file.write(reinterpret_cast<const char*>(&underwaterTime), sizeof(underwaterTime));
    file.write(reinterpret_cast<const char*>(&maxSpeed), sizeof(maxSpeed));

    size_t size = weapons.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    file.write(weapons.data(), size);
}

void Submarine::loadFromFile(ifstream& file) {
    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    file.read(reinterpret_cast<char*>(&width), sizeof(width));
    file.read(reinterpret_cast<char*>(&crew), sizeof(crew));
    file.read(reinterpret_cast<char*>(&underwaterTime), sizeof(underwaterTime));
    file.read(reinterpret_cast<char*>(&maxSpeed), sizeof(maxSpeed));

    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    weapons.resize(size);
    file.read(&weapons[0], size);
}

float Submarine::getLength() const { return length; }
void Submarine::setLength(float length) { this->length = length; }

float Submarine::getWidth() const { return width; }
void Submarine::setWidth(float width) { this->width = width; }

int Submarine::getCrew() const { return crew; }
void Submarine::setCrew(int crew) { this->crew = crew; }

int Submarine::getUnderwaterTime() const { return underwaterTime; }
void Submarine::setUnderwaterTime(int underwaterTime) { this->underwaterTime = underwaterTime; }

int Submarine::getMaxSpeed() const { return maxSpeed; }
void Submarine::setMaxSpeed(int maxSpeed) { this->maxSpeed = maxSpeed; }

std::string Submarine::getWeapons() const { return weapons; }
void Submarine::setWeapons(const std::string& weapons) { this->weapons = weapons; }

Submarine::~Submarine() {
    cout << "Вызван деструктор Submarine" << endl;
}
