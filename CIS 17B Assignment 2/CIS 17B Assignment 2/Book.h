#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
private:
    //Private members for Book
    string title;
    string author;
    string isbn;
    bool available;

public:
    //Public members for Book
    Book(string title, string author, string isbn);
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;

    bool isAvailable() const;

    void setAvailable(bool status);
    void setTitle(const string& newTitle) { title = newTitle; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setISBN(const string& newISBN) { isbn = newISBN; }

};

#endif
