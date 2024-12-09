#pragma once
#include "Base.h"
#include <string>

class Boat : public Base {
private:
    std::string purpose, material;
    float speed;
    int capacity;
public:
    Boat();
    Boat(const std::string& purpose, const std::string& material, float speed, int capacity);
    Boat(const Boat& other);

    void input() override;
    void output() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    std::string getPurpose() const;
    void setPurpose(const std::string& purpose);

    std::string getMaterial() const;
    void setMaterial(const std::string& material);

    float getSpeed() const;
    void setSpeed(float speed);

    int getCapacity() const;
    void setCapacity(int capacity);

    ~Boat();
};
