#pragma once
#include <string>

class DisplayManager {
private:
    std::string m_szStartingScene;
    std::string m_szCustomerOne;
    std::string m_szCustomerTwo;
    std::string m_szCustomerThree;
    std::string m_szCustomerFour;
    std::string m_szCustomerFive;
    std::string m_szCustomerSix;

    void setStartingScene();
    void setCustomerOne();
    void setCustomerTwo();
    void setCustomerThree();
    void setCustomerFour();
    void setCustomerFive();
    void setCustomerSix();

public:
    DisplayManager();
    const std::string& getStartingScene()  const { return m_szStartingScene; }
    const std::string& getCustomerOne()    const { return m_szCustomerOne; }
    const std::string& getCustomerTwo()    const { return m_szCustomerTwo; }
    const std::string& getCustomerThree()  const { return m_szCustomerThree; }
    const std::string& getCustomerFour()   const { return m_szCustomerFour; }
    const std::string& getCustomerFive()   const { return m_szCustomerFive; }
    const std::string& getCustomerSix()    const { return m_szCustomerSix; }
};
