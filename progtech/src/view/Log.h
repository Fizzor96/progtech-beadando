#pragma once

#include <iostream>
#include <string>

using namespace std;

class Log
{
public:
    static void promptOutput(std::string output);

    static std::string getUserInput(std::string task);

    Log() {}
    ~Log() {}
    Log(const Log &other) = delete;
    Log &operator=(const Log &other) = delete;
};

void Log::promptOutput(std::string output)
{
    cout << output << endl;
}

std::string Log::getUserInput(std::string task)
{
    cout << task << endl;
    std::string temp = "";
    std::cin >> temp;
    return temp;
}