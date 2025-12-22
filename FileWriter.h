// FileWriter
// Manages file save/load and data persistence

#pragma once
#include <vector>
#include <string>
#include "Resource.h"
#include "Reservation.h"
#include "User.h"

class FileWriter
{
public:
    // RESOURCE FILES
    static bool saveResources(const std::vector<Resource> &resources,
                              const std::string &filename);
    static bool loadResources(std::vector<Resource> &resources,
                              const std::string &filename);

    // RESERVATION FILES
    static bool saveReservations(const std::vector<Reservation> &reservations,
                                 const std::string &filename);
    static bool loadReservations(std::vector<Reservation> &reservations,
                                 const std::string &filename);

    // USER FILES (optional but good to have)
    static bool saveUsers(const std::vector<User> &users,
                          const std::string &filename);
    static bool loadUsers(std::vector<User> &users,
                          const std::string &filename);

    static ResourceType strToResourceType(std::string);
};
