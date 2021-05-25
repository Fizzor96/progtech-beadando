#pragma once

#include <iostream>
#include <string>
#include "../interfaces/ISub.h"
#include "../model/Storage.h"

using namespace std;

class StorageController : public ISub
{
private:
    static Storage storage;
    bool isRunning;

public:
    void fillStorageByType(const std::string &bookType, const std::string &altType)
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
    StorageController()
    {
        isRunning = true;
    }
    ~StorageController() {}
};
