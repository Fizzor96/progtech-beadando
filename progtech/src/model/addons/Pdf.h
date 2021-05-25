#include <iostream>
#include "../AddonDecorator.h"
#include "../Book.h"

using namespace std;

class Pdf : public AddonDecorator
{
public:
    float getCost() const override
    {
        return this->cost;
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

    Book getBook()
    {
        return this->book;
    }

    Pdf() {}

    Pdf(const Book &b)
    {
        this->book = b;
        this->cost = b.getCost() + 0.88;
        this->description = b.getDescription() + " (Pdf)";
    }

    ~Pdf() {}
};
