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
        std::string idStr, nameStr, typeStr, capacityStr;

        getline(ss, idStr, ',');
        getline(ss, nameStr, ',');
        getline(ss, typeStr, ',');
        getline(ss, capacityStr, ',');

        int capacity = std::stoi(capacityStr);
        int id = std::stoi(idStr);
        ResourceType type = strToResourceType(typeStr);
        resources.emplace_back(id, nameStr, type, capacity);
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
                << r.getUsername() << ","
                << r.getResourceId() << ","
                << r.getTimeSlot() << ","
                << r.getDayIndex() << "\n";
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
        std::string resIdStr, username, resourceIdStr, timeStr, dayStr;

        getline(ss, resIdStr, ',');
        getline(ss, username, ',');
        getline(ss, resourceIdStr, ',');
        getline(ss, timeStr, ',');
        getline(ss, dayStr, ',');

        int rsvId = std::stoi(resIdStr);
        int rscId = std::stoi(resourceIdStr);
        int timeSlot = std::stoi(timeStr);
        int dayIndex = std::stoi(dayStr);

        reservations.emplace_back(rsvId, rscId, timeSlot, dayIndex, username);
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

ResourceType FileWriter::strToResourceType(std::string typeName){
    if(typeName == "Study Room") {return StudyRoom;}
    if(typeName == "Lab Equipment") {return LabEquipment;}
    if(typeName == "Practice Room") {return PracticeRoom;}
    if(typeName == "Sports Court") {return SportsCourt;}
    if(typeName == "Tutoring") {return Tutoring;}
    else {return Unknown;}
}
