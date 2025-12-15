#include "Reservation.h"
#include <iostream>

int Reservation::reservationIdCount = 1;


Reservation::Reservation() : resourceId(-1), timeSlot(-1), dayIndex(-1), reservationId(-1) {}
Reservation::Reservation(int id, int t, int d, const std::string& username) : resourceId(id), timeSlot(t), dayIndex(d), reservationId(reservationIdCount++) {}
Reservation::Reservation(int rsvId, int rscId, int time, int day, const std::string& username) : reservationId(rsvId), resourceId(rscId), timeSlot(time), dayIndex(day), username(username) {}
int Reservation::getReservationId() const
{
    return reservationId;
}
int Reservation::getResourceId() const
{
    return resourceId;
}
const std::string& Reservation::getUsername() const
{
    return username;
}
int Reservation::getTimeSlot() const
{
    return timeSlot;
}
int Reservation::getDayIndex() const
{
    return dayIndex;
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