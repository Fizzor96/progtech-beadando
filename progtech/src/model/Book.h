#pragma once

#include <iostream>
#include <string>

#include "../interfaces/IStorageObser.h"

class Book : public IStorageObser
{
private:
    float cost;
    std::string description;

public:
    virtual float getCost() const
    {
        return this->cost;
    }
    virtual void setCost(const float &value)
    {
        this->cost = value;
    }
    virtual std::string getDescription() const
    {
        return this->description;
    }
    virtual void setDescription(const char *descriptstr)
    {
        this->description = static_cast<std::string>(description);
    }

    void update(const float &price) override
    {
        setCost(price);
    }

    Book() {}
    ~Book() {}
};
