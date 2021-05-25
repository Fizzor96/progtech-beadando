#pragma once

#include <iostream>
#include "../Book.h"

using namespace std;

class History : public Book
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

    History()
    {
        this->cost = 33.3;
        this->description = "One History book etc, etc.";
    }
    ~History() {}
};