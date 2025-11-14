/*********************************************************************
File name: program5_driver.cpp
Author: <Luke Lyons>(<ujw18>)
Date: 11/14/2025

Purpose:
    Main driver program for the Airship Delivery System game.
    Manages game flow from start to end.
Command Parameters:
    None
Input:
    User input throughout game execution.
Results:
    Runs complete game session with victory or defeat ending.
Notes:
    Creates game objects and coordinates scene progression.
*********************************************************************/

#include "AirshipOrderList.hpp"
#include "DisplayManager.hpp"
#include "GameManager.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/*********************************************************************
int main()
Purpose:
    Main entry point for the Airship Delivery System game.
Parameters:
    None
Return Value:
    int - 0 on successful completion
Notes:
    Initializes game objects and runs through all scenes in sequence.
*********************************************************************/
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
    gameManager.runGuessingScene(displayManager.getGuessingScene());

    if(gameManager.getIsGuessCorrect() == true)
    {
        gameManager.runEndingScene(displayManager.getVictoryScene());
    }
    else
    {
        gameManager.runEndingScene(displayManager.getLosingScene());
    }

    return 0;
}
