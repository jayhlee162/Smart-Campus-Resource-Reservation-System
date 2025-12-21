#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "School.h"


class UserInterface {
    private:
    public:
        bool isInputJustNumberz(std::string input);
        int getIntFromUser();
        void printAdminMenu();
        void printStudentMenu();
        void waitForEnter();
        void createReservation(User user, School school);
};
