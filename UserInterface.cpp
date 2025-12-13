#include "UserInterface.h"

void UserInterface::printAdminMenu(){
    std::cout << std::string(54, '-') + '\n'
              << "| Welcome to the Campus Resource Reservation System! |\n"
              << std::string(54, '-') + '\n'
              << "\n"
              << "Please select an option: \n"
              << "1. Create Reservation\n"
              << "2. Cancel Reservation\n"
              << "3. View Current Reservations\n"
              << "4. List Available Resources\n"
              << "5. Add Resource\n"
              << "6. Remove Resource\n"
              << "7. Edit resource\n"
              << "8. Exit\n";
}
void UserInterface::printStudentMenu(){
    std::cout << std::string(54, '-') + '\n'
              << "| Welcome to the Campus Resource Reservation System! |\n"
              << std::string(54, '-') + '\n'
              << "\n"
              << "Please select an option: \n"
              << "1. Create Reservation\n"
              << "2. Cancel Reservation\n"
              << "3. View Current Reservations\n"
              << "4. List Available Resources\n"
              << "5. Exit\n";
}
