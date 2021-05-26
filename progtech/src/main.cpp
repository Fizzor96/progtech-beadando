#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "controller/StorageController.h"

using namespace std;

int main()
{
    cout << "\nProgtech Beadando - Szoke Dominik\n";

    std::unique_ptr<StorageController> sc = std::make_unique<StorageController>();

    sc->seedStorage();

    try
    {
        sc->handleUserInput();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}