#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "../interfaces/ISub.h"
#include "../model/Storage.h"
#include "../factory/BookFactory.h"
#include "../model/Book.h"
#include "../view/Log.h"
#include "../view/LogCost.h"
#include "../view/LogStorage.h"

using namespace std;

class StorageController : public ISub
{
private:
    bool isRunning;
    static Storage *storage;
    LogStorage logStorage;
    LogCost logCost;

public:
    StorageController()
    {
        isRunning = true;
    }

    ~StorageController() {}

    void seedStorage()
    {
        // cout << "SC seed storage func" << endl;
        fillStorageByType(std::string("biography"), std::string("physical"));
        fillStorageByType(std::string("gastronomy"), std::string("physical"));
        fillStorageByType(std::string("history"), std::string("physical"));
        fillStorageByType(std::string("technology"), std::string("physical"));
        std::cout << "Storage size after seed = " << storage->getBookStorageSize() << endl;
    }
    void fillStorageByType(std::string bookType, std::string ext)
    {
        storage->fillStorageByType(new Book(bookType, ext));
    }
    void addBookToStorage(std::string bookType, std::string ext)
    {
        try
        {
            storage->add(makeBook(bookType, ext));
        }
        catch (const char *e)
        {
            throw e;
        }
    }

    void removeBookFromStorage(Book book)
    {
        storage->removeBookByType(book);
    }

    void notifyObserver(Book book, float price)
    {
        try
        {
            for (Book *b : storage->getFilteredBooksByType(book))
            {
                b->update(price);
            }
        }
        catch (const char *e)
        {
            throw "Price of " + book.getBookType() + " is set to " + std::to_string(price);
        }
    }

    Book *makeBook(std::string bookType, std::string ext)
    {
        try
        {
            if (bookType == "biography")
            {
                return BookFactory::makeBook(std::string("biography"), ext);
            }
            else if (bookType == "gastronomy")
            {
                return BookFactory::makeBook(std::string("gastronomy"), ext);
            }
            else if (bookType == "history")
            {
                return BookFactory::makeBook(std::string("history"), ext);
            }
            else if (bookType == "technology")
            {
                return BookFactory::makeBook(std::string("technology"), ext);
            }
            else
            {
                throw "Invalid BookType given!";
            }
        }
        catch (const char *e)
        {
            throw e;
        }
    }
    std::string chooseBookType()
    {
        std::string bookType = Log::getUserInput(logStorage.getBookOptions());
        if (bookType == "1")
        {
            return std::string("biography");
        }
        else if (bookType == "2")
        {
            return std::string("gastronomy");
        }
        else if (bookType == "3")
        {
            return std::string("history");
        }
        else if (bookType == "4")
        {
            return std::string("technology");
        }
        else
        {
            throw "Invalid input was given!";
        }
    }
    std::string chooseExtension()
    {
        std::string isExtOpt = Log::getUserInput(logStorage.getIsExtensionOptions());
        std::string bookType;
        if (isExtOpt == "y")
        {
            bookType = Log::getUserInput(logStorage.getExtensionOptions());
            if (bookType == "1")
            {
                return std::string("txt");
            }
            else if (bookType == "2")
            {
                return std::string("epub");
            }
            else if (bookType == "3")
            {
                return std::string("pdf");
            }
            else
            {
                throw "Invalid input was given!";
            }
        }
        else if (isExtOpt == "n")
        {
            return std::string("physical");
        }
        else
        {
            throw "Invalid input was given!";
        }
    }
    void orderBook(std::string bookType)
    {
        Book b = *storage->getBookByType(bookType);
        std::string response = "Coffee was ordered for: " + std::to_string(b.getCost());
        removeBookFromStorage(b);
        Log::promptOutput(response);
    }
    void setPrice(std::string bookType, float price)
    {
        notifyObserver(*storage->getBookByType(bookType), price);
    }
    void handleUserInput()
    {
        string o = Log::getUserInput(logStorage.getStorageOptions());
        string bookType;
        string extension;
        while (isRunning)
        {
            try
            {
                if (o != "")
                {
                    if (o == "1")
                    {
                        bookType = chooseBookType();
                        extension = chooseExtension();
                        orderBook(bookType);
                    }
                    else if (o == "2")
                    {
                        bookType = chooseBookType();
                        extension = chooseExtension();
                        fillStorageByType(bookType, extension);
                    }
                    else if (o == "3")
                    {
                        Log::promptOutput(storage->getQuantityAllByType());
                    }
                    else if (o == "4")
                    {
                        bookType = chooseBookType();
                        extension = chooseExtension();
                        float price = std::stof(Log::getUserInput(logCost.getCostChangeOpstion()));
                        setPrice(bookType, price);
                    }
                    else if (o == "q")
                    {
                        isRunning = false;
                    }
                    else
                    {
                        throw "Invalid input!";
                    }
                }
            }
            catch (const char *e)
            {
                throw e;
            }
        }
    }
};

Storage *StorageController::storage = Storage::getStorageInstance();