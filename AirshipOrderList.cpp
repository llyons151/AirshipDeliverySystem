/*********************************************************************
File name: AirshipOrderList.cpp
Author: <Luke Lyons>(<ujw18>)
Date: 11/14/2025

Purpose:
    Implementation file for the AirshipOrderList class. Manages a
    linked list of delivery orders for the airship system.
Command Parameters:
    N/A
Input:
    Delivery information (customer name, item, quantity, cost).
Results:
    Maintains and manipulates linked list of deliveries.
Notes:
    Implements linked list operations for delivery management.
*********************************************************************/

#include "AirshipOrderList.hpp"

/*********************************************************************
AirshipOrderList::AirshipOrderList()
Purpose:
    Constructor that initializes an empty delivery list.
Parameters:
    None
Return Value:
    None (constructor)
Notes:
    Sets head pointer to nullptr.
*********************************************************************/
AirshipOrderList::AirshipOrderList() : pHead(nullptr) {}

/*********************************************************************
AirshipOrderList::~AirshipOrderList()
Purpose:
    Destructor that frees all dynamically allocated delivery nodes.
Parameters:
    None
Return Value:
    None (destructor)
Notes:
    Traverses list and deletes each node to prevent memory leaks.
*********************************************************************/
AirshipOrderList::~AirshipOrderList()
{
    Delivery* current = pHead;
    Delivery* nextNode;
    while(current != nullptr)
    {
        nextNode = current->pNext;
        delete current;
        current = nextNode;
    }
}

/*********************************************************************
void AirshipOrderList::addDelivery(std::string szCust, std::string szItm, int iQty, double dCst)
Purpose:
    Adds a new delivery to the end of the linked list.
Parameters:
    I std::string szCust - Customer name
    I std::string szItm - Item description
    I int iQty - Quantity of items
    I double dCst - Cost of delivery
Return Value:
    None
Notes:
    Creates new delivery node and appends to end of list.
*********************************************************************/
void AirshipOrderList::addDelivery(std::string szCust, std::string szItm, int iQty, double dCst)
{
    Delivery* newDelivery = new Delivery(szCust, szItm, iQty, dCst);

    if(pHead == nullptr)
    {
        pHead = newDelivery;
        return;
    }

    Delivery* current = pHead;
    while(current->pNext != nullptr)
    {
        current = current->pNext;
    }
    current->pNext = newDelivery;
}

/*********************************************************************
Delivery* AirshipOrderList::findDelivery(std::string szCust, std::string szItm) const
Purpose:
    Searches for a delivery by customer name and item.
Parameters:
    I std::string szCust - Customer name to search for
    I std::string szItm - Item name to search for
Return Value:
    Delivery* - Pointer to found delivery, or nullptr if not found
Notes:
    Searches list for exact match of both name and item.
*********************************************************************/
Delivery* AirshipOrderList::findDelivery(std::string szCust, std::string szItm) const
{
    Delivery* current = pHead;

    while(current != nullptr)
    {
        if(current->szName == szCust && current->szItem == szItm) return current;
        current = current->pNext;
    }
    return nullptr;
}

/*********************************************************************
bool AirshipOrderList::removeDelivery(string szCust, string szItm)
Purpose:
    Removes a delivery from the list by customer name and item.
Parameters:
    I string szCust - Customer name
    I string szItm - Item name
Return Value:
    bool - True if delivery was found and removed, false otherwise
Notes:
    Searches for delivery and removes it from list, freeing memory.
*********************************************************************/
bool AirshipOrderList::removeDelivery(string szCust, string szItm)
{
    if(pHead == nullptr) return false;

    if(pHead->szName == szCust && pHead->szItem == szItm)
    {
        Delivery* temp = pHead;
        pHead = pHead->pNext;
        delete temp;
        return true;
    }

    Delivery* prev = pHead;
    Delivery* current = pHead->pNext;

    while(current != nullptr)
    {
        if(current->szName == szCust && current->szItem == szItm)
        {
            prev->pNext = current->pNext;
            delete current;
            return true;
        }
        prev = current;
        current = current->pNext;
    }
    return false;
}

/*********************************************************************
bool AirshipOrderList::modifyDelivery(string szCust, string szItm, int iNewQty, double dNewCst)
Purpose:
    Modifies the quantity and cost of an existing delivery.
Parameters:
    I string szCust - Customer name
    I string szItm - Item name
    I int iNewQty - New quantity value
    I double dNewCst - New cost value
Return Value:
    bool - True if delivery was found and modified, false otherwise
Notes:
    Uses findDelivery to locate the delivery before modifying.
*********************************************************************/
bool AirshipOrderList::modifyDelivery(string szCust, string szItm, int iNewQty, double dNewCst)
{
    Delivery* delivery = findDelivery(szCust, szItm);
    if(delivery == nullptr) return false;

    delivery->iQuantity = iNewQty;
    delivery->dCost = dNewCst;

    return true;
}

/*********************************************************************
void AirshipOrderList::displayDeliveries() const
Purpose:
    Displays all deliveries in the list.
Parameters:
    None
Return Value:
    None
Notes:
    Outputs formatted list of all deliveries with details.
*********************************************************************/
void AirshipOrderList::displayDeliveries() const
{
    Delivery* current = pHead;
    int iCount = 1;

    if(current == nullptr)
    {
        std::cout << "No deliveries to display\n";
        return;
    }

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
    }
}

/*********************************************************************
void AirshipOrderList::displayDelivery(const Delivery* delivery)
Purpose:
    Displays a single specific delivery.
Parameters:
    I const Delivery* delivery - Pointer to delivery to display
Return Value:
    None
Notes:
    Searches for delivery matching the provided delivery's name and item.
*********************************************************************/
void AirshipOrderList::displayDelivery(const Delivery* delivery)
{
    Delivery* current = pHead;
    int iCount = 1;

    if(current == nullptr)
    {
        std::cout << "No deliveries to display\n";
        return;
    }

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
        }

        current = current->pNext;
    }
}
