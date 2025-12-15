#include "user.h"

User::User(){
    this->username = " ";
    this->adminStatus = false;
}
User::User(const std::string& username){
    this->username = username;
    this->adminStatus = false;
}
User::User(const std::string& username, bool adminStatus){
    this->username = username;
    this->adminStatus = adminStatus;
}
bool User::isAdmin() const {
    if(adminStatus){return true;}
    else{return false;}
}

std::string User::getUsername() const {
    return username;
}

Admin::Admin(){
    this->userId += userIdCount;
    this->adminStatus = 1;
}

Admin::Admin(std::string username){
    this->userId += userIdCount;
    this->username = username;
    this->adminStatus = 1;
}

Student::Student(){
    this->userId += userIdCount;
    this->adminStatus = 0;
}

Student::Student(std::string username){
    this->userId += userIdCount;
    this->username = username;
    this->adminStatus = 0;
}