#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;

class Library
{
private:
    //Private member for Library
    vector<Book> books;
    vector<User*> users;
    Library() {}
    static Library* instance;

public:
    //Public member for Library
    static Library& getInstance();
    ~Library();

    void addUser();
    void editUser();
    void removeUser();
    void listAllUsers();

    void addBook();
    void editBook();
    void removeBook();
    void listAllBooks();

   

    void checkOutBook();
    void checkInBook();
};

#endif 