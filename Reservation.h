#pragma once
#include <string>

class Reservation
{
private:
    // School sch;
    static int reservationIdCount;
    int reservationId;
    int resourceId;
    std::string username;
    int timeSlot;
    int dayIndex;

public:
    Reservation();
    Reservation(int id, int t, int d, const std::string& username);
    Reservation(int rsvId, int rscId, int time, int day, const std::string& username);  // for file load, no auto generated reservation ID

    int getReservationId() const;
    int getResourceId() const;
    const std::string& getUsername() const;
    int getTimeSlot() const;
    int getDayIndex() const;

    Reservation &setResourceId(int id);
    Reservation &setTimeSlot(int t);
    Reservation &setDayIndex(int d);

    // collision resolution
    bool collisionCheck(const Reservation &other) const;
};
