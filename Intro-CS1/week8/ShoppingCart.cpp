#include "ShoppingCart.hpp"
#include "Item.hpp"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart()
{
    //Loop that sets each member of the array to NULL
    for(int i = 0; i < 100; i++)
    {
        ItemArray[i] = NULL;
        
    }
    //Constructor initializes arrayEnd to zero
    arrayEnd = 0;
}

void ShoppingCart::addItem(Item *NewItem)
{
    //Add new items to ItemArray
    ItemArray[arrayEnd] = NewItem;
    arrayEnd++;
  
}

double ShoppingCart::totalPrice()
{
    double totalCost = 0;
    
    // Loop to add cost of each item in ShoppingCart
    for(int i = 0; i < arrayEnd; i++)
        if (ItemArray[i] != NULL)
        {
            //Use get methods to add cost of items
            totalCost += ItemArray[i]->getPrice() * ItemArray[i]->getQuantity();
        }
    
    
    //return total cost
    return totalCost;
}

