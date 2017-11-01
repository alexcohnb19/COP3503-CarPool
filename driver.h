#ifndef DRIVER_H_
#define DRIVER_H_

class Driver{
  private:
    std::string name;
    std::string phoneNum;
    int seats;

  public:
    std::string getName();
    std::string getPhoneNum();
    void setSeats();
    int getSeats();
    Driver();
}

#endif /* DRIVER_H_ */
