#pragma once
#include <string>

class Reservation
{
private:
    // School sch;
    int resourceId;
    int timeSlot;
    int dayIndex;

public:
    Reservation() : resourceId(-1), timeSlot(-1), dayIndex(-1) {}
    Reservation(int id, int t, int d) : resourceId(id), timeSlot(t), dayIndex(d) {}

    int getResourceId();
    int getTimeSlot();
    int getDayIndex();

    Reservation &setResourceId(int id);
    Reservation &setTimeSlot(int t);
    Reservation &setDayIndex(int d);

    // collision resolution
    bool collisionCheck(const Reservation &other) const;
};
