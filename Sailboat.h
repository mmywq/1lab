#pragma once
#include "Base.h"
#include <string>

class Sailboat : public Base {
private:
    std::string type, name;
    bool isMilitary;
    float length, speed;
    int crew;
public:
    Sailboat();
    Sailboat(const std::string& type, const std::string& name, bool isMilitary, float length, float speed, int crew);
    Sailboat(const Sailboat& other);

    void input() override;
    void output() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    std::string getType() const;
    void setType(const std::string& type);

    std::string getName() const;
    void setName(const std::string& name);

    bool getIsMilitary() const;
    void setIsMilitary(bool isMilitary);

    float getLength() const;
    void setLength(float length);

    float getSpeed() const;
    void setSpeed(float speed);

    int getCrew() const;
    void setCrew(int crew);

    ~Sailboat();
};
