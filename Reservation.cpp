#include "Reservation.h"
#include <iostream>
#include <iomanip>

int Reservation::reservationIdCount = 0;

Reservation::Reservation() : resourceId(-1), timeSlot(-1), dayIndex(-1) {}
Reservation::Reservation(int id, int t, int d, const std::string& username) : resourceId(id), timeSlot(t), dayIndex(d), username(username), reservationId(reservationIdCount++) {}
Reservation::Reservation(int rsvId, int rscId, int time, int day, const std::string &u) : reservationId(rsvId), resourceId(rscId), timeSlot(time), dayIndex(day), username(u) {}

int Reservation::getResourceId() const
{
    return resourceId;
}
int Reservation::getTimeSlot() const
{
    return timeSlot;
}
int Reservation::getDayIndex() const
{
    return dayIndex;
}
int Reservation::getReservationId() const
{
    return reservationId;
}

const std::string &Reservation::getUsername() const
{
    return username;
}

Reservation &Reservation::setResourceId(int id)
{
    resourceId = id;
    return *this;
}
Reservation &Reservation::setTimeSlot(int t)
{
    timeSlot = t;
    return *this;
}
Reservation &Reservation::setDayIndex(int d)
{
    dayIndex = d;
    return *this;
}

void Reservation::cancelReservation() {
    cancelled = true;
}

void Reservation::printReservationHeader() {
    std::cout << std::right;
    std::cout << std::setw(20) << "reservationId";
    std::cout << std::setw(20) << "timeSlot";
    std::cout << std::setw(20) << "dayIndex";
    std::cout << std::setw(20) << "username" << "\n";
}

void Reservation::printReservation() {
    std::cout << std::right;
    std::cout << std::setw(20) << reservationId;
    std::cout << std::setw(20) << timeSlot;
    std::cout << std::setw(20) << dayIndex;
    std::cout << std::setw(20) << username << "\n";
}

bool Reservation::collisionCheck(const Reservation &other) const
{
    {
        if (resourceId != other.resourceId)
            return false;
        if (dayIndex != other.dayIndex)
            return false;
        if (timeSlot != other.timeSlot)
        {
            return false;
        }

        return true;
    }
}

void Reservation::print(std::ostream &out) const {
    out << "Reservation ID: " << this->reservationId << "\n" << "Party Name: " << this->username << "\n" << "Day: " << this->dayIndex << "\n" << "Time: " << this->timeSlot;
}

std::ostream &operator<<(std::ostream &out, const Reservation &reservation){
    reservation.print(out);
    return out;
}

bool Reservation::operator==(const Reservation &other){
    if(this->resourceId == other.resourceId 
        && this->timeSlot == other.timeSlot 
        && this->dayIndex == other.dayIndex){
        return true;
    }
    else {
        return false;
    }
}
