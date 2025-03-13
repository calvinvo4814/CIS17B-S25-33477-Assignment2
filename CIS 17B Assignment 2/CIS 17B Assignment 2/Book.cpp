#include "Book.h"
//Constructor
Book::Book(string a, string b, string c) : title(a), author(b), isbn(c), available(true) {}

//Returns title, author, isbn, available
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }
void Book::setAvailable(bool status) { available = status; }