#include "School.h"
#include <cctype>


std::vector<Resource>& School::getResources()
{
    return resources;
}


std::vector<User>& School::getUsers()
{
    return users;
}

/*allows main to call all loading functions at once, cleaner main function and ensures proper loading*/
void School::loadAll()
{
    FileWriter::loadUsers(users, "SCRRSusers.csv");
    FileWriter::loadReservations(reservations, "SCRRSreservations.csv");
    FileWriter::loadResources(resources, "SCRRSresources.csv");
}

/*allows main to save all data at once, cleaner main function and ensures proper loading*/
void School::saveAll()
{
    FileWriter::saveUsers(users, "SCRRSusers.csv");
    FileWriter::saveReservations(reservations, "SCRRSreservations.csv");
    FileWriter::saveResources(resources, "SCRRSresources.csv");
}


/* 
    Used for creating default resources when program starts up, so that
    they don't have to be manually input each time.
*/
void School::initializeResources(){
    if(resources.empty()){
        resources.emplace_back(0, "Study Room", StudyRoom, 12);
        resources.emplace_back(1, "Lab Equipment", LabEquipment, 4);
        resources.emplace_back(2, "Practice Room", PracticeRoom, 20);
        resources.emplace_back(3, "Sports Court", SportsCourt, 30);
        resources.emplace_back(4, "Tutoring", Tutoring, 2);
        resources.emplace_back(5, "Unknown", Unknown, 1000);
    }
}


/*
    Checks if a resource has already been reserved by comparing the id, day and
    time to existing reservations. Ignores cancelled reservations.
*/
bool School::isReservedAlready(int resourceId, int timeSlot, int dayIndex) const {

    for (int i = 0; i < reservations.size(); i++) {

        if (reservations[i].isCancelled()) continue;

        if (reservations[i].getResourceId() == resourceId && 
            reservations[i].getTimeSlot() == timeSlot &&
            reservations[i].getDayIndex() == dayIndex) {

                return true;

            }
    }

    return false;
}


/* 
    Removes a resource at the provided index. Returns true if successful, and false
    if the index is out of bounds.
*/
bool School::removeResource(int resourceIndex)
{
    if (resourceIndex >= 0 && resourceIndex < resources.size())
    {
        resources.erase(resources.begin() + resourceIndex);
        return true;
    }

    return false;
}

/*creates a reservation object attached to username and resource at chosen date and time, returns created reservation*/
Reservation& School::createReservation(int resourceId, int timeSlot, int dayIndex, std::string username)
{
    Reservation res{resourceId, timeSlot, dayIndex, username};

    reservations.push_back(res);
    return reservations.back();
}

/*removes reservation corresponding with reservationID from vector and returns true if successful, false if unsuccessful*/
bool School::cancelReservation(int reservationId)
{
    if (reservationId < reservations.size() && reservationId >=0) {
        reservations[reservationId].cancelReservation();
        return true;
    }
    return false;
}

/*calls printReservationHeader for formatting and prints all non-cancelled reservations*/
void School::printAllReservations(User)
{
    Reservation::printReservationHeader();
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].isCancelled()) continue;
        reservations[i].printReservation();
    }

    std::cout << '\n';
}

/*prints name of all resources available for reserving at the school*/
void School::printResources()
{
    std::cout << "Available Resources:\n";
    for (int i = 0; i < resources.size(); i++)
    {
        std::cout << i << ") " << resources[i].getName() << "\n";
    }
}

/*allows admin to create a new resource by creating new resource object with taken name, type, and capacity, adds to resources vector*/
void School::addResource(std::string resourceName, ResourceType resourceType, int capacity)
{
    int id = resources.size();
    resources.emplace_back(id, resourceName, resourceType, capacity);
}

/*takes a resource id and allows admin to change information about corresponding resource through user input*/
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


