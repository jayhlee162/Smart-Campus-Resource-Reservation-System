// UserInterface.h
// Controller for menu between users and functions

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "School.h"

class UserInterface
{
private:
public:
    void printAdminMenu();
    void printStudentMenu();
    User loginInteractive(School& school);
    User loginExistingUser(std::vector<User>& users, bool& reEnter);

    void createReservationInteractive(User &user, School &school);
    void cancelReservationInteractive(User &user, School &school);
    void addResourceInteractive(School &school);
    void removeResourceInteractive(School &school);
    void editResourceInteractive(School &school);

    static bool isInputJustNumbers(std::string input);
    static int getIntFromUser();
    void waitForEnter();
};
