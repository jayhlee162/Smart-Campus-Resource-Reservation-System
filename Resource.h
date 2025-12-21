#pragma once
#include <iostream>
#include <string>

enum ResourceType{Unknown, StudyRoom, LabEquipment, PracticeRoom, SportsCourt, Tutoring};

class Resource {
    private:
        int resourceId;
        ResourceType type;
        std::string resourceName;
        int capacity;
    public:
        Resource(int id, std::string name, ResourceType type, int capacity);
        int getId() const;
        std::string getName() const;
        ResourceType getType() const;
        int getCapacity() const;
        std::string typeToString (ResourceType type) const;
};