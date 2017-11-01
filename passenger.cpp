#include "passenger.h"

passenger::passenger(string phoneNum, string name) {

  this->phoneNum = phoneNum;
  this->name = name;
}

std::string passenger::getName() {

  return this->name;
}

std::string passenger::getPhoneNum() {

  return this->phoneNum;
}
