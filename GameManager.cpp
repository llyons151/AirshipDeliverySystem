#include "GameManager.hpp"
#include "DisplayManager.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

GameManager::GameManager(const AirshipOrderList& airshipOrderList) : m_airshipOrderList(airshipOrderList){};

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
    std::cout << "promptCargoInput is running\n";
};

void GameManager::promptNextCustomerScene()
{
    std::cout << "      ──────────────────────────────────────────────\n";
    std::cout << "                    ENTER 1 TO CONTINUE \n";
    std::cout << "                     ENTER -1 TO EXIT \n";
    std::cout << "      ──────────────────────────────────────────────\n";

    int iUserInput;
    std::cin >> iUserInput;

    if (iUserInput == -1)
    {
        std::cout << "Goodbye, Captain.\n";
        exit(0); 
    };
};

void GameManager::clearScreen() {
#ifdef _WIN32
    std::system("cls");   
#else
    std::cout << "\033[2J\033[1;1H";  
#endif
}
