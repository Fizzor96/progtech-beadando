#pragma once

#include <iostream>
#include <vector>
#include "Book.h"
#include "books/Biography.h"
#include "books/Gastronomy.h"
#include "books/History.h"
#include "books/Technology.h"

class Storage
{
private:
    static Storage *firstInstance;
    static unsigned int max_quantity;
    std::vector<Book> bookStorage;
    Storage() {}

public:
    static Storage *getStorageInstance();

    static void deleteStorageInstance();

    ~Storage()
    {
        //delete heap allocated objs (otherwise memoryleak)
        delete firstInstance;
    }

    void add(const Book &book)
    {
        if (validateQuantity(book))
        {
            bookStorage.push_back(book);
        }
        else
        {
            throw "Storage is full!";
        }
    }

    void removeBookByType(Book book)
    {
        for (size_t i = 0; i < bookStorage.size(); i++)
        {
            if (bookStorage[i].getBookType() == book.getBookType())
            {
                bookStorage.erase(bookStorage.begin() + i);
            }
            else
            {
                throw "We ran out of this type of book.";
            }
        }
    }

    Book *getBookByType(std::string bookType)
    {
        try
        {
            for (size_t i = 0; i < bookStorage.size(); i++)
            {
                if (bookStorage[i].getBookType() == bookType)
                {
                    return &bookStorage[i];
                }
            }
        }
        catch (const std::exception &e)
        {
            throw "No book of this type present!";
        }
        return nullptr;
    }

    //validation based on "types" are impossible, cuz types are not exist in the memory!!
    bool validateQuantity(Book book)
    {
        if (!bookStorage.empty())
        {
            unsigned int counter = 0;
            for (auto b : bookStorage)
            {
                if (b.getBookType() == book.getBookType())
                {
                    counter++;
                    if (counter >= max_quantity)
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            throw "Invalid parameter value in Storage.validateQuantity";
        }
        return true;
    }

    std::vector<Book> getFilteredBooksByType(Book book)
    {
        std::vector<Book> filtered;
        try
        {
            if (!bookStorage.empty())
            {
                for (auto b : bookStorage)
                {
                    if (b.getBookType() == book.getBookType())
                    {
                        filtered.push_back(b);
                    }
                }
                if (filtered.size() != 0)
                {
                    return filtered;
                }
                else
                {
                    throw "There is no book with the given arguments!";
                }
            }
        }
        catch (const char *e)
        {
            throw e;
        }
    }

    std::string getQuantityAllByType()
    {
    }

    void fillStorageByType(Book book)
    {
        while (validateQuantity(book))
        {
            if (book.getBookType() == "biography")
            {
                bookStorage.push_back(Biography());
            }
            else if (book.getBookType() == "gastronomy")
            {
                bookStorage.push_back(Gastronomy());
            }
            else if (book.getBookType() == "history")
            {
                bookStorage.push_back(History());
            }
            else if (book.getBookType() == "technology")
            {
                bookStorage.push_back(Technology());
            }
        }
    }
};

//static things

Storage *Storage::firstInstance = nullptr;

unsigned int Storage::max_quantity = 500;

Storage *Storage::getStorageInstance()
{
    if (firstInstance == nullptr)
    {
        firstInstance = new Storage();
    }
    return firstInstance;
}

void Storage::deleteStorageInstance()
{
    firstInstance = nullptr;
}