#pragma once
#include "DisplayManager.hpp"
#include "AirshipOrderList.hpp"

class GameManager{
    private:
        const AirshipOrderList& m_airshipOrderList;
    private:
        void promptCargoInput();
        void promptNextCustomerScene();
        void clearScreen();
    public:
        GameManager(const AirshipOrderList& airshipOrderList);
        void runCustomerScene(const std::string& szScene);
        void runStartingScene(const std::string& szScene);
};
