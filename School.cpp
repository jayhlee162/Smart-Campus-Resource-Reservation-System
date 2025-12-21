#include "School.h"

void waitForEnter() {
    std::cout << "Press enter to continue. . .";

    std::string input;
    std::getline(std::cin, input);
    std::cout << "\n";
}

void School::loadAll()
{
    FileWriter::loadUsers(users, "SCRRSusers.csv");
    FileWriter::loadReservations(reservations, "SCRRSreservations.csv");
    FileWriter::loadResources(resources, "SCRRSresources.csv");
}
void School::saveAll()
{
    FileWriter::saveUsers(users, "SCRRSusers.csv");
    FileWriter::saveReservations(reservations, "SCRRSreservations.csv");
    FileWriter::saveResources(resources, "SCRRSresources.csv");
}

User School::login()
{
    std::string username = " ";
    bool reEnter = false;
    bool tryAgain = false;
    int selection = 0;
    int adminStatus;

    do
    {
        reEnter = false;
        std::cout << "Please select an option\n"
                  << "1. User Login\n"
                  << "2. Create account\n";
        std::cin >> selection;
        std::cin.ignore(1000, '\n');

        if (selection == 1)
        {
            std::cout << "Enter username: ";
            std::getline(std::cin, username);

            // returns user if username exists
            for (int i = 0; i < users.size(); i++)
            {
                if (this->users[i].getUsername() == username)
                {
                    return this->users[i];
                }
            }
            std::cout << "Username incorrect or does not exist. Please re-enter or create an account.\n\n";
            reEnter = true;
        }
        else if (selection == 2)
        {
            do
            {
                tryAgain = false;
                std::cout << "Username: ";
                std::getline(std::cin, username);
                for (int i = 0; i < users.size(); i++)
                {
                    if (this->users[i].getUsername() == username)
                    {
                        std::cout << "Username already taken. Please try again\n";
                        tryAgain = true;
                    }
                }
            } while (tryAgain);

            do
            {
                std::cout << "Please select user type:\n"
                          << "1. Admin\n"
                          << "2. Student\n";
                std::cin >> adminStatus;

                if (adminStatus == 1)
                {
                    users.emplace_back(username, true);
                }
                else if (adminStatus == 2)
                {
                    users.emplace_back(username, false);
                }
                else
                {
                    std::cout << "Invalid selection, please try again.\n";
                }
            } while (adminStatus < 1 || adminStatus > 2);

            return users.back();
        }
        else
        {
            std::cout << "invalid selection\n";
            reEnter = true;
        }

    } while (reEnter);

    return User();
}

void School::createReservation(User user){
    // TODO: add logic to check for existing reservations. cancelled ones can be overwritten
    int timeSlot{0};
    int dayIndex{0};
    int resourceId{0};
    
    std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::cout << "Enter day:\n";
    for (int i = 0; i < 7; i++) {
        std::cout << i+1 << ") " << days[i] << "\n";
    }
    std::cin >> dayIndex;
    
    std::cout << "Enter the hour of your reservation (0 - 23): ";
    std::cin >> timeSlot;
    
    std::cout << "Select which resource to reserve:\n";
    for (int i = 0; i < resources.size(); i++) {
        std::cout << i+1 << ") " << resources[i].getName() << "\n";
    }
    
    std::cin >> resourceId;

    Reservation* res = new Reservation(resourceId-1, timeSlot, dayIndex-1, user.getUsername());
    reservations.push_back(*res);
    
    std::cout << "Created a reservation!\n\n";
    res->printReservation();
    
    waitForEnter();
}

void School::cancelReservation(User)
{
    int reservationId{0};

    std::cout << "Enter the ID of the reservation you would like to cancel:\n";
    std::cin >> reservationId;
    reservations[reservationId].cancelReservation();
    std::cout << "Reservation cancelled.";

    waitForEnter();
}

void School::printReservation(User)
{
    Reservation::printReservationHeader();
    for (int i = 0; i < reservations.size(); i++) {
        reservations[i].printReservation();
    }
    std::cout << '\n';
    
    waitForEnter();
}

void School::printResources()
{
    std::cout << "running printResources\n";
}

void School::addResource()
{
    std::cout << "running addResource\n";
}
void School::removeResource()
{
    std::cout << "running removeResource\n";
}
void School::editResource()
{
    std::cout << "running editResource\n";
}


