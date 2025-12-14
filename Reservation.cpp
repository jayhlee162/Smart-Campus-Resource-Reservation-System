#include "Reservation.h"
#include <iostream>

Reservation::Reservation() : resourceId(-1), timeSlot(-1), dayIndex(-1) {}
Reservation::Reservation(int id, int t, int d) : resourceId(id), timeSlot(t), dayIndex(d) {}

int Reservation::getResourceId()
{
    return resourceId;
}
int Reservation::getTimeSlot()
{
    return timeSlot;
}
int Reservation::getDayIndex()
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
get fetch origin