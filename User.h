// User.h
// Manages userID, username and admin status

#pragma once
#include <iostream>
#include <string>
class User
{
protected:
    int userId;
    bool adminStatus;
    std::string username;

public:
    User();
    User(const std::string &username);
    User(const std::string &username, bool adminStatus);
    bool isAdmin() const;
    std::string getUsername() const;
};

class Admin : public User
{
public:
    Admin();
    Admin(std::string);
};

class Student : public User
{
public:
    Student();
    Student(std::string);
};

static int userIdCount = 0;