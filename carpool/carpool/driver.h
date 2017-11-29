#include <vector>
class Driver{
  private:
    std::string name;
    std::string phoneNum;
	std::vector<Passenger> passengers;
	int seats;

  public:
    std::string getName();
    std::string getPhoneNum();
    void setSeats(int seats);
    int getSeats();
    Driver(std::string phoneNum, std::string Name, int seats);
	void addPassenger();
};


