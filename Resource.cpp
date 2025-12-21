#include "Resource.h"
Resource::Resource(int id, std::string name, ResourceType type, int capacity){
    resourceId = id;
    resourceName = name;
    this->type = type;
    this->capacity = capacity; 
}
int Resource::getId() const {
    return resourceId;
}

std::string Resource::getName() const{
    return resourceName;
}

ResourceType Resource::getType() const {
    return type;
}

int Resource::getCapacity() const {
    return capacity;
}

std::string Resource::typeToString (ResourceType type) const {
    switch (type) {
        case StudyRoom:
            return "Study Room";
        case LabEquipment:
            return "Lab Equipment";
        case PracticeRoom:
            return "Practice Room";
        case SportsCourt:
            return "Sports Court";
        case Tutoring:
            return "Tutoring";
        default: 
            return "Unknown";
    }
}

void Resource::print(std::ostream &out) const {
    out << "Resource ID: " << this->resourceId << "\n" << "Name: " << this->resourceName << "\n" << "Capactiy: " << this->capacity << "\n";
}

std::ostream &operator<<(std::ostream &out, const Resource &resource){
    resource.print(out);
    return out;
}

bool Resource::operator==(const Resource &other){
    if(this->resourceName == other.resourceName) {
        return true;
    }
    else {
        return false;
    }
}