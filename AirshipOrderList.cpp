#include "AirshipOrderList.hpp"

AirshipOrderList::AirshipOrderList() : pHead(nullptr) {};

AirshipOrderList::~AirshipOrderList()
{
    Delivery* current = pHead;
    Delivery* nextNode; 
    while(current != nullptr)
    {
        nextNode = current->pNext;
        delete current;
        current = nextNode;
    };
};

void AirshipOrderList::addDelivery(std::string szCust, std::string szItm, int iQty, double dCst)
{
    Delivery* newDelivery = new Delivery(szCust, szItm, iQty, dCst);

    if(pHead == nullptr)
    {
        pHead = newDelivery;
        return;
    };

    Delivery* current = pHead;
    while(current->pNext != nullptr)
    {
        current = current->pNext;
    };
    current->pNext = newDelivery;
};

Delivery* AirshipOrderList::findDelivery(std::string szCust, std::string szItm) const
{
    Delivery* current = pHead;

    while(current != nullptr)
    {
        if(current->szName == szCust && current->szItem == szItm) return current;
        current = current->pNext;
    };
    return nullptr;
};


bool AirshipOrderList::removeDelivery(string szCust, string szItm)
{
    if(pHead == nullptr) return false;

    if(pHead->szName == szCust && pHead->szItem == szItm)
    {
        Delivery* temp = pHead;
        pHead = pHead->pNext;
        delete temp;
        return true;
    };

    Delivery* prev = pHead;
    Delivery* current = pHead->pNext;

    while(current != nullptr)
    {
        if(current->szName == szCust && current->szItem == szItm)
        {
            prev->pNext = current->pNext;
            delete current;
            return true;
        };
        prev = current;
        current = current->pNext;
    };
    return false;
};

bool AirshipOrderList::modifyDelivery(string szCust, string szItm, int iNewQty, double dNewCst)
{
    Delivery* delivery = findDelivery(szCust, szItm);
    if(delivery == nullptr) return false;

    delivery->iQuantity = iNewQty;
    delivery->dCost = dNewCst;

    return true;
};

void AirshipOrderList::displayDeliveries() const
{
    Delivery* current = pHead;
    int iCount = 1;

    if(current == nullptr)
    {
        std::cout << "No deliveries to display\n";
        return;
    };

    std::cout << szLineSpacing << "──────────────────────────────────────────────\n";
    std::cout << szLineSpacing << "               ALL DELIVERIES\n";
    std::cout << szLineSpacing << "──────────────────────────────────────────────\n\n";
    while(current != nullptr)
    {
        std::cout << szLineSpacing << "DELIVERY NUMBER: " << iCount << "\n";
        std::cout << szLineSpacing << "Name: " << current->szName << "\n";
        std::cout << szLineSpacing << "Item: " << current->szItem << "\n";
        std::cout << szLineSpacing << "Quantity: " << current->iQuantity << "\n";
        std::cout << szLineSpacing << "Cost: " << current->dCost << "\n\n";
        iCount++;
        current = current->pNext;
    };
};

void AirshipOrderList::displayDelivery(const Delivery* delivery)
{
    Delivery* current = pHead;
    int iCount = 1;

    if(current == nullptr)
    {
        std::cout << "No deliveries to display\n";
        return;
    };

    while(current != nullptr)
    {
        if(current->szName == delivery->szName && current->szItem == delivery->szItem)
        {
            std::cout << szLineSpacing << "DELIVERY NUMBER: " << iCount << "\n";
            std::cout << szLineSpacing << "Name: " << current->szName << "\n";
            std::cout << szLineSpacing << "Item: " << current->szItem << "\n";
            std::cout << szLineSpacing << "Quantity: " << current->iQuantity << "\n";
            std::cout << szLineSpacing << "Cost: " << current->dCost << "\n";
            return;
        };

        current = current->pNext;
    };
};
