#pragma once

#include <iostream>
#include "../model/Book.h"

class ISub
{
public:
    virtual void fillStorageByType(std::string bookType, std::string ext) = 0;
    virtual void removeBookFromStorage(Book book) = 0;
    virtual void notifyObserver(Book book, float price) = 0;
    ISub() {}
    ~ISub() {}
    ISub(const ISub &other) = delete;
    ISub(ISub &&other) = delete;
    ISub &operator=(const ISub &other) = delete;
};