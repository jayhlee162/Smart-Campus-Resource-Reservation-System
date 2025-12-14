#include "FileWriter.h"
#include <fstream>
#include <sstream>

// -------------------- RESOURCES --------------------
bool FileWriter::saveResources(const std::vector<Resource>& resources,
                               const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) return false;

    for (const auto& r : resources) {
        outFile << r.getId() << ","
                << r.getName() << ","
                << r.getType() << ","
                << r.getCapacity() << "\n";
    }

    outFile.close();
    return true;
}

bool FileWriter::loadResources(std::vector<Resource>& resources,
                               const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) return false;

    resources.clear();
    std::string line;

    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string id, name, type, capacityStr;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, type, ',');
        getline(ss, capacityStr, ',');

        int capacity = std::stoi(capacityStr);
        resources.emplace_back(id, name, type, capacity);
    }

    inFile.close();
    return true;
}

// -------------------- RESERVATIONS --------------------
bool FileWriter::saveReservations(const std::vector<Reservation>& reservations,
                                  const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) return false;

    for (const auto& r : reservations) {
        outFile << r.getReservationId() << ","
                << r.getUserId() << ","
                << r.getResourceId() << ","
                << r.getStartTime() << ","
                << r.getEndTime() << "\n";
    }

    outFile.close();
    return true;
}

bool FileWriter::loadReservations(std::vector<Reservation>& reservations,
                                  const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) return false;

    reservations.clear();
    std::string line;

    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string resId, userId, resourceId, start, end;

        getline(ss, resId, ',');
        getline(ss, userId, ',');
        getline(ss, resourceId, ',');
        getline(ss, start, ',');
        getline(ss, end, ',');

        reservations.emplace_back(resId, userId, resourceId, start, end);
    }

    inFile.close();
    return true;
}

// -------------------- USERS --------------------
bool FileWriter::saveUsers(const std::vector<User>& users,
                           const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) return false;

    for (const auto& u : users) {
        outFile << u.getUsername() << ","
                << u.isAdmin() << "\n";
    }

    outFile.close();
    return true;
}

bool FileWriter::loadUsers(std::vector<User>& users,
                           const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) return false;

    users.clear();
    std::string line;

    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string username, adminFlag;

        getline(ss, username, ',');
        getline(ss, adminFlag, ',');

        bool isAdmin = (adminFlag == "1");
        users.emplace_back(username, isAdmin);
    }

    inFile.close();
    return true;
}
