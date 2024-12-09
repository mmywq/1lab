#pragma once
#include "Base.h"
#include <string>

class Keeper {
private:
    Base** objects;
    int size;
    int capacity;

    void expand(); // ����������� ������� �������
public:
    Keeper();
    ~Keeper();

    void addObject(Base* obj);
    void removeObject(int index);
    void editObject(int index); // ��������� ������������� ������

    void display() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
