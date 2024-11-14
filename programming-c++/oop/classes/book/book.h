#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
    std::string _isbn;
    std::string _author;
    std::string _title;

public:
    // Constructor
    Book(const std::string& isbn, const std::string& author, const std::string& title);

    // Accessor methods for isbn
    std::string isbn() const;
    void isbn(const std::string& isbn);

    // Accessor methods for author
    std::string author() const;
    void author(const std::string& author);

    // Accessor methods for title
    std::string title() const;
    void title(const std::string& title);

    // Method to convert the object to JSON
    std::string toJson() const;
};

#endif // BOOK_H
