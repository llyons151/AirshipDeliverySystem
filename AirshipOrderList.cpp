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
    while(current != nullptr)
    {
        if(current->pNext == nullptr)
        {
            current->pNext = newDelivery;
            return;
        }
        else
        {
            current = current->pNext;
        }
    };
};
