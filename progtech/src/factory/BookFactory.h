#pragma once

#include <iostream>
#include <locale>
#include "../model/Book.h"
#include "../model/books/Biography.h"
#include "../model/books/History.h"
#include "../model/books/Technology.h"
#include "../model/books/Gastronomy.h"
#include "../model/addons/Epub.h"
#include "../model/addons/Pdf.h"
#include "../model/addons/Physical.h"
#include "../model/addons/Txt.h"

using namespace std;

class BookFactory
{
public:
    static Book makeBook(std::string &bookType, std::string &ext);
    static Book addExt(const Book &b, std::string &ext);
    BookFactory(/* args */);
    ~BookFactory();
};

Book BookFactory::addExt(const Book &b, std::string &ext)
{
    for (auto &c : ext)
    {
        c = tolower(c);
    }

    if (ext == "epub")
    {
        return Epub(b);
    }
    else if (ext == "pdf")
    {
        return Pdf(b);
    }
    else if (ext == "physical")
    {
        return Physical(b);
    }
    else if (ext == "txt")
    {
        return Txt(b);
    }
    else
    {
        throw "Invalid parameter value in CoffeeFactory.addFlavour()";
    }
}

Book BookFactory::makeBook(std::string &bookType, std::string &ext)
{
    for (auto &c : bookType)
    {
        c = tolower(c);
    }

    if (bookType == "biography")
    {
        if (ext != "")
        {
            return addExt(Biography(), ext);
        }
        return Biography();
    }
    else if (bookType == "gastronomy")
    {
        if (ext != "")
        {
            return addExt(Gastronomy(), ext);
        }
        return Gastronomy();
    }
    else if (bookType == "history")
    {
        if (ext != "")
        {
            return addExt(History(), ext);
        }
        return History();
    }
    else if (bookType == "technology")
    {
        if (ext != "")
        {
            return addExt(Technology(), ext);
        }
    }
    else
    {
        throw "Invalid parameter value in BookFactory.makeBook()";
    }
}