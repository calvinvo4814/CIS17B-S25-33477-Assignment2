#include "Library.h"
#include <iostream>

using namespace std;

//Static pointer
Library* Library::instance = nullptr;

Library& Library::getInstance()
{
    if (!instance)
    {
        instance = new Library();
    }
    return *instance;
}
//Deconstructor
Library::~Library()
{
    for (auto user : users)
    {
        delete user;
    }
    users.clear();

    delete instance;
    instance = nullptr;
}

//Adds book 
void Library::addBook()
{
    string title, author, isbn;
    cin.ignore();
    cout << "Please enter the title: ";
    getline(cin, title);
    cout << "Please enter the author: ";
    getline(cin, author);
    cout << "Please enter the ISBN: ";
    getline(cin, isbn);

    books.push_back(Book(title, author, isbn));
    cout << "Book Added" << endl;
}

//edits Book
void Library::editBook()
{
    cout << "Enter the title of the book to edit: ";
    string title;
    cin.ignore();
    getline(cin, title);

    for (auto& book : books) {
        if (book.getTitle() == title) {
            cout << "Please enter new title: ";
            string newTitle;
            getline(cin, newTitle);
            cout << "Please enter new author: ";
            string newAuthor;
            getline(cin, newAuthor);
            cout << "Please enter new ISBN: ";
            string newISBN;
            getline(cin, newISBN);

            book.setTitle(newTitle);
            book.setAuthor(newAuthor);
            book.setISBN(newISBN);
            cout << "Book updated successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

//Remove book
void Library::removeBook()
{
    cout << "Enter the title of the book to remove: ";
    string title;
    cin.ignore();
    getline(cin, title);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

//add User
void Library::addUser()
{
    string name;
    int type;

    cout << "Enter 1 for Student, 2 for Faculty: ";
    cin >> type;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    User* newUser = nullptr;
    if (type == 1)
    {
        newUser = new Student(name);
    }
    else
    {
        newUser = new Faculty(name);
    }

    users.push_back(newUser);

   
    cout << "User Added with ID: " << newUser->getUserID() << endl;
}
//Edits the user information
void Library::editUser()
{
    cout << "Enter the user ID to edit: ";
    int userID;
    cin >> userID;
    cin.ignore();

    for (auto user : users)
    {
        if (user->getUserID() == userID)
        {
            cout << "Enter new name: ";
            string newName;
            getline(cin, newName);
            user->setUserName(newName);
            cout << "User updated successfully." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}
//Remove User
void Library::removeUser()
{
    cout << "Enter the user ID to remove: ";
    int userID;
    cin >> userID;

    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if ((*it)->getUserID() == userID)
        {
            delete* it;  
            users.erase(it);
            cout << "User removed successfully." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

//Checks in the book
void Library::checkInBook()
{
    cout << "Enter the user ID: ";
    int userID;
    cin >> userID;
    cin.ignore();

    User* foundUser = nullptr;
    for (auto user : users)
    {
        if (user->getUserID() == userID)
        {
            foundUser = user;
            break;
        }
    }
    if (!foundUser)
    {
        cout << "User not found." << endl;
        return;
    }

    cout << "Enter the title of the book to check in: ";
    string bookTitle;
    getline(cin, bookTitle);

    for (auto& book : books)
    {
        if (book.getTitle() == bookTitle)
        {
            if (!book.isAvailable())
            {
                book.setAvailable(true);
                foundUser->returnBook(&book);

                cout << "Book checked in successfully!\n";
                return;
            }
            else
            {
                cout << "This book was already marked as available.\n";
                return;
            }
        }
    }
    cout << "Book not found in the library." << endl;
}

//Chekcs out the book
void Library::checkOutBook()
{
    int userID;
    cout << "Enter the user ID: ";
    cin >> userID;
    cin.ignore(); 

    User* foundUser = nullptr;
    for (auto user : users)
    {
        if (user->getUserID() == userID)
        {
            foundUser = user;
            break;
        }
    }
    if (!foundUser)
    {
        cout << "User not found." << endl;
        return;
    }

    cout << "Enter the title of the book to check out: ";
    string bookTitle;
    getline(cin, bookTitle);

    for (auto& book : books)
    {
        if (book.getTitle() == bookTitle)
        {
            if (!book.isAvailable())
            {
                cout << "Sorry, that book is currently unavailable." << endl;
                return;
            }
            book.setAvailable(false);
            foundUser->borrowBook(&book);

            cout << "Book checked out successfully!\n";
            return;
        }
    }
    cout << "Book not found in the library." << endl;
}

//Lists all the users  
void Library::listAllUsers()
{
    cout << "List of All Users:" << endl;

    if (users.empty())
    {
        cout << "No users found." << endl;
        return;
    }

    for (const auto& user : users)
    {
        cout << "User ID: " << user->getUserID()
            << endl << "Name: " << user->getUserName()
            << endl << "Borrowed Books: " << user->getBorrowedBookCount();
    }
}

//Lists all the books
void Library::listAllBooks()
{
    cout << "Here are the list of all books:" << endl;

    if (books.empty()) {
        cout << "No books available." << endl;
        return;
    }

    for (const auto& book : books)
    {
        cout << "Title: " << book.getTitle() <<endl<< "Author: " << book.getAuthor()
            <<endl<< "ISBN: " << book.getISBN() << endl << "Available: " << (book.isAvailable() ? "Yes" : "No");
    }
}

