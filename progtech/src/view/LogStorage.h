#pragma once

#include <iostream>
#include <string>
#include "Log.h"

using namespace std;

class LogStorage : public Log
{
private:
    std::string storageOptions = "*************** Book Storage App ***************\n1. Order\n2.Fill Storage\n3.Show Storage\n4.Manage price\nq.Quit ";
    std::string bookOptions = "Enter the number of the book.\n1. Biography\n2. Gastronomy\n3. History\n4. Technology\n";
    std::string isEbookOptions = "Do you want online copy? (y/n)";
    std::string ebookOptions = "Enter the number of the format.\n1. TXT\n2. EPUB\n3. PDF\n";

public:
    std::string getStorageOptions()
    {
        return this->storageOptions;
    }

    std::string getBookOptions()
    {
        return this->bookOptions;
    }

    std::string getIsEbookOptions()
    {
        return this->isEbookOptions;
    }

    std::string getEbookOptions()
    {
        return this->ebookOptions;
    }

    LogStorage() {}
    ~LogStorage() {}
};