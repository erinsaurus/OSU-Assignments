#include "Item.hpp"
#include <iostream>
using namespace std;

//Default constructor initializes variables
Item::Item()
{
    name = "";
    price = 0.0;
    quantity = 0;
    
}

//Constructor
Item::Item(string n,double p,int q)
{
    name = n;
    price = p;
    quantity = q;
}

//Set name
void Item::setName(string n)
{
    name = n;
}

//Get name
string Item::getName()
{
    return name;
}

//Set price
void Item::setPrice(double p)
{
    price = p;
}

//Get price
double Item::getPrice()
{
    return price;
}

//Set quantity
void Item::setQuantity(int q)
{
    quantity = q;
}

//Get quantity
int Item::getQuantity()
{
    return quantity;
}
