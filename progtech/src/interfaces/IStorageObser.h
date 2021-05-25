#pragma once

#include <iostream>

#include "../model/Book.h"

class IStorageObser
{
private:
    /* data */
public:
    virtual void update(const float &price) = 0;
    IStorageObser() {}
    ~IStorageObser() {}
    IStorageObser(const IStorageObser &other) = delete;
    IStorageObser &operator=(const IStorageObser &other) = delete;
};
