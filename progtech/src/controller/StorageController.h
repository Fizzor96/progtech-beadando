#pragma once

#include <iostream>
#include <string>
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
        fillStorageByType(std::string("biography"), std::string(""));
        fillStorageByType(std::string("biography"), std::string(""));
        fillStorageByType(std::string("biography"), std::string(""));
        fillStorageByType(std::string("biography"), std::string(""));
    }
    void fillStorageByType(const std::string &bookType, const std::string &altType)
    {
        //implementation
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
        //implementation
    }
    Book makeBook(std::string bookType, std::string ext)
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
        //implementation
    }
    std::string chooseAltType()
    {
        //implementation
    }
    void orderBook()
    {
        //implementation
    }
    void setPrice()
    {
        //implementation
    }
    void handleUserInput()
    {
        string o;
        string bookType;
        string altType;
        while (isRunning)
        {
            try
            {
                cin >> o;
                if (o != "")
                {
                    if (o == "1")
                    {
                        /* code */
                    }
                    else if (o == "2")
                    {
                        /* code */
                    }
                    else if (o == "3")
                    {
                        /* code */
                    }
                    else if (o == "4")
                    {
                        /* code */
                    }
                    else if (o == "q")
                    {
                        isRunning = false;
                    }
                    // Default
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