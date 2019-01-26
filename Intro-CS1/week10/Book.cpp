#include "Book.hpp"
#include <iostream>


Book::Book(std::string idc, std::string t, std::string a)
{
    idCode = idc;
    title = t;
    author = a;
    setLocation(ON_SHELF);
    setCheckedOutBy(NULL);
    setRequestedBy(NULL);
}

int Book::getCheckOutLength()
{
    return CHECK_OUT_LENGTH;
}

std::string Book::getIdCode()
{
    return idCode;
}

std::string Book::getTitle()
{
    return title;
}

std::string Book::getAuthor()
{
    return author;
}

Locale Book::getLocation()
{
    return location;
}

void Book::setLocation(Locale loc)
{
    location = loc;
}

Patron* Book::getCheckedOutBy()
{
    return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* pat)
{
    checkedOutBy = pat;
}

Patron* Book::getRequestedBy()
{
    return requestedBy;
}

void Book::setRequestedBy(Patron* pr)
{
    requestedBy = pr;
}

int Book::getDateCheckedOut()
{
    return dateCheckedOut;
}

void Book::setDateCheckedOut(int date) 
{
    dateCheckedOut = date;
}