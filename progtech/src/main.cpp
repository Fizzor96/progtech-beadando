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

    // std::vector<int> asd;
    // std::cout << asd.size() << endl;

    sc->seedStorage();

    // std::cout << std::to_string(Storage::getStorageInstance()->getBookStorage().size()) << std::endl;

    try
    {
        sc->handleUserInput();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    // system("pause");
    return 0;
}