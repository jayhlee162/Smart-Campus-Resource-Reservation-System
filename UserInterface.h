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

        void createReservationInteractive(User& user, School& school);
        void cancelReservationInteractive(User& user, School& school);
        void addResourceInteractive(School& school);
};
