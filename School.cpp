#include "School.h"
#include <cctype>


bool isInputJustNumberz(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            return false;
        }
    }
    return true;
}


int getIntFromUser() {
    std::string input{};
    while(true) {
        std::getline(std::cin, input);
        if (isInputJustNumberz(input)) {
            return stoi(input);
        }
        std::cout << "Invalid input. Try again: ";
    } 
}


void waitForEnter() {
    std::cout << "Press enter to continue. . .";

    std::string input;
    std::getline(std::cin, input);
    std::cout << "\n";
}

std::vector<Resource> School::getResources() {
    return resources;
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
    int selection;
    int adminStatus{0};

    do
    {
        reEnter = false;
        std::cout << "Please select an option\n"
                  << "1. User Login\n"
                  << "2. Create account\n";

        selection = getIntFromUser();

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
                adminStatus = getIntFromUser();

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

Reservation* School::createReservation(int resourceId, int timeSlot, int dayIndex, std::string username){
    Reservation* res = new Reservation(resourceId, timeSlot, dayIndex, username);
    reservations.push_back(*res);
    return res;
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
    std::cout << "Available Resources:\n";
    for (int i = 0; i < resources.size(); i++)
    {
        std::cout << i << ") " << resources[i].getName() << "\n";
    }
}

void School::addResource()
{
    std::string resourceName;
    int id = resources.size();

    std::cout << "Enter resource name: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, resourceName);

    // type and capacity are hardcoded to simple defaults
    resources.emplace_back(id, resourceName, ResourceType(), 1);

    std::cout << "Resource added successfully.\n";
}


void School::removeResource()
{
    int resourceIndex;

    printResources();
    std::cout << "Enter the ID of the resource to remove: ";
    std::cin >> resourceIndex;

    if (resourceIndex >= 0 && resourceIndex < resources.size())
    {
        resources.erase(resources.begin() + resourceIndex);
        std::cout << "Resource removed successfully.\n";
    }
    else
    {
        std::cout << "Invalid resource ID.\n";
    }
}

void School::editResource()
{
    int index;
    std::string newName;

    printResources();
    std::cout << "Enter the ID of the resource to edit: ";
    std::cin >> index;

    if (index < 0 || index >= resources.size())
    {
        std::cout << "Invalid resource ID.\n";
        return;
    }

    std::cout << "Enter new resource name: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, newName);

    int id = resources[index].getId();

    // replace resource with updated name
    resources[index] = Resource(id, newName, ResourceType(), 1);

    std::cout << "Resource updated successfully.\n";
}

void School::initializeResources(){
    if(resources.empty()){
        resources.emplace_back(1, "Study Room", StudyRoom, 12);
        resources.emplace_back(1, "Lab Equipment", LabEquipment, 4);
        resources.emplace_back(1, "Practice Room", PracticeRoom, 20);
        resources.emplace_back(1, "Sports Court", SportsCourt, 30);
        resources.emplace_back(1, "Tutoring", Tutoring, 2);
        resources.emplace_back(1, "Unknown", Unknown, 1000);
    }
}
