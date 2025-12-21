#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "Resource.h"
#include "Reservation.h"
#include "FileWriter.h"
class School {
    private:
        std::vector<User> users;
        std::vector<Resource> resources;
        std::vector<Reservation> reservations;
    public:
        User login();
        void loadAll();
        void saveAll();
        
        void createReservation(User);
        void cancelReservation(User);
        void printReservation(User);
        void printResources();
        void addResource();
        void removeResource();
        void editResource();
        void initializeResources();
};
