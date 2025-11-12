#pragma once
#include "DisplayManager.hpp"
#include "AirshipOrderList.hpp"

class GameManager{
    private:
        AirshipOrderList& m_airshipOrderList;
    private:
        void promptCargoInput();
        void promptNextCustomerScene();
        void clearScreen();
    public:
        GameManager(AirshipOrderList& airshipOrderList);
        void runCustomerScene(const std::string& szScene);
        void runStartingScene(const std::string& szScene);
};
