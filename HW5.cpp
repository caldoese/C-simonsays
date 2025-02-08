//hw5.cpp-CS1210 Simon Says Homework #5
//Caleb Doese
//September 22, 2021
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <array>
#include <ostream>
#include <unistd.h>
using namespace std;

int main() {

//Start program by having user enter Y
	string yes;
	cout << "Welcome to Simon, Type Y to play" << endl;
	cin >> yes;

//If user enters Y, clear screen and start the game
	if (yes == "Y") {
		cout << "\014" << flush;
	}

//Declare and initialize appropriate variables and arrays
	srand(time(0));
	string Simon = "";
	string User;

	//Make an array of size 4 that holds the four colors
	char colorArray[4]={'R', 'G', 'B', 'Y'};
	int i=0;
	int j=0;

//Play 15 rounds or until user guesses it wrong
	for (i=0;i<15;i++) {

		//Add on one more character to the computer generated string for each iteration
		Simon += colorArray[rand()%4];

		//Display newly added part of array for 2 seconds, then replace it with a period so user must remember
		cout << "Simon says: " << Simon << flush;
		sleep(2);
		cout << "\010." << flush << '\n';
		cout << "Please enter " << i+1 << " character(s) to match" << endl;

		//Get input string from user
		cin >> User;

		//Check if user got it wrong, then they would lose immediately
		if (User!=Simon) {
			cout << "You lose. Better luck next time!" << endl;
			break;
		}

		//Also check if it's the last round, then user would win immediately after first if condition is false
		if (i==14) {
			cout << "Congratulations, you win!" << endl;
			break;
		}
		cout << "\014" << flush;
	}



return 0;
}
