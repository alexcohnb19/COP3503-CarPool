class Event{
	private:
		std::string name;
		std::string date;
		std::string time;
		std::string location;
		std::string description;
		std::vector<Driver> drivers;
		
	public:
		std::string getName();
		std::string getDate();
		std::string getTime();
		std::string getLocation();
		std::string getDescription();
		void addDriver(std::string name, std::string phoneNum, int numSeats);
		void addPassenger(std::string name, std::string phoneNum);//Fits them in car with most avaiable seats
		void listRides();//Lists Drivers, their passenger and the Avaiable Number of Seats	
}