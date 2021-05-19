#pragma once

#include <iostream>
#include "../interfaces/ISub.h"
#include "../model/Storage.h"

class StorageController : public ISub
{
private:
    static Storage storage;

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
    StorageController() {}
    ~StorageController() {}
};
