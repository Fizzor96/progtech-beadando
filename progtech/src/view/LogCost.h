#pragma once

#include <iostream>
#include <string>
#include "Log.h"

using namespace std;

class LogCost : public Log
{
private:
    std::string costChangeOption = "Enter new price. (format: 69.69)\n";

public:
    std::string getCostChangeOpstion()
    {
        return this->costChangeOption;
    }
    LogCost() {}
    ~LogCost() {}
};
