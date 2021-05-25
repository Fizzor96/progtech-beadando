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
    void toStr()
    {
        std::cout << this->cost << " " << this->bookType << " " << this->bookExtension << " " << this->description << std::endl;
    }

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

    Book()
    {
        // this->bookExtension = "";
        // this->bookType = "";
        // this->description = "";
    }

    Book(std::string bookType)
    {
        this->bookType = bookType;
    }

    Book(std::string bookType, std::string ext)
    {
        this->bookType = bookType;
        this->bookExtension = ext;
    }

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
