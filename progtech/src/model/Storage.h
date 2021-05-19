#pragma once

#include <iostream>
#include <vector>
#include "Book.h"

// instanceof implementation
template <typename Base, typename T>
inline bool instanceof (const T *)
{
    return is_base_of<Base, T>::value;
}

class Storage
{
private:
    static Storage *firstInstance;
    static unsigned int max_quantity;
    std::vector<Book> bookStorage;
    Storage() {}

public:
    Storage *getStorageInstance()
    {
        if (firstInstance == nullptr)
        {
            firstInstance = new Storage();
        }
        return firstInstance;
    }

    ~Storage()
    {
        //delete heap allocated objs (otherwise memoryleak)
        delete firstInstance;
    }

    void add(const Book &book)
    {
    }

    //validation based on "types" are impossible, cuz types are not exist in the memory!!
    bool validateQuantity(const Book &book)
    {
        if (!bookStorage.empty())
        {
            /* code */
        }
    }
};

Storage *Storage::firstInstance = nullptr;
unsigned int Storage::max_quantity = 500;