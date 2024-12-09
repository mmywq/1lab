#pragma once
#include <fstream>

class Base {
public:
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;
    virtual ~Base() = default;
};
