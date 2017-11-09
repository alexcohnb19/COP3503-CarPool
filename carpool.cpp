#include <iostream>
#include <string.h>
using namespace std;

void viewRides(int eventId){
  cout << "\n\t\t 1. Eric - 2 empty seats\n";
  cout << "\n\t\t 2. Bill - 1 empty seats\n";
  cout << "\n\t\t 3. Robert - 0 empty seats\n";
  cout << "\n\t\t 4. Timothy - 3 empty seats\n";
  cout << "\n\t\t 0. Henry ugly god - 0 empty seats\n";
  cout << "\n\t\t";
}

void eventOptions(){
  cout << "\n\t\t1. Add Driver\n";
  cout << "\t\t2. Add Passenger\n";
  cout << "\t\t3. View Rides\n";
  cout << "\t\t4. Return \n";
  cout << "\t\t\n";
}

void mainOptions(){
  cout << "\n\t1. Add Event\n";
  cout << "\t2. View Events\n";
  cout << "\t3. Done\n";
}

void addDriver(int eventId){
  string name = "";
  string phoneNumber = "";
  int seats = 0;

  cin.ignore();
  cout << "\n\t\t\tDriver name:\n";
  getline( cin, name );

  cout << "\n\t\t\tPhone Number:\n";
  getline( cin, phoneNumber );

  cout << "\n\t\t\tNumber of seats:\n";
  cin >> seats;
  if(seats < 1){
    cout << "\t\t\tFailed to add driver, no available seats.\n"; 
  }else{
    //put in vector
    new driver(phoneNumber, name, seats);
    cout << "\t\t\tDriver added successfully\n";
  }
}

void addPassenger(int eventId){
  string name = "";
  string phoneNumber = "";
  int numSeats;

  cin.ignore();
  cout << "\n\t\t\tDriver name:\n";
  getline( cin, name );

  cout << "\n\t\t\tPhone Number:\n";
  getline( cin, phoneNumber );

  cout << "\n\t\t\tNumber of seats:\n"; //why is this needed? shouldnt it just be 1 seat?
  cin >> numSeats;
  
  if(//check for open seats){
    //put passenger in vector and under car with most seats available
    new passenger(phoneNumber, name);
    cout << "\t\t\tPassenger added successfully\n";
  }else{
    cout << "\t\t\tFailed to add passenger, no available seats\n";
  }
}


// This method also needs to take in an event
void eventMenu(int eventId){
  bool stop = false;

  while( !stop ) {
    int userInput;

    // Print out event details
    eventOptions();
    cin >> userInput;

    if( userInput == 4 ){
      stop = true;
    } else if(userInput == 1){
      addDriver(eventId);
    } else if(userInput == 2){
      addPassenger(eventId);
    } else if(userInput == 3){
      viewRides(eventId);
    } else {
      cout << "\n\t ----- Invalid input -----\n\n";
    }
  }
}

void mainMenu( int userInput ){
  if( userInput == 1 ){
    string name = "";
    string description = "";
    string date = "";
    string location = "";

    cin.ignore();
    cout << "\n\tEvent name:\n";
    getline( cin, name );

    cout << "\n\tEvent description:\n";
    getline( cin, description );

    cout << "\n\tEvent date:\n";
    getline( cin, date );

    cout << "\n\tEvent location:\n";
    getline( cin, date );

    // CREATE EVENT KL:AJGKLJ

    cout << "Event successfully created\n";
  } else if ( userInput == 2 ) {
    int eventId;
    cout << "\n\tSelect an event: \n";

    for(int i = 0; i < 5; ++i) {
      cout << "\n\t" << i+1 << ". This is event ";
    }

    cin >> eventId;

    eventMenu( eventId );

  } else {
    cout << "\n\t ----- Invalid input -----\n\n";
  }
}

int main(){
  bool stop = false;
  int userInput;

  while( !stop ) {
    mainOptions();
    cin >> userInput;
    if(userInput == 3 ){
      stop = true;
    } else {
      mainMenu( userInput );
    }
  }
}
