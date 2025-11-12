#include "GameManager.hpp"
#include "DisplayManager.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

GameManager::GameManager(AirshipOrderList& airshipOrderList) : m_airshipOrderList(airshipOrderList){};

void GameManager::runStartingScene(const std::string& szScene)
{
    clearScreen();
    std::cout << szScene << "\n";
    promptNextCustomerScene();
};

void GameManager::runCustomerScene(const std::string& szScene)
{
    clearScreen();
    std::cout << szScene << "\n";
    promptCargoInput();
    promptNextCustomerScene();
};

void GameManager::promptCargoInput()
{
    std::string szCustomer;
    std::string szItem;
    int iQuantity = 0;
    double dCost = 0.0;

    std::cout << "      ──────────────────────────────────────────────\n";
    std::cout << "                CARGO MANIFEST ENTRY TERMINAL\n";
    std::cout << "      ──────────────────────────────────────────────\n\n";

    std::cout << "  Captain, input the following details carefully.\n";
    std::cout << "  One wrong digit and insurance will have your head.\n\n";

    std::cout << "  Customer / Sender Name: ";
    std::getline(std::cin >> std::ws, szCustomer);

    std::cout << "  Item Description: ";
    std::getline(std::cin >> std::ws, szItem);

    std::cout << "  Quantity (units): ";
    while (!(std::cin >> iQuantity) || iQuantity <= 0) {
        std::cin.clear();
        std::cout << "  Invalid number. Enter a positive integer: ";
    }

    std::cout << "  Declared Value (credits): ";
    while (!(std::cin >> dCost) || dCost < 0.0) {
        std::cin.clear();
        std::cout << "  Invalid amount. Enter a valid cost: ";
    }

    std::cout << "\n      ──────────────────────────────────────────────\n";
    std::cout << "  Recording shipment...\n";
    std::cout << "      Sender:  " << szCustomer << "\n";
    std::cout << "      Cargo:   " << szItem << "\n";
    std::cout << "      Units:   " << iQuantity << "\n";
    std::cout << "      Value:   " << std::fixed << std::setprecision(2)
              << dCost << " credits\n";
    std::cout << "      ──────────────────────────────────────────────\n\n";

    m_airshipOrderList.addDelivery(szCustomer, szItem, iQuantity, dCost);
};

void GameManager::promptNextCustomerScene()
{
    std::cout << "        ──────────────────────────────────────────────\n";
    std::cout << "                    PRESS ENTER TO CONINTUE\n";
    std::cout << "        ──────────────────────────────────────────────\n";

    std::string iUserInput;
    std::getline(std::cin, iUserInput);
};

void GameManager::clearScreen() {
#ifdef _WIN32
    std::system("cls");   
#else
    std::cout << "\033[2J\033[1;1H";  
#endif
}
