// Resource.h
// Manages resource information

#pragma once
#include <iostream>
#include <string>

enum ResourceType
{
    Unknown,
    StudyRoom,
    LabEquipment,
    PracticeRoom,
    SportsCourt,
    Tutoring
};

class Resource
{
private:
    int resourceId;
    ResourceType type;
    std::string resourceName;
    int capacity;

public:
    Resource(int id, std::string name, ResourceType type, int capacity);
    int getId() const;
    std::string getName() const;
    void setName(std::string name);
    ResourceType getType() const;
    int getCapacity() const;
    std::string typeToString(ResourceType type) const;
    void print(std::ostream &out) const;
    friend std::ostream &operator<<(std::ostream &, const Resource &);
    bool operator==(const Resource &other);
};