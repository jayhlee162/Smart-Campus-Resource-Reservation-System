// School.h
// Main system controller that handles creating/editing reservations, resources, calling file load,

#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include "User.h"
#include "Resource.h"
#include "Reservation.h"
#include "FileWriter.h"

class School
{
private:
    std::vector<User> users;
    std::vector<Resource> resources;
    std::vector<Reservation> reservations;

public:
    User login();
    void loadAll();
    void saveAll();

    Reservation &createReservation(int, int, int, std::string);
    bool cancelReservation(int reservationId);
    void printAllReservations(User);
    void printResources();
    void addResource(std::string resourceName, ResourceType resourceType, int capacity);
    bool removeResource(int resourceIndex);
    void editResource();
    void initializeResources();
    std::vector<Resource>& getResources();

    bool isReservedAlready(int resourceId, int timeSlot, int dayIndex) const;
};
