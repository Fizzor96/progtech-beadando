#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogCost
{
private:
    std::string costChaneOption = "Enter new price. (format: 69.69)\n";

public:
    std::string getCostChangeOpstion()
    {
        return this->costChaneOption;
    }
    LogCost() {}
    ~LogCost() {}
};
