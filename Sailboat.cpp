#include "Sailboat.h"
#include <iostream>
#include <fstream>
using namespace std;

Sailboat::Sailboat() : type("Unknown"), name("Unknown"), isMilitary(false), length(0), speed(0), crew(0) {
    cout << "������ ����������� Sailboat �� ���������" << endl;
}

Sailboat::Sailboat(const string& type, const string& name, bool isMilitary, float length, float speed, int crew)
    : type(type), name(name), isMilitary(isMilitary), length(length), speed(speed), crew(crew) {
    cout << "������ ����������� Sailboat � �����������" << endl;
}

Sailboat::Sailboat(const Sailboat& other)
    : type(other.type), name(other.name), isMilitary(other.isMilitary), length(other.length), speed(other.speed), crew(other.crew) {
    cout << "������ ����������� ����������� Sailboat" << endl;
}

void Sailboat::input() {
    cout << "������� ��� ���������: ";
    cin.ignore();
    getline(cin, type);
    cout << "������� ��������: ";
    getline(cin, name);
    cout << "������� (1) ��� ������ (0): ";
    cin >> isMilitary;
    cout << "������� ����� �������: ";
    cin >> length;
    cout << "������� ��������: ";
    cin >> speed;
    cout << "������� ������: ";
    cin >> crew;
}

void Sailboat::output() const {
    cout << "��������: ��� " << type << ", �������� " << name
        << ", " << (isMilitary ? "�������" : "������") << ", ����� " << length
        << ", �������� " << speed << ", ������ " << crew << endl;
}

void Sailboat::saveToFile(ofstream& file) const {
    file << "Type: " << type << " "
        << "Name: " << name << " "
        << "IsMilitary: " << (isMilitary ? "Yes" : "No") << " "
        << "Length: " << length << " "
        << "Speed: " << speed << " "
        << "Crew: " << crew;
}

void Sailboat::loadFromFile(ifstream& file) {
    string label;
    file >> label >> type;
    file >> label >> name;
    file >> label;
    string militaryStatus;
    file >> militaryStatus;
    isMilitary = (militaryStatus == "Yes");
    file >> label >> length;
    file >> label >> speed;
    file >> label >> crew;
}

string Sailboat::getType() const { return type; }
void Sailboat::setType(const string& type) { this->type = type; }

string Sailboat::getName() const { return name; }
void Sailboat::setName(const string& name) { this->name = name; }

bool Sailboat::getIsMilitary() const { return isMilitary; }
void Sailboat::setIsMilitary(bool isMilitary) { this->isMilitary = isMilitary; }

float Sailboat::getLength() const { return length; }
void Sailboat::setLength(float length) { this->length = length; }

float Sailboat::getSpeed() const { return speed; }
void Sailboat::setSpeed(float speed) { this->speed = speed; }

int Sailboat::getCrew() const { return crew; }
void Sailboat::setCrew(int crew) { this->crew = crew; }

Sailboat::~Sailboat() {
    cout << "������ ���������� Sailboat" << endl;
}
