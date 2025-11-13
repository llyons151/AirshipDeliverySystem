#pragma once
#include "DisplayManager.hpp"
#include "AirshipOrderList.hpp"
#include <string>

class GameManager{
    private:
        const char* szLineSpacing = "        ";
        std::string szCatalog;
        AirshipOrderList& m_airshipOrderList;
        std::string m_szName;
        std::string m_szItem;

    private:
        int promptGuessingScene();
        void promptNameAndItem();
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
};
