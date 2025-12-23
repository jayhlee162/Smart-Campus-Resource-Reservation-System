#include "UserInterface.h"


/*
    Prints available options to users with admin status.
*/
void UserInterface::printAdminMenu()
{
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


/*
    Prints available options to users with student status.
*/
void UserInterface::printStudentMenu()
{
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


/*
    Interactive prompt that lets a user either login, or create a new account
    and automatically login to the new account.
*/
User UserInterface::loginInteractive(School& school)
{
    std::string username = " ";
    bool reEnter = false;
    bool tryAgain = false;
    int selection;
    int adminStatus{0};
    std::vector<User> users = school.getUsers();

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
                if (users[i].getUsername() == username)
                {
                    return users[i];
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
                    if (users[i].getUsername() == username)
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


/*
    Interactive prompt that lets user create a new reservation. If the chosen
    resource is already reserved at the chosen time and hour, the user is informed 
    and no reservation is made.
*/
void UserInterface::createReservationInteractive(User &user, School &school)
{
    int timeSlot{0};
    int dayIndex;
    int resourceId{0};

    std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::cout << "Enter day:\n";
    for (int i = 0; i < 7; i++)
    {
        std::cout << i + 1 << ") " << days[i] << "\n";
    }
    dayIndex = getIntFromUser() - 1;

    std::cout << "Enter the time of hour you would like your reservation to be(0 - 23): ";
    timeSlot = getIntFromUser();

    std::cout << "Select which resource to reserve:\n";
    for (int i = 0; i < school.getResources().size(); i++)
    {
        std::cout << i + 1 << ") " << school.getResources()[i].getName() << "\n";
    }

    resourceId = getIntFromUser() - 1;
    
    if (school.isReservedAlready(resourceId, timeSlot, dayIndex))
    {
        std::cout << "This resource is already reserved at this time.\n";
        waitForEnter();
        return;
    }

    Reservation res = school.createReservation(resourceId, timeSlot, dayIndex, user.getUsername());

    std::cout << "Created a reservation!\n\n";
    Reservation::printReservationHeader();
    res.printReservation();

    waitForEnter();
}


/*
    Interactive prompt that allows a user to cancel a reservation. When a
    reservation is cancelled, its "cancelled property" is set to true but
    it remains in the reservations vector so that the id still corresponds to
    the index. If someone then tries to make a new reservation with the same
    resource and time it will work.
*/
void UserInterface::cancelReservationInteractive(User &user, School &school)
{
    // TODO: check if user is admin, if not they can only delete their own reservations
    int reservationId{0};

    std::cout << "Enter the ID of the reservation you would like to cancel:\n";
    reservationId = getIntFromUser();
    if (school.cancelReservation(reservationId))
    {
        std::cout << "Reservation cancelled. ";
    }
    else
    {
        std::cout << "Error: no reservation with that ID. ";
    }

    waitForEnter();
}


/*
    Interactive prompt that allows a user to add a new resource to the school.
*/
void UserInterface::addResourceInteractive(School &school)
{
    std::string resourceName;

    std::cout << "Enter resource name: ";
    std::getline(std::cin, resourceName);

    // type and capacity are hardcoded to simple defaults
    school.addResource(resourceName, ResourceType(), 1);

    std::cout << "Resource added successfully.\n";
}


/*
    Interactive prompt that allows a user to remove a resource to the school.
*/
void UserInterface::removeResourceInteractive(School &school)
{
    int resourceIndex;

    school.printResources();
    std::cout << "Enter the ID of the resource to remove: ";
    resourceIndex = getIntFromUser();
    
    if (school.removeResource(resourceIndex)) {
        std::cout << "Resource removed successfully.\n";
    }

    else
    {
        std::cout << "Invalid resource ID.\n";
    }
    
}

/*Interactive prompt that allows user to edit a give resources information*/
void UserInterface::editResourceInteractive(School& school)
{
    int index;
    std::string newName;
    std::vector<Resource> resources = school.getResources();

    school.printResources();
    std::cout << "Enter the ID of the resource to edit: ";
    index = getIntFromUser();

    if (index < 0 || index >= resources.size())
    {
        std::cout << "Invalid resource ID. ";
        waitForEnter();
        return;
    }

    std::cout << "Enter new resource name: ";
    std::getline(std::cin, newName);

    // replace resource with updated name
    resources[index].setName(newName);

    std::cout << "Resource updated successfully. ";
    waitForEnter();
}


/* ------------------ UTILITY FUNCTIONS ------------------*/

/*
    Utility function to check if string only contains digits.
*/
bool UserInterface::isInputJustNumbers(std::string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

/*
    Utility function to get an int from user that reprompts the user if
    invalid characters are input.
*/
int UserInterface::getIntFromUser()
{
    std::string input{};
    while (true)
    {
        std::getline(std::cin, input);
        if (isInputJustNumbers(input))
        {
            return stoi(input);
        }
        std::cout << "Input must be a number. Try again: ";
    }
}


/*
    Utility function to prompt the user to press enter. Helps with program flow
    and user experience.
*/
void UserInterface::waitForEnter()
{
    std::cout << "Press enter to continue. . .";

    std::string input;
    std::getline(std::cin, input);
    std::cout << "\n";
}