#pragma once

#include <iostream>
#include <string>

#include "../interfaces/IStorageObser.h"

class Book : public IStorageObser
{
protected:
    float cost;
    std::string description;
    std::string bookType;
    std::string bookExtension;

public:
    virtual std::string getBookExtension()
    {
        return this->bookExtension;
    }

    virtual void setBookExtension(const std::string &ext)
    {
        this->bookExtension = ext;
    }

    virtual std::string getBookType()
    {
        return this->bookType;
    }

    virtual void setBookType(const std::string &bType)
    {
        this->bookType = bType;
    }

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

    virtual void setDescription(const std::string &desc)
    {
        this->description = static_cast<std::string>(desc);
    }

    void update(const float &price)
    {
        setCost(price);
    }

    Book() {}

    ~Book() {}

    Book(const Book &other)
    {
        this->cost = other.cost;
        this->description = other.description;
        this->bookType = other.bookType;
        this->bookExtension = other.bookExtension;
    }

    Book &operator=(const Book &other)
    {
        this->cost = other.cost;
        this->description = other.description;
        this->bookType = other.bookType;
        this->bookExtension = other.bookExtension;
    }
};
