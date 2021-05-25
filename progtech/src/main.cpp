#include <iostream>
#include <string>
#include <memory>
#include "controller/StorageController.h"

using namespace std;

int main()
{
    cout << "Progtech Beadando - Szoke Dominik\n\n";

    std::unique_ptr<StorageController> sc = std::make_unique<StorageController>();
    try
    {
        sc->handleUserInput();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    system("pause");
    return 0;
}