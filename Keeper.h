#pragma once
#include "Base.h"
#include <string>

class Keeper {
private:
    Base** objects;
    int size;
    int capacity;

    void expand(); // Увеличивает емкость массива
public:
    Keeper();
    ~Keeper();

    void addObject(Base* obj);
    void removeObject(int index);
    void editObject(int index); // Позволяет редактировать объект

    void display() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
