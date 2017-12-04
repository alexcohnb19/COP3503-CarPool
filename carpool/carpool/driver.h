#include <vector>
#include "Passenger.h"

class Driver{
  private:
    std::string name;
    std::string phoneNum;
    std::vector<Passenger*> passengers;
    int seats;

  public:
    std::string getName();
    std::string getPhoneNum();
    void setSeats(int seats);
    int getSeats();
    Driver(std::string phoneNum, std::string Name, int seats);
    bool addPassenger( Passenger * passenger );
    std::vector<Passenger*> getPassengers();
    void deletePassenger();
    void deletePass(int passengerId);
    void viewPassengers();
};


