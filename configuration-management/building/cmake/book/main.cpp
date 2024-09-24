#include "book.h"
#include <assert.h>
#include <stdlib.h>

int main(void)
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         

    assert("978-0131103627" == book.getIsbn());
    assert("Brian W. Kernighan and Dennis Ritchie" == book.getAuthor());
    assert("The C Programming Language" == book.getTitle()); 
    assert("{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}" == book.toJson());

    return EXIT_SUCCESS;
}