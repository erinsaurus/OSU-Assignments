#include "Library.hpp"
#include <string>
#include <vector>
#include <iostream>

//constructor initializes the currentDate to 0
Library::Library()
{
    
    currentDate = 0;
}

//adds the parameter to holdings vector
void Library::addBook(Book* addBook)
{
holdings.push_back(addBook);
}

//adds the parameter to members vector
void Library::addPatron(Patron* addPat)
{
    members.push_back(addPat);
}

//returns a pointer to the Book corresponding to the ID parameter or NULL if no such Book in holdings
Book* Library::getBook(std::string bID)
{
    //loop through the holdings vector to find the book with the specified ID Code
    for (int i = 0; i < holdings.size(); i++)
    {
        std::string currentID = holdings.at(i)->getIdCode();
        
        // if the specified ID Code is equal to the current element of the holdings vector
        if (bID == currentID)
        {
            return holdings.at(i);
        }
    }
    
    // given ID did not match a Book in the holdings
    return NULL;
}

//returns a pointer to the Patron corresponding to the ID parameter or NULL if no such Patron is a member
Patron* Library::getPatron(std::string pID)
{
    
    // search through all the members
    for (int i = 0; i < members.size(); i++)
    {
        std::string curID = members.at(i)->getIdNum();
        
        // check for equality of strings
        if (pID == curID)
        {
            return members.at(i);
        }
    }
    
    // given ID did not match a Patron member
    return NULL;
}


std::string Library::checkOutBook(std::string pID, std::string bID)
{
 
//pointers to get functions in Book class
Book *book = getBook(bID);
Patron *patron = getPatron(pID);

    //if the specified Book is not in the library
    if(book == NULL)
    {
        return "book not found";
    }
    
    //if the specified Patron is not in the library
    if(patron == NULL)
    {
        return "patron not found";
    }
    
    //get location of book
    Locale location = book->getLocation();
    
    //if the specified Book is already checked out
    if (location == CHECKED_OUT){
        return "book already checked out";
    }
    
    //if the specified Book is on hold by another Patron
    if (location == ON_HOLD_SHELF)
    {
        if(book->getRequestedBy() != patron)
        {
            return "book on hold by other patron";
        
            //if specified Book is on hold by this patron, updated requestedBy
        } else
        
        {
            book->setRequestedBy(NULL);
        }
    }
    
    //update the Book's checkedOutBy
    book->setCheckedOutBy(patron);
    //update the Book's dateCheckedOut
    book->setDateCheckedOut(currentDate);
    //update the Book's location
    book->setLocation(CHECKED_OUT);
    //update the Patron's checkedOutBooks
    patron->addBook(book);
    return "check out successful";
}


std::string Library::returnBook(std::string bID) {
    Book *book = getBook(bID);
    
    // if the specified Book is not in the Library
    if (book == NULL) {
        return "book not found";
    }
    
    // determine Book's status
    Locale status = book->getLocation();
    
    // if the Book is not checked out
    if (status != CHECKED_OUT) {
        return "book already in library";
    }

    
    // find patron via checkedOutBy vector
    Patron *patron = book->getCheckedOutBy();
    
    // update the Patron's checkedOutBooks
    patron->removeBook(book);
    
    //update the Book's location depending on whether another Patron has requested it
    if (book->getRequestedBy())
    {
        book->setLocation(ON_HOLD_SHELF);
    } else
    {
        book->setLocation(ON_SHELF);
    }
    
    // update the Book's checkedOutBy
    book->setCheckedOutBy(NULL);
    
    return "return successful";
}

std::string Library::requestBook(std::string pID, std::string bID) {
    Book *book = getBook(bID);
    Patron *patron = getPatron(pID);
    
    // if the specified Book is not in the Lbrary
    if (book == NULL)
    {
        return "book not found";
    }
    
    // if the specified Patron is not in the Library
    if (patron == NULL)
    {
        return "patron not found";
    }
    
    // find Book's location
    Locale location = book->getLocation();
    
    // if the specified book is already requested
    if (location == ON_HOLD_SHELF)
    {
        if (book->getRequestedBy() != patron)
        {
            return "book already on hold";
        }
    }
    
    // if the Book is on the shelf, update its location to on hold
    if (location == ON_SHELF)
    {
        book->setLocation(ON_HOLD_SHELF);
    }
    
    // update the Book's requested by
    book->setRequestedBy(patron);
    
    return "request successful";
}

//takes parameter of ammount being paid and amends fine
std::string Library::payFine(std::string pID, double payment)
{
    Patron *patron = getPatron(pID);
    
    // if Patron is not a Library member return patron not found
    if (patron == NULL)
    {
        return "patron not found";
        
    }else
  
    // if Patron is a library member, amend fine and return payment successful
   patron->amendFine(-(payment));
    
   return "payment successful";
}


//find the fines for each patron per book checked out
void Library::incrementCurrentDate()
{
 
currentDate++;

    //loop to see if book is overdue. If it is, charge the patron who has it checked out $0.10
    for(int i = 0; i < holdings.size(); i++)
    { Book *book = holdings.at(i);
        { if(currentDate - (book->getCheckOutLength() + book->getDateCheckedOut()) > 0)
        { Patron *patron = book->getCheckedOutBy();
                if(patron != NULL)
                {
                    patron->amendFine(0.10);
                }
            

        }
        }
    }
}
