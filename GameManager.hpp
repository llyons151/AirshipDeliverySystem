/*********************************************************************
File name: GameManager.hpp
Author: <Luke Lyons>(<ujw18>)
Date: 11/14/2025

Purpose:
    Header file for the GameManager class which controls game flow
    and user interactions for the Airship Delivery System.
Command Parameters:
    N/A
Input:
    N/A
Results:
    Class definition for GameManager.
Notes:
    Manages game state, user input, and scene transitions.
*********************************************************************/

#pragma once
#include "DisplayManager.hpp"
#include "AirshipOrderList.hpp"
#include <string>

/*********************************************************************
Class Name: GameManager
Purpose:
    Controls game flow, manages user interactions, and coordinates
    between display and delivery management systems.
Notes:
    Handles all game logic, input validation, and scene transitions.
    Maintains reference to AirshipOrderList for delivery operations.
*********************************************************************/
class GameManager
{
    private:
        const char* szLineSpacing = "";                            // Line spacing for formatted output
        std::string szCatalog;                                     // Catalog of crew statements and clues
        AirshipOrderList& m_airshipOrderList;                     // Reference to delivery list
        std::string m_fraudulentPackageName = "Linton Yarrow";    // Name of fraudulent package customer
        std::string m_szName;                                      // Temporary storage for customer name
        std::string m_szItem;                                      // Temporary storage for item name
        int m_iQuantity;                                           // Temporary storage for quantity
        double m_dCost;                                            // Temporary storage for cost
        bool bHasRemovedPackage = false;                           // Flag indicating if package removed
        bool bIsGuessCorrect = false;                              // Flag indicating if correct package removed

    private:
        int promptGuessingScene();
        int getChoice();
        void promptNameAndItem();
        void promptQuantityAndCost();
        void promptCargoInput();
        void promptFindDelivery();
        void promptModifyDelivery();
        void promptRemoveDelivery();
        void promptNextCustomerScene();
        void setCatalog();
        void clearScreen();

    public:
        GameManager(AirshipOrderList& airshipOrderList);
        void runStartingScene(const std::string& szScene);
        void runCustomerScene(const std::string& szScene);
        void runGuessingScene(const std::string& szScene);
        void runEndingScene(const std::string& szScene);
        bool getIsGuessCorrect() { return bIsGuessCorrect; }
};
