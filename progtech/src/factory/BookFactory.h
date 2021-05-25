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
    static Book *makeBook(std::string bookType, std::string ext);
    static Book *addExt(Book *b, std::string ext);
    BookFactory(/* args */);
    ~BookFactory();
};

Book *BookFactory::addExt(Book *b, std::string ext)
{
    for (auto &c : ext)
    {
        c = tolower(c);
    }

    if (ext == "epub")
    {
        return new Epub(*b);
    }
    else if (ext == "pdf")
    {
        return new Pdf(*b);
    }
    else if (ext == "physical")
    {
        return new Physical(*b);
    }
    else if (ext == "txt")
    {
        return new Txt(*b);
    }
    else
    {
        throw "Invalid parameter value in BookFactory.addExtension()";
    }
}

Book *BookFactory::makeBook(std::string bookType, std::string ext)
{
    // for (auto &c : bookType)
    // {
    //     c = tolower(c);
    // }

    if (bookType == "biography")
    {
        if (ext != "")
        {
            // return addExt(new Book("biography", ext), ext);
            return new Book(bookType, ext);
        }
        // return new Biography();
        return new Book(bookType);
    }
    else if (bookType == "gastronomy")
    {
        if (ext != "")
        {
            // return addExt(new Gastronomy(), ext);
            return new Book(bookType, ext);
        }
        // return new Gastronomy();
        return new Book(bookType);
    }
    else if (bookType == "history")
    {
        if (ext != "")
        {
            // return addExt(new History(), ext);
            return new Book(bookType, ext);
        }
        // return new History();
        return new Book(bookType);
    }
    else if (bookType == "technology")
    {
        if (ext != "")
        {
            // return addExt(new Technology(), ext);
            return new Book(bookType, ext);
        }
        // return new Technology();
        return new Book(bookType);
    }
    else
    {
        throw "Invalid parameter value in BookFactory.makeBook()";
    }
}