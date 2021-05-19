#pragma once

#include <iostream>
#include "../model/Book.h"

class ISub
{
private:
public:
    virtual void fillStorageByType(const char *bookType, const char *altType) = 0;
    virtual void removeBookFromStorage(const Book &book) = 0;
    virtual void notifyObserver(const Book &book, float price) = 0;
    ISub() {}
    ~ISub() {}
};
