#include "AirshipOrderList.hpp"
#include "DisplayManager.hpp"
#include "GameManager.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    AirshipOrderList airshipOrderList;
    DisplayManager displayManager;
    GameManager gameManager(airshipOrderList);

    gameManager.runStartingScene(displayManager.getStartingScene());
    gameManager.runCustomerScene(displayManager.getCustomerOne());
    gameManager.runCustomerScene(displayManager.getCustomerTwo());
    gameManager.runCustomerScene(displayManager.getCustomerThree());
    gameManager.runCustomerScene(displayManager.getCustomerFour());
    gameManager.runCustomerScene(displayManager.getCustomerFive());
    gameManager.runCustomerScene(displayManager.getCustomerSix());

    return 0;
}
