#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "School.h"


class UserInterface {
    private:
    public:
        static bool isInputJustNumbers(std::string input);
        static int getIntFromUser();
        void printAdminMenu();
        void printStudentMenu();
        void waitForEnter();

        void createReservation(User user, School school);
        void cancelReservation(User user, School school);
};
