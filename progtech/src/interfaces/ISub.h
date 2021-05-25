#pragma once

#include <iostream>
#include "../model/Book.h"

class ISub
{
public:
    virtual void fillStorageByType(const char *bookType, const char *altType) = 0;
    virtual void removeBookFromStorage(const Book &book) = 0;
    virtual void notifyObserver(const Book &book, float price) = 0;
    ISub() {}
    ~ISub() {}
    ISub(const ISub &other) = delete;
    ISub &operator=(const ISub &other) = delete;
};