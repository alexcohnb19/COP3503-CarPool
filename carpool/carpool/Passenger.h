#include <string>

class Passenger {
private:
	std::string phoneNum;
	std::string name;

public:
	Passenger(std::string phoneNum, std::string name);
	std::string getName();
	std::string getPhoneNum();
};

