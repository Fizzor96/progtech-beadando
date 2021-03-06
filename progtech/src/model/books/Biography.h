#pragma once

#include <iostream>
#include "../Book.h"

using namespace std;

class Biography : public Book
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

    Biography()
    {
        this->cost = 22.2;
        this->description = "One Biography book etc, etc.";
    }
    ~Biography() {}
};