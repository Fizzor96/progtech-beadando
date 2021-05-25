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

    void setCost(float cost) override
    {
        this->book.setCost(cost);
    }

    std::string getDescription() override
    {
        return this->book.getDescription();
    }

    void setDescription(const std::string &desc) override
    {
        this->book.setDescription(desc);
    }

    AddonDecorator(const std::string &bookType)
    {
        this->book.setBookType(bookType);
    }

    ~AddonDecorator();
};