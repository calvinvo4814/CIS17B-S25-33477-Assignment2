#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

using namespace std;

class User {
protected:
    //Protected member for User
    string userName;
    int userID;
    static int ID;

    vector<Book*> borrowedBooks;

public:
    //Public member for User
    User(string name);
    virtual ~User() = default;

    virtual string getUserType() const = 0;
    string getUserName() const;
    int getUserID() const;

    void borrowBook(Book* book);
    void returnBook(Book* book);

    void setUserName(const string& newName) { userName = newName; }
    int getBorrowedBookCount() const { return borrowedBooks.size(); }

};

#endif
