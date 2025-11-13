#include "GameManager.hpp"
#include "DisplayManager.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>

GameManager::GameManager(AirshipOrderList& airshipOrderList) : m_airshipOrderList(airshipOrderList)
{
    setCatalog();
};

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

void GameManager::runGuessingScene(const std::string& szScene)
{
    int iChoice;
    while(!bHasRemovedPackage)
    {
        clearScreen();
        std::cout << szScene << "\n";
        iChoice = promptGuessingScene();
        switch(iChoice)
        {
            case 1:
                std::cout << szCatalog << "\n";
                break;

            case 2:
                promptFindDelivery();
                break;

            case 3:
                promptModifyDelivery();
                break;

            case 4:
                m_airshipOrderList.displayDeliveries();
                break;

            case 5:
                promptRemoveDelivery();
                break;

            default:
                std::cout << szLineSpacing << "Please Enter Valid Input\n";
                break;
        };
        promptNextCustomerScene();
    };
};

int GameManager::promptGuessingScene()
{
    int iChoice;
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";
    std::cout << szLineSpacing << "1. View Catalog\n";
    std::cout << szLineSpacing << "2. Find Delivery\n";
    std::cout << szLineSpacing << "3. Modify Delivery\n";
    std::cout << szLineSpacing << "4. Display Deliveries\n";
    std::cout << szLineSpacing << "5. Delete Delivery\n\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";
    std::cout << szLineSpacing << "Enter Choice: ";
    std::cin >> iChoice;
    std::cout << "\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return iChoice;
};

void GameManager::promptNameAndItem()
{
    std::cout << szLineSpacing << "Please Enter Delivery Name: ";
    std::getline(std::cin >> std::ws, m_szName);
    std::cout << szLineSpacing << "Please Enter Item Name: ";
    std::getline(std::cin >> std::ws, m_szItem);
};

void GameManager::promptQuantityAndCost()
{
    std::cout << szLineSpacing << "Please Enter New Quantity: ";
    while (!(std::cin >> m_iQuantity) || m_iQuantity <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << szLineSpacing << "Invalid number. Enter a positive integer: ";
    }

    std::cout << szLineSpacing << "Please Enter New Cost: ";
    while (!(std::cin >> m_dCost) || m_dCost < 0.0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << szLineSpacing << "Invalid amount. Enter a valid cost: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

void GameManager::promptFindDelivery()
{
    promptNameAndItem();
    Delivery* delivery = m_airshipOrderList.findDelivery(m_szName, m_szItem);
    if(delivery == nullptr)
    {
        std::cout << szLineSpacing << "Delivery Not Found\n";
        return;
    };

    std::cout << "\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";
    std::cout << szLineSpacing << "               DELIVERY FOUND\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";
    m_airshipOrderList.displayDelivery(delivery);
    std::cout << "\n";
};

void GameManager::promptModifyDelivery()
{
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";
    std::cout << szLineSpacing << "               MODIFY DELIVERY\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";

    promptNameAndItem();
    promptQuantityAndCost();

    bool bIsModified = m_airshipOrderList.modifyDelivery(m_szName, m_szItem, m_iQuantity, m_dCost);
    if(!bIsModified)
    {
        std::cout << szLineSpacing << "Failed To Modify Delivery\n";
        return;
    };
    std::cout << szLineSpacing << "Delivery Successfully Modified\n\n";
};

void GameManager::promptRemoveDelivery()
{
    promptNameAndItem();
    Delivery* delivery = m_airshipOrderList.findDelivery(m_szName, m_szItem);
    if(delivery == nullptr)
    {
        std::cout << szLineSpacing << "Delivery Not Found\n";
        return;
    };

    std::cout << "\n";
    m_airshipOrderList.displayDelivery(delivery);
    std::cout << "\n";

    char cInput;
    std::cout << szLineSpacing << "Are You Sure This Is The Fraudulent Package? (y/n): ";
    std::cin >> cInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(cInput != 'y')
    {
        std::cout << szLineSpacing << "Aborting Package Removal\n";
        return;
    };

    bool bIsRemoved = m_airshipOrderList.removeDelivery(m_szName, m_szItem);
    if(bIsRemoved)
    {
        std::cout << szLineSpacing << "Package Successfully Removed\n\n";
        bHasRemovedPackage = true;
    }
    else
    {
        std::cout << szLineSpacing << "Issue Removing Package\n";
    }
};

void GameManager::promptCargoInput()
{
    std::string szCustomer;
    std::string szItem;
    int iQuantity = 0;
    double dCost = 0.0;

    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";
    std::cout << szLineSpacing << "         CARGO MANIFEST ENTRY TERMINAL\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";

    std::cout << szLineSpacing << "Captain, input the following details carefully.\n";
    std::cout << szLineSpacing << "One wrong digit and insurance will have your head.\n\n";

    std::cout << szLineSpacing << "Customer / Sender Name: ";
    std::getline(std::cin >> std::ws, szCustomer);

    std::cout << szLineSpacing << "Item Description: ";
    std::getline(std::cin >> std::ws, szItem);

    std::cout << szLineSpacing << "Quantity (units): ";
    while (!(std::cin >> iQuantity) || iQuantity <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << szLineSpacing << "Invalid number. Enter a positive integer: ";
    }

    std::cout << szLineSpacing << "Declared Value (credits): ";
    while (!(std::cin >> dCost) || dCost < 0.0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << szLineSpacing << "Invalid amount. Enter a valid cost: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n" << szLineSpacing << "──────────────────────────────────────────────\n\n";
    std::cout << szLineSpacing << "Recording shipment...\n";
    std::cout << szLineSpacing << "Sender:  " << szCustomer << "\n";
    std::cout << szLineSpacing << "Cargo:   " << szItem << "\n";
    std::cout << szLineSpacing << "Units:   " << iQuantity << "\n";
    std::cout << szLineSpacing << "Value:   " << std::fixed << std::setprecision(2)
              << dCost << " credits\n\n";
    m_airshipOrderList.addDelivery(szCustomer, szItem, iQuantity, dCost);
};

void GameManager::promptNextCustomerScene()
{
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";
    std::cout << szLineSpacing << "             PRESS ENTER TO CONINTUE\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";

    std::string iUserInput;
    std::getline(std::cin, iUserInput);
};

void GameManager::setCatalog()
{
    szCatalog = R"(
        ──────────────────────────────────────────────
                       CREW STATEMENTS LOG
        ──────────────────────────────────────────────

        [1] Lord Varric – House Altura
            "Between glass and trust, Captain, one 
            always breaks. Guess which I insure."
            ▸ The crate ticks. Subtle. Wrong.

        [2] Professor Elmwick
            "Do not drop it. Do not insult it. Do 
            not *concentrate* on it."
            ▸ The vapor pulses when he says 
            'concentrate.'

        [3] Mira Dross
            "Saboteurs love tidy labels and boring 
            numbers. When it looks perfect, squint 
            harder."
            ▸ She watches your reaction—too long.

        [4] Lyra Skyrunner
            "They sing when a manifest lies. One 
            of your nobles didn’t like his 
            description line."
            ▸ A faint harmonic hum brushes your 
              teeth, then fades.

        [5] The Mortician – Gray & Sons
            "We do not mislabel, Captain. 
             Others... project."
            ▸ Paperwork flawless. Too flawless.

        [6] Dr. Caldera
            "Some people undercharge for what’s 
            real. Some call that misdeclared. 
            I call it... leverage."
            ▸ The drums are too quiet. 
              No scent. No slosh.
)";
};

void GameManager::clearScreen() {
#ifdef _WIN32
    std::system("cls");   
#else
    std::cout << "\033[2J\033[1;1H";  
#endif
}
