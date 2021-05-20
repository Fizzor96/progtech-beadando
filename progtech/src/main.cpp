#include <iostream>
#include <string>
#include <memory>
#include "controller/StorageController.h"

using namespace std;

int main()
{
    std::unique_ptr<StorageController> sc = std::make_unique<StorageController>();
    try
    {
        sc->handleUserInput();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Progtech Beadando - Szoke Dominik\n";
    system("pause");
    return 0;
}