#pragma once

#include <iostream>
#include <string>

using namespace std;

class Log
{
public:
    void promptOutput(const std::string &output)
    {
        cout << output << endl;
    }
    std::string getUserInput(const std::string &task)
    {
        cout << task << endl;
        return task;
    }
    Log() {}
    ~Log() {}
};
