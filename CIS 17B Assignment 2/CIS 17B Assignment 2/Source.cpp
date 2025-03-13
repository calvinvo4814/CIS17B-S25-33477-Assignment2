#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Library.h"
#include "User.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

//Menu functions
void displayMenu();
void manageBooksMenu(Library& collegeLibrary);
void manageUsersMenu(Library& collegeLibrary);
void manageTransactionsMenu(Library& collegeLibrary);

int main()
{
    //Singleton function
    Library& collegeLibrary = Library::getInstance();

    const int bookChoice = 1;
    const int userChoice = 2;
    const int transactionChoice = 3;
    const int quitChoice = 4;

    int choice;
    do {
        //Greets users and opens options for users to pick
        cout << "Welcome to Library by Calvin Vo:" << endl;
        cout << "1. Manage Books" << endl;
        cout << "2. Manage Users" << endl;
        cout << "3. Manage Transactions" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        //Navigates differently depending what user chose
        if (choice == bookChoice)
        {
            manageBooksMenu(collegeLibrary);
        }
        else if (choice == userChoice)
        {
            manageUsersMenu(collegeLibrary);
        }
        else if (choice == transactionChoice)
        {
            manageTransactionsMenu(collegeLibrary);
        }
        else if (choice == quitChoice)
        {
            cout << "Thank you for using our Library Management System!" << endl;
        }
        else
        {
            cout << "Invalid! Please choose a valid option." << endl;
        }
    } while (choice != quitChoice);

    return 0;
}
//Manages the books such as add, edit, remove
void manageBooksMenu(Library& collegeLibrary)
{
    int choice;
    do {
        cout << "Manage Books:" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Edit a Book" << endl;
        cout << "3. Remove a Book" << endl;
        cout << "4. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            collegeLibrary.addBook();
        }
        else if (choice == 2)
        {
            collegeLibrary.editBook();
        }
        else if (choice == 3)
        {
            collegeLibrary.removeBook();
        }
        else {
            cout << "Your choice is invalid. Please try again" << endl;
        }
    } while (choice != 4);
}

//Manages users such as add, edit, remove
void manageUsersMenu(Library& collegeLibrary)
{
    int choice;
    do {
        cout << "Manage Users:" << endl;
        cout << "1. Add a User" << endl;
        cout << "2. Edit a User" << endl;
        cout << "3. Remove a User" << endl;
        cout << "4. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            collegeLibrary.addBook();
        }
        else if (choice == 2)
        {
            collegeLibrary.editBook();
        }
        else if (choice == 3)
        {
            collegeLibrary.removeBook();
        }
        else {
            cout << "Your choice is invalid. Please try again" << endl;
        }
    } while (choice != 4);
}

//Manages transaction such as check out, check in ,list books, list users
void manageTransactionsMenu(Library& collegeLibrary)
{
    int choice;
    do {
        cout << "Manage Transactions:" << endl;
        cout << "1. Check Out A Book" << endl;
        cout << "2. Check In A Book" << endl;
        cout << "3. List All Books" << endl;
        cout << "4. List All Users" << endl;
        cout << "5. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            collegeLibrary.checkOutBook();
            cout << endl;
        }
        else if (choice == 2)
        {
            collegeLibrary.checkOutBook();
            cout << endl;
        }
        else if (choice == 3)
        {
            collegeLibrary.listAllUsers();
            cout << endl;
        }
        else
        {
            cout << "Your choice is invalid. Please try again" << endl;
        }
    } while (choice != 5);
}