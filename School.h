#pragma once
#include <iostream>
#include <vector>
#include <optional>
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
        
        std::optional<Reservation> createReservation(int, int, int, std::string);
        void cancelReservation(int reservationId);
        void printAllReservations(User);
        void printResources();
        void addResource();
        void removeResource();
        void editResource();
        void initializeResources();
        std::vector<Resource> getResources();
        
        bool isReservedAlready(int resourceId, int timeSlot, int dayIndex) const;
};
