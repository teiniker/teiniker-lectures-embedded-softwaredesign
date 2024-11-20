#include <string>
#include <sstream>
#include "book.h"

using namespace std;

// Constructor
Book::Book(const string& isbn, const string& author, const string& title)
    : _isbn{isbn}, _author{author}, _title{title}
{
}

// Accessor methods for isbn
string Book::isbn() const
{
    return _isbn;
}
void Book::isbn(const string& isbn)
{
    _isbn = isbn;
}

// Accessor methods for author
string Book::author() const
{
    return _author;
}
void Book::author(const string& author)
{
    _author = author;
}

// Accessor methods for title
string Book::title() const
{
    return _title;
}
void Book::title(const string& title)
{
    _title = title;
}

// Method to convert the object to JSON
string Book::toJson() const
{
    char buffer[120];

    snprintf(buffer, sizeof(buffer), "{\"isbn\":\"%s\",\"author\":\"%s\",\"title\":\"%s\"}",
             _isbn.c_str(), _author.c_str(), _title.c_str());
    
    return string(buffer);
}

