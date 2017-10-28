#include <iostream>
#include <string.h>
using namespace std;

void eventOptions(){
  cout << "\n\t\t1. Add Driver\n";
  cout << "\t\t2. Add Passenger\n";
  cout << "\t\t3. View Rides\n";
  cout << "\t\t4. Empty seats\n";
  cout << "\t\t5. Return \n";
}

void mainOptions(){
  cout << "\n\t1. Add Event\n";
  cout << "\t2. View Events\n";
  cout << "\t3. Done\n";
}

// This method also needs to take in an event
void eventMenu(int eventId){
  bool stop = false;

  while( !stop ) {
    int actionId;

    // Print out event details
    eventOptions();
    cin >> actionId;

    eventMenu( actionId );
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
