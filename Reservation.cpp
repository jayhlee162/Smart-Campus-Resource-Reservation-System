#include "Reservation.h"
#include <iostream>

Reservation::Reservation() : resourceId(-1), timeSlot(-1), dayIndex(-1) {}
Reservation::Reservation(int id, int t, int d, const std::string &u) : resourceId(id), timeSlot(t), dayIndex(d), username(u) {}
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
