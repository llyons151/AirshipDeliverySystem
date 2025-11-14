/*********************************************************************
File name: DisplayManager.hpp
Author: <Luke Lyons>(<ujw18>)
Date: 11/14/2025

Purpose:
    Header file for the DisplayManager class which manages all display
    text and scenes for the Airship Delivery System game.
Command Parameters:
    N/A
Input:
    N/A
Results:
    Class definition for DisplayManager.
Notes:
    Contains story scenes and customer dialogue for the game.
*********************************************************************/

#pragma once
#include <string>

/*********************************************************************
Class Name: DisplayManager
Purpose:
    Manages and stores all display text for the Airship Delivery
    System game including story scenes and customer dialogues.
Notes:
    All scenes are stored as strings and initialized in the constructor.
    Getter methods provide read-only access to scene text.
*********************************************************************/
class DisplayManager
{
private:
    std::string m_szStartingScene;  // Opening scene text
    std::string m_szCustomerOne;    // Bulk Ryker scene text
    std::string m_szCustomerTwo;    // Buck Hawthorne scene text
    std::string m_szCustomerThree;  // Old Man Ripple scene text
    std::string m_szCustomerFour;   // Bramble Nett scene text
    std::string m_szCustomerFive;   // Vesper Morrow scene text
    std::string m_szCustomerSix;    // Linton Yarrow scene text
    std::string m_szGuessingScene;  // Guessing phase scene text
    std::string m_szVictoryScene;   // Victory ending scene text
    std::string m_szLosingScene;    // Losing ending scene text

    void setStartingScene();
    void setCustomerOne();
    void setCustomerTwo();
    void setCustomerThree();
    void setCustomerFour();
    void setCustomerFive();
    void setCustomerSix();
    void setGuessingScene();
    void setVictoryScene();
    void setLosingScene();

public:
    DisplayManager();
    const std::string& getStartingScene()  const { return m_szStartingScene; }
    const std::string& getCustomerOne()    const { return m_szCustomerOne; }
    const std::string& getCustomerTwo()    const { return m_szCustomerTwo; }
    const std::string& getCustomerThree()  const { return m_szCustomerThree; }
    const std::string& getCustomerFour()   const { return m_szCustomerFour; }
    const std::string& getCustomerFive()   const { return m_szCustomerFive; }
    const std::string& getCustomerSix()    const { return m_szCustomerSix; }
    const std::string& getGuessingScene()  const { return m_szGuessingScene; }
    const std::string& getVictoryScene()   const { return m_szVictoryScene; }
    const std::string& getLosingScene()   const { return m_szLosingScene; }
};
