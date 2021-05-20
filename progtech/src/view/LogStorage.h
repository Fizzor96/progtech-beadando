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

public:
    LogStorage()
    {
    }
    ~LogStorage() {}
};