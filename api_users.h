#pragma once

#include <iostream>
#include <string>
#include "model_users.h"
#include "database_conn.h"
#include "user_database.h"
#include "OpenDataBase.h"
#include "api_products.h"
using namespace std;

void CreateUser(sqlite3* db) {
    Person user = {};
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Your Username: ";
    getline(cin, user.Name);
    cout << "Enter Your Password: ";
    getline(cin, user.Password);
    cout << "Enter Your Phone Number: ";
    getline(cin, user.PhoneNumber);
    cout << "Enter Your Location: ";
    getline(cin, user.Location);
    cout << endl;
    saveUser(db, user);
}

void Greeting(sqlite3* db) {
    int userActionChoice = 0;
    cout << "Welcome to the online super-market" << endl;
    cout << "To Edit Your Personal Info Press 1" << endl;
    cout << "To View The Products Menu Press 2" << endl;
    cout << "To Make An Order Press 3" << endl;
    cout << "To Review Your Order Press 4" << endl;
    cout << "To Modify Your Order Press 5" << endl;
    cout << "To Display The Order Total Price Press 6" << endl;
    cout << "To Logout From The App Press 7" << endl;
    cout << "(For Admins Only) To Create a new Product press 8" << endl;
    cout << "(For Admins Only) To Create a new category press 9" << endl;

    cin >> userActionChoice;

    switch (userActionChoice) {
    case 1:
        cout << "You Chose to enter user data" << endl;
        CreateUser(db);
        break;

    case 2:
        cout << "You entered 2" << endl;
        break;

    case 3:
        cout << "You Chose to make an order" << endl;
        Order(db);
        break;

    case 4:
        cout << "You Chose to review your order" << endl;
        ViewUserOrders(db);
        break;

    case 5:
        cout << "You chose to edit your order" << endl;
        EditOrder(db);
        break;

    case 6:
        cout << "You entered 6" << endl;
        break;

    case 7:
        cout << "You entered 7" << endl;
        break;
    
    case 8:
        cout << "You Chose to create a product" << endl;
        CreateProduct(db);
        break;

    case 9:
        cout << "You Chose to create a category" << endl;
        CreateProductCategory(db);
        break;

     case 10:
        cout << "You Chose to view categories" << endl;
        ViewCategories(db);
        break;

    default:
        cout << "Please Only Select A Number From The Menu" << endl;
        cout << endl;
        Greeting(db);
    }

}

int editInformation()
{

    Person person;
    int choice, age;
    string name, password, phoneNumber, location;

    cout << "=====================================\n";
    cout << "choice 1 : edit your name\n";
    cout << "choice 2 : edit your password\n";
    cout << "choice 3 : edit your phone number\n";
    cout << "choice 4 : edit your location\n";
    cout << "choice 5 : edit your age\n";
    cout << "=====================================\n";
    cout << "Enter your choice\n";

    cin >> choice;

    switch (choice)
    {
    case 1 :
        cout << "You're editing your name\n";
        cout << "Enter your name\n";

        getline(cin, name);

        person.Name = name;
            // edit the name in the database
         break;

    case 2 : 
        cout << "You're editing your password\n";
        cout << "Enter your new password\n";

        getline(cin, password);

        person.Password = password;
        // edit the password
        break;

    case 3 :
        cout << "You're editing your phone number\n";
        cout << "Enter your new phone number\n";

        getline(cin, phoneNumber);

        person.PhoneNumber = phoneNumber;
        // edit the phone number
        break;

    case 4 :
        cout << "You're editing your location\n";
        cout << "Enter your new location\n";

        getline(cin, location);

        person.Location = location;
        // edit the location

        break;

    case 5 : 
        cout << "You're editing your age\n";
        cout << "Enter your new age\n";

        cin >> age;

        person.Age = age;
    default:
        break;
    }

    return 0;
}


int logoOut()
{
    cout << "logged out!";

    return 0;
}





