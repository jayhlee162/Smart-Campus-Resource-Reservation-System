#include "UserInterface.h"


bool UserInterface::isInputJustNumbers(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            return false;
        }
    }
    return true;
}


int UserInterface::getIntFromUser() {
    std::string input{};
    while(true) {
        std::getline(std::cin, input);
        if (isInputJustNumbers(input)) {
            return stoi(input);
        }
        std::cout << "Input must be a number. Try again: ";
    } 
}


void UserInterface::waitForEnter() {
    std::cout << "Press enter to continue. . .";

    std::string input;
    std::getline(std::cin, input);
    std::cout << "\n";
}


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

void UserInterface::createReservation(User user, School& school){
    // TODO: add logic to check for existing reservations. cancelled ones can be overwritten
    int timeSlot{0};
    int dayIndex;
    int resourceId{0};
    
    std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::cout << "Enter day:\n";
    for (int i = 0; i < 7; i++) {
        std::cout << i+1 << ") " << days[i] << "\n";
    }
    dayIndex = getIntFromUser();
    
    std::cout << "Enter the time of hour you would like your reservation to be(0 - 23): ";
    timeSlot = getIntFromUser();
    
    std::cout << "Select which resource to reserve:\n";
    for (int i = 0; i < school.getResources().size(); i++) {
        std::cout << i+1 << ") " << school.getResources()[i].getName() << "\n";
    }
    
    resourceId = getIntFromUser();

    Reservation res = school.createReservation(resourceId-1, timeSlot, dayIndex-1, user.getUsername());
    
    std::cout << "Created a reservation!\n\n";
    res.printReservation();
    
    waitForEnter();
}

void UserInterface::cancelReservation(User user, School& school)
{
    // TODO: check if user is admin, if not they can only delete their own reservations
    int reservationId{0};

    std::cout << "Enter the ID of the reservation you would like to cancel:\n";
    reservationId = getIntFromUser();
    school.cancelReservation(reservationId);
    std::cout << "Reservation cancelled.";

    waitForEnter();
}