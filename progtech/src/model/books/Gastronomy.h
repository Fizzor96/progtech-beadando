#pragma once

#include <iostream>
#include "../Book.h"

using namespace std;

class Gastronomy : public Book
{
public:
    float getCost() const override
    {
        return cost;
    }

    void setCost(const float &cost) override
    {
        this->cost = cost;
    }

    std::string getDescription() const override
    {
        return this->description;
    }

    void setDescription(const std::string &desc) override
    {
        this->description = desc;
    }

    Gastronomy()
    {
        this->cost = 11.1;
        this->description = "One Gastronomy book etc, etc.";
    }
    ~Gastronomy() {}
};