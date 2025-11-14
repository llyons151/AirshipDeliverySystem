/*********************************************************************
File name: GameManager.cpp
Author: <Luke Lyons>(<ujw18>)
Date: 11/14/2025

Purpose:
    Implementation file for the GameManager class. Manages game flow,
    user interactions, and coordinates game logic for the Airship
    Delivery System.
Command Parameters:
    N/A
Input:
    User input for game choices and delivery information.
Results:
    Manages complete game flow from start to end.
Notes:
    Contains all game logic, input validation, and scene management.
*********************************************************************/

#include "GameManager.hpp"
#include "DisplayManager.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>

/*********************************************************************
GameManager::GameManager(AirshipOrderList& airshipOrderList)
Purpose:
    Constructor that initializes the game manager with delivery list.
Parameters:
    I/O AirshipOrderList& airshipOrderList - Reference to delivery list
Return Value:
    None (constructor)
Notes:
    Initializes the catalog by calling setCatalog().
*********************************************************************/
GameManager::GameManager(AirshipOrderList& airshipOrderList) : m_airshipOrderList(airshipOrderList)
{
    setCatalog();
}

/*********************************************************************
void GameManager::runStartingScene(const std::string& szScene)
Purpose:
    Displays the starting scene and waits for user to continue.
Parameters:
    I const std::string& szScene - Starting scene text to display
Return Value:
    None
Notes:
    Clears screen before displaying scene.
*********************************************************************/
void GameManager::runStartingScene(const std::string& szScene)
{
    clearScreen();
    std::cout << szScene << "\n";
    promptNextCustomerScene();
}

/*********************************************************************
void GameManager::runCustomerScene(const std::string& szScene)
Purpose:
    Displays a customer scene, prompts for cargo input, and continues.
Parameters:
    I const std::string& szScene - Customer scene text to display
Return Value:
    None
Notes:
    Clears screen, displays scene, prompts for delivery entry.
*********************************************************************/
void GameManager::runCustomerScene(const std::string& szScene)
{
    clearScreen();
    std::cout << szScene << "\n";
    promptCargoInput();
    promptNextCustomerScene();
}

/*********************************************************************
void GameManager::runEndingScene(const std::string& szScene)
Purpose:
    Displays the ending scene (victory or defeat).
Parameters:
    I const std::string& szScene - Ending scene text to display
Return Value:
    None
Notes:
    Clears screen before displaying the final scene.
*********************************************************************/
void GameManager::runEndingScene(const std::string& szScene)
{
    clearScreen();
    std::cout << szScene << "\n";
}

/*********************************************************************
void GameManager::runGuessingScene(const std::string& szScene)
Purpose:
    Manages the guessing phase where player identifies fraudulent package.
Parameters:
    I const std::string& szScene - Guessing scene text to display
Return Value:
    None
Notes:
    Loops until player removes a package, provides menu for various actions.
*********************************************************************/
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
        }
        promptNextCustomerScene();
    }
}

/*********************************************************************
int GameManager::promptGuessingScene()
Purpose:
    Displays the guessing scene menu and gets user choice.
Parameters:
    None
Return Value:
    int - User's menu choice
Notes:
    Presents 5 options: view catalog, find, modify, display, delete.
*********************************************************************/
int GameManager::promptGuessingScene()
{
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";
    std::cout << szLineSpacing << "1. View Catalog\n";
    std::cout << szLineSpacing << "2. Find Delivery\n";
    std::cout << szLineSpacing << "3. Modify Delivery\n";
    std::cout << szLineSpacing << "4. Display Deliveries\n";
    std::cout << szLineSpacing << "5. Delete Delivery\n\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";
    std::cout << szLineSpacing << "Enter Choice: ";
    int iChoice = getChoice();
    return iChoice;
}

/*********************************************************************
int GameManager::getChoice()
Purpose:
    Gets and validates integer input from user.
Parameters:
    None
Return Value:
    int - Valid integer choice from user
Notes:
    Loops until valid integer is entered, clears invalid input.
*********************************************************************/
int GameManager::getChoice()
{
    int iChoice;

    while (true)
    {
        std::cout << "Enter choice: ";
        if (std::cin >> iChoice)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return iChoice;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\nInvalid input. Please enter a number.\n\n";
    }
}

/*********************************************************************
void GameManager::promptNameAndItem()
Purpose:
    Prompts user for customer name and item name.
Parameters:
    None
Return Value:
    None
Notes:
    Stores input in member variables m_szName and m_szItem.
*********************************************************************/
void GameManager::promptNameAndItem()
{
    std::cout << szLineSpacing << "Please Enter Delivery Name: ";
    std::getline(std::cin >> std::ws, m_szName);
    std::cout << szLineSpacing << "Please Enter Item Name: ";
    std::getline(std::cin >> std::ws, m_szItem);
}

/*********************************************************************
void GameManager::promptQuantityAndCost()
Purpose:
    Prompts user for quantity and cost with input validation.
Parameters:
    None
Return Value:
    None
Notes:
    Validates positive quantity and non-negative cost, stores in members.
*********************************************************************/
void GameManager::promptQuantityAndCost()
{
    std::cout << szLineSpacing << "Please Enter New Quantity: ";
    while (!(std::cin >> m_iQuantity) || m_iQuantity <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << szLineSpacing << "Invalid number. Enter a positive integer: ";
    }

    std::cout << szLineSpacing << "Please Enter New Cost: ";
    while (!(std::cin >> m_dCost) || m_dCost < 0.0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << szLineSpacing << "Invalid amount. Enter a valid cost: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*********************************************************************
void GameManager::promptFindDelivery()
Purpose:
    Prompts for delivery info and displays if found.
Parameters:
    None
Return Value:
    None
Notes:
    Searches for delivery by name and item, displays result.
*********************************************************************/
void GameManager::promptFindDelivery()
{
    promptNameAndItem();
    Delivery* delivery = m_airshipOrderList.findDelivery(m_szName, m_szItem);
    if(delivery == nullptr)
    {
        std::cout << szLineSpacing << "Delivery Not Found\n";
        return;
    }

    std::cout << "\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";
    std::cout << szLineSpacing << "               DELIVERY FOUND\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";
    m_airshipOrderList.displayDelivery(delivery);
    std::cout << "\n";
}

/*********************************************************************
void GameManager::promptModifyDelivery()
Purpose:
    Prompts for delivery info and modifies quantity and cost.
Parameters:
    None
Return Value:
    None
Notes:
    Finds delivery and updates quantity and cost if found.
*********************************************************************/
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
    }
    std::cout << szLineSpacing << "Delivery Successfully Modified\n\n";
}

/*********************************************************************
void GameManager::promptRemoveDelivery()
Purpose:
    Prompts for delivery to remove and confirms with user.
Parameters:
    None
Return Value:
    None
Notes:
    Validates delivery exists, confirms removal, checks if correct package.
*********************************************************************/
void GameManager::promptRemoveDelivery()
{
    promptNameAndItem();
    Delivery* delivery = m_airshipOrderList.findDelivery(m_szName, m_szItem);
    if(delivery == nullptr)
    {
        std::cout << szLineSpacing << "Delivery Not Found\n";
        return;
    }

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
    }

    bool bIsRemoved = m_airshipOrderList.removeDelivery(m_szName, m_szItem);
    if(!bIsRemoved)
    {
        std::cout << szLineSpacing << "Issue Removing Package\n";
        return;
    }

    std::cout << szLineSpacing << "Package Successfully Removed\n\n";
    bHasRemovedPackage = true;
    (m_szName == m_fraudulentPackageName) ? bIsGuessCorrect = true : bIsGuessCorrect = false;
}

/*********************************************************************
void GameManager::promptCargoInput()
Purpose:
    Prompts user to enter a new delivery into the system.
Parameters:
    None
Return Value:
    None
Notes:
    Validates input and adds delivery to the order list.
*********************************************************************/
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
    while (!(std::cin >> iQuantity) || iQuantity <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << szLineSpacing << "Invalid number. Enter a positive integer: ";
    }

    std::cout << szLineSpacing << "Declared Value (credits): ";
    while (!(std::cin >> dCost) || dCost < 0.0)
    {
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
}

/*********************************************************************
void GameManager::promptNextCustomerScene()
Purpose:
    Prompts user to press enter to continue to next scene.
Parameters:
    None
Return Value:
    None
Notes:
    Pauses execution until user presses enter.
*********************************************************************/
void GameManager::promptNextCustomerScene()
{
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";
    std::cout << szLineSpacing << "             PRESS ENTER TO CONINTUE\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";

    std::string iUserInput;
    std::getline(std::cin, iUserInput);
}

/*********************************************************************
void GameManager::setCatalog()
Purpose:
    Initializes the catalog string with crew statements and clues.
Parameters:
    None
Return Value:
    None
Notes:
    Contains all customer information, price notes, and riddles.
*********************************************************************/
void GameManager::setCatalog()
{
    szCatalog = R"(
──────────────────────────────────────────────
               CREW STATEMENTS LOG
──────────────────────────────────────────────


[1] Bulk Ryker
    Price Note:
      Protein Infusion Canisters priced at 200 — you’ve seen
      similar canisters and they never come that cheap.

    Accusation:
      Points at Linton: “Bro jitters like he drank twelve
      energy drinks… I wouldn’t trust him alone with my gym bag.”

    Riddle:
      "25 * 5 is 100"


[2] Buck Hawthorne
    Price Note:
      Classic Ale Keg priced at 90 — number sounds right.

    Accusation:
      Comments on Vesper: smells like excuses, reminds him of
      his disappointing son, but deep down solid.

    Riddle:
      “What has numbers but no weight,
       letters but no sound?”


[3] Old Man Ripple
    Price Note:
      Net-Stabilizer Kit priced at 120 — you’ve seen them
      closer to 180; his price feels light.

    Accusation:
      Says Bulk’s numbers feel lighter than his temper.

    Riddle:
      “When two shadows stand, only one is true.
       The liar’s breath chills the page they touch.”


[4] Bramble Nett
    Price Note:
      Cultivation Spore Beds priced at 150 — standard rate.

    Accusation:
      Says Buck’s crate smells honest; says Ripple is someone
      he’d trust with a secret.

    Riddle:
      “The quietest growth makes the loudest bloom
       when no one’s watching.”


[5] Vesper Morrow
    Price Note:
      EM Field Sensor priced at 110 — you know they run more
      than twice that.

    Accusation:
      Says Buck acts harmless but is always listening, knows
      more than he should.

    Riddle:
      (None)


[6] Linton Yarrow
    Price Note:
      Soft-Code Debugging Array priced at 320 — you’ve seen
      arrays like it listed near 900.

    Accusation:
      Says Bramble talks like a meditation app with a glitch,
      suspects he’s hiding a subroutine.

    Riddle:
      “A tool that finds mistakes
       cannot afford one of its own.”
)";
}

/*********************************************************************
void GameManager::clearScreen()
Purpose:
    Clears the terminal screen for better display formatting.
Parameters:
    None
Return Value:
    None
Notes:
    Uses platform-specific commands (cls for Windows, escape codes for Unix).
*********************************************************************/
void GameManager::clearScreen()
{
#ifdef _win32
    std::system("cls");
#else
    std::cout << "\033[2j\033[3j\033[h" << std::flush;
#endif
}
