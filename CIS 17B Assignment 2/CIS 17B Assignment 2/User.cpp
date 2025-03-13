#include "User.h"
#include <iostream>
using namespace std;

//Static member
int User::ID = 0;

//Constructor
User::User(string newName) 
    : userName(newName), userID(ID++) {}

//returns user name
string User::getUserName() const {
    return userName;
}

//Return UserID
int User::getUserID() const {
    return userID;
}

//Return Borrowed Book
void User::borrowBook(Book* book) {
    if (book) {
        borrowedBooks.push_back(book);
    }
}

void User::returnBook(Book* book) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == book) {
            borrowedBooks.erase(it);
            return;
        }
    }
    cout << "Book not found" << endl;
}
