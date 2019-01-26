#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "Item.hpp"
#include <iostream>
using namespace std;

//ShoppingCart class
class ShoppingCart

{
    
private:
    Item* ItemArray[100];
    int arrayEnd;
    
public:
    //constructor
    ShoppingCart();
    
    double totalPrice();
    void addItem(Item *);

};

#endif