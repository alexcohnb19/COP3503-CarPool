#include "driver.h"

driver::driver(string phoneNum, string Name, int seats){

  this->phoneNum = phoneNum;
  this->name = name;
  this->seats = seats;
}

std::string driver::getPhoneNume(){
  
  return this->phoneNum;
}

std::string driver::getName(){

  return this->name;
}

std::int driver::getSeats(){

  return this->seats;
}

std::void driver::setSeats(int seats){

  this->seats = seats;
}
