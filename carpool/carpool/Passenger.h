#include <string>

class Passenger {
private:
	std::string phoneNum;
	std::string name;

public:
	Passenger(std::string name, std::string phoneNum);
	std::string getName();
	std::string getPhoneNum();
	void setName(std::string name);
	void setPhoneNum(std::string phoneNum);
};

