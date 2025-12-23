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

void Resource::setName(std::string newName)
{
    resourceName = newName;
}

ResourceType Resource::getType() const {
    return type;
}

int Resource::getCapacity() const {
    return capacity;
}

/*allows for simple output by hardcoding resource type names to printable strings*/
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

/*passes outstream object data as a fully comprehensive string*/
void Resource::print(std::ostream &out) const {
    out << "Resource ID: " << this->resourceId << "\n" << "Name: " << this->resourceName << "\n" << "Capactiy: " << this->capacity << "\n";
}

/*allows for simple object output*/
std::ostream &operator<<(std::ostream &out, const Resource &resource){
    resource.print(out);
    return out;
}

/*allows for comparison of a resource to another resource*/
bool Resource::operator==(const Resource &other){
    if(this->resourceName == other.resourceName) {
        return true;
    }
    else {
        return false;
    }
}