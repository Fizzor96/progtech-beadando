#pragma once

#include <iostream>
#include <string>
#include "../interfaces/ISub.h"
#include "../model/Storage.h"

class StorageController : public ISub
{
private:
    static Storage storage;
    bool isRunning;

public:
    void fillStorageByType(const char *bookType, const char *altType)
    {
        //implementation
    }
    void removeBookFromStorage(const Book &book)
    {
        //implementation
    }
    void notifyObserver(const Book &book, float price)
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
    }
    StorageController()
    {
        isRunning = true;
    }
    ~StorageController() {}
};
