#include <iostream>
#include "Book.h"

using namespace std;

class AddonDecorator : public Book
{
protected:
    Book book;

public:
    float getCost() const override
    {
        return this->book.getCost();
    }

    void setCost(const float &cost) override
    {
        this->book.setCost(cost);
    }

    std::string getDescription() const override
    {
        return this->book.getDescription();
    }

    void setDescription(const std::string &desc) override
    {
        this->book.setDescription(desc);
    }

    AddonDecorator() {}

    AddonDecorator(const std::string &bookType)
    {
        this->book.setBookType(bookType);
    }

    ~AddonDecorator();
};