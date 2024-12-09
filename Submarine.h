#pragma once
#include "Base.h"
#include <string>

class Submarine : public Base {
private:
    float length, width;
    int crew;
    int underwaterTime, maxSpeed;
    std::string weapons;
public:
    Submarine();
    Submarine(float length, float width, int crew, int underwaterTime, int maxSpeed, const std::string& weapons);
    Submarine(const Submarine& other);

    void input() override;
    void output() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    float getLength() const;
    void setLength(float length);

    float getWidth() const;
    void setWidth(float width);

    int getCrew() const;
    void setCrew(int crew);

    int getUnderwaterTime() const;
    void setUnderwaterTime(int underwaterTime);

    int getMaxSpeed() const;
    void setMaxSpeed(int maxSpeed);

    std::string getWeapons() const;
    void setWeapons(const std::string& weapons);

    ~Submarine();
};
