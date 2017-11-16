#include <string>
#include <vector>
#include "driver.h"

class Event{
	private:
		std::string name;
		std::string date;
		std::string time;
		std::string location;
		std::string description;
		std::vector<Driver> drivers;
		
	public:
		Event(std::string name, std::string date, std::string description, std::string time, std::string location);
		std::string getName();
		std::string getDate();
		std::string getTime();
		std::string getLocation();
		std::string getDescription();
		void setName(std::string newName);
		void setDate(std::string newDate);
		void setTime(std::string newTime);
		void setLocation(std::string newLocation);
		void setDescription(std::string newDescription);
		void addDriver(std::string name, std::string phoneNum, int numSeats);
		void addPassenger(std::string name, std::string phoneNum);//Fits them in car with most avaiable seats
		void listRides();//Lists Drivers, their passenger and the Avaiable Number of Seats	
		void deleteDriver(std::string driver);
		void deletePassenger(std::string passenger);
};

