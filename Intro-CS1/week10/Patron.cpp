#include "Patron.hpp"
#include <string>

//constructor takes idNum and name and initializes fineAmount to 0
Patron::Patron(std::string idn, std::string n)
{
    idNum = idn;
    name = n;
    fineAmount = 0.0;
}

std::string Patron::getIdNum() //get ID number
{
    return idNum;
}

std::string Patron::getName() //get name
{
    return name;
}

std::vector<Book*> Patron::getCheckedOutBooks() //get books checked out by patron
{
    return checkedOutBooks;
}

//add book checked out by patron to checkedOutBooks vector
void Patron::addBook(Book* b)
{
    checkedOutBooks.push_back(b);
}

// remove book from vector if found in checkedOutBooks
void Patron::removeBook(Book *b)
{
    for (int i = 0; i < checkedOutBooks.size(); i++)
    {
        Book *currentBook = checkedOutBooks.at(i);
        if (b == currentBook)
        {
            checkedOutBooks.erase(checkedOutBooks.begin() + i);
      
        }
    }
}


double Patron::getFineAmount() //get fine Amount
{
    return fineAmount;
}

//a positive argument increases the fineAmount, a negative one decreases it
void Patron::amendFine(double amount)
{

    fineAmount += amount;
}