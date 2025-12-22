// Reservation.h
// Manages reservation information

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
    bool cancelled{false};

public:
    Reservation();
    Reservation(int id, int t, int d, const std::string &username);
    Reservation(int rsvId, int rscId, int time, int day, const std::string &username); // for file load, no auto generated reservation ID

    int getReservationId() const;
    int getResourceId() const;
    const std::string &getUsername() const;
    int getTimeSlot() const;
    int getDayIndex() const;
    bool isCancelled() const;
    static void incrementIdCount();

    Reservation &setResourceId(int id);
    Reservation &setTimeSlot(int t);
    Reservation &setDayIndex(int d);

    void cancelReservation();
    void printReservation();
    static void printReservationHeader();

    // collision resolution
    bool collisionCheck(const Reservation &other) const;

    void print(std::ostream &out) const;
    friend std::ostream &operator<<(std::ostream &, const Reservation &);
    bool operator==(const Reservation &);
};
