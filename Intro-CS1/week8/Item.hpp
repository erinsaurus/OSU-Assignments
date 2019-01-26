#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
using namespace std;


class Item
{
private:
    
    //Variables
    string name;
    double price;
    int quantity;
    
public:
    
    //Default Constructor
    Item();
    
    //Non-Default Constructor
    Item(string name, double price, int quantity);
    
    //Get and Set Methods
    void setPrice(double);
    void setName(string);
    void setQuantity(int);
    double getPrice();
    string getName();
    int getQuantity();
    

};

#endif