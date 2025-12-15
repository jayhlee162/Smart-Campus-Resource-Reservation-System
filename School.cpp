#include "School.h"

void School::loadAll(){
    FileWriter::loadUsers(users, "SCRRSusers.csv");
    FileWriter::loadReservations(reservations, "SCRRSreservations.csv");
    FileWriter::loadResources(resources,"SCRRSresources.csv");
}
void School::saveAll(){
    FileWriter::saveUsers(users, "SCRRSusers.csv");
    FileWriter::saveReservations(reservations, "SCRRSreservations.csv");
    FileWriter::saveResources(resources,"SCRRSresources.csv");
}

User School::login(){
    std::string username = " ";
    bool reEnter = false;
    bool tryAgain = false;
    int selection = 0;
    int adminStatus;

    do{
        reEnter = false;
        std::cout << "Please select an option\n"
                  << "1. User Login\n"
                  << "2. Create account\n";
        std::cin >> selection;
        std::cin.ignore(1000, '\n');

        if (selection == 1){
            std::cout << "Enter username: ";
            std::getline(std::cin, username);

            //returns user if username exists
            for (int i = 0; i < users.size(); i++){
                if (this->users[i].getUsername() == username){
                    return this->users[i];
                }
            }
            std::cout << "Username incorrect or does not exist. Please re-enter or create an account.\n\n";
            reEnter = true;
        }
        else if (selection == 2){
            do{
                tryAgain = false;
                std::cout << "Username: ";
                std::getline(std::cin, username);
                for (int i = 0; i < users.size(); i++){
                    if (this->users[i].getUsername() == username){
                        std::cout << "Username already taken. Please try again\n";
                        tryAgain = true;
                    }
                }
            }while(tryAgain);

            do{
                std::cout << "Please select user type:\n"
                          << "1. Admin\n"
                          << "2. Student\n";
                std::cin >> adminStatus;

                if (adminStatus == 1){
                    users.emplace_back(username, true);
                }
                else if (adminStatus == 2){
                    users.emplace_back(username, false);
                }
                else{
                    std::cout << "Invalid selection, please try again.\n";
                }
            }while (adminStatus < 1 || adminStatus > 2);

            return users.back();
        }
        else{
            std::cout << "invalid selection\n";
            reEnter = true;
        }

    }while(reEnter);

    return User();
}

void School::createReservation(User user){
    Reservation* res = new Reservation();
    reservations.push_back(*res);
}
void School::cancelReservation(User){
    std::cout << "running cancelReservation\n";
}
void School::printReservation(User){
    std::cout << "running printReservation\n";
}
void School::printResources(){
    std::cout << "running printResources\n";
}
void School::addResource(){
    std::cout << "running addResource\n";
}
void School::removeResource(){
    std::cout << "running removeResource\n";
}
void School::editResource(){
    std::cout << "running editResource\n";
}