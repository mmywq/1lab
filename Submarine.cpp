#include "Submarine.h"
#include <iostream>
#include <fstream>
using namespace std;

Submarine::Submarine() : length(0), width(0), crew(0), underwaterTime(0), maxSpeed(0), weapons("None") {
    cout << "������ ����������� Submarine �� ���������" << endl;
}

Submarine::Submarine(float length, float width, int crew, int underwaterTime, int maxSpeed, const string& weapons)
    : length(length), width(width), crew(crew), underwaterTime(underwaterTime), maxSpeed(maxSpeed), weapons(weapons) {
    cout << "������ ����������� Submarine � �����������" << endl;
}

Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew),
    underwaterTime(other.underwaterTime), maxSpeed(other.maxSpeed), weapons(other.weapons) {
    cout << "������ ����������� ����������� Submarine" << endl;
}

void Submarine::input() {
    cout << "������� �����: ";
    cin >> length;
    cout << "������� ������: ";
    cin >> width;
    cout << "������� ������: ";
    cin >> crew;
    cout << "������� ����� ��� �����: ";
    cin >> underwaterTime;
    cout << "������� ������������ ��������: ";
    cin >> maxSpeed;
    cout << "������� ����������: ";
    cin.ignore();
    getline(cin, weapons);
}

void Submarine::output() const {
    cout << "��������� �����: ����� " << length << ", ������ " << width
        << ", ������ " << crew << ", ����� ��� ����� " << underwaterTime
        << ", �������� " << maxSpeed << ", ���������� " << weapons << endl;
}

void Submarine::saveToFile(ofstream& file) const {
    file << "Length: " << length << " "
        << "Width: " << width << " "
        << "Crew: " << crew << " "
        << "UnderwaterTime: " << underwaterTime << " "
        << "MaxSpeed: " << maxSpeed << " "
        << "Weapons: " << weapons;
}

void Submarine::loadFromFile(ifstream& file) {
    string label;
    file >> label >> length;
    file >> label >> width;
    file >> label >> crew;
    file >> label >> underwaterTime;
    file >> label >> maxSpeed;
    file.ignore();
    getline(file, weapons);
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

string Submarine::getWeapons() const { return weapons; }
void Submarine::setWeapons(const string& weapons) { this->weapons = weapons; }

Submarine::~Submarine() {
    cout << "������ ���������� Submarine" << endl;
}
