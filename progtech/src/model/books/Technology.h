#pragma once

#include <iostream>
#include "../Book.h"

using namespace std;

class Technology : public Book
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

    Technology()
    {
        this->cost = 44.4;
        this->description = "One Technology book etc, etc.";
    }
    ~Technology() {}
};