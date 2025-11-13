#pragma once
#include "DisplayManager.hpp"
#include "AirshipOrderList.hpp"
#include <string>

class GameManager{
    private:
        const char* szLineSpacing = "        ";
        std::string szCatalog;
        AirshipOrderList& m_airshipOrderList;
        std::string m_fraudulentPackageName = "Grey";
        std::string m_szName;
        std::string m_szItem;
        int m_iQuantity;
        double m_dCost;
        bool bHasRemovedPackage = false;
        bool bIsGuessCorrect = false;

    private:
        int promptGuessingScene();
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
