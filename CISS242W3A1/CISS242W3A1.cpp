//Created by Jared Alwyn, Sept 11 2017
//Password Verifier

#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <cstring>;
using namespace std;

//Function prototype.
void validatePassword(char[]);

int main() {
	//Named variables, and constants.
	const int size = 16;
	char user_password[size];

	//Intro Message to user and validation.
	cout << "\t\t---Password Verifier---\n\n"
		<< "Enter a password that is at least six characters long:\n"
		<< "contains at least one digit,\n"
		<< "contains at least one uppercase letter,\n"
		<< "at least one lowercase letter,\n"
		<< "and a max of 15 characters in length.\n";
	validatePassword(user_password);
	cout << "\n\n\t\t---Password has been verified!---\n\n"
		<< "\nYour password is valid and has been saved!\n\n";

	//Holds the system open, and closes program.
	system("Pause");
	return 0;
}

//****************************************************
// This is a funtion that will validate the password *
// entered by the user using loops.					 *
//****************************************************
void validatePassword(char password[]) {
	char restart;
	//Uses 4 bool values to determine if password requirments are met.
	//If any values are false, loop will repeat.
	do {
		bool digit = false, lowercase = false, uppercase = false, length = false;
		cout << "Enter your password: ";
		cin.getline(password, 16);
		if (strlen(password) >= 6)
			length = true;
		for (int count = 0; count < strlen(password); count++) {
			if (isalpha(password[count])) {
				if (isupper(password[count]))
					uppercase = true;
				else
					lowercase = true;
			}
			if (isdigit(password[count]))
				digit = true;
		}
		//Runs through if statement and displays error in accordance with bool.
		if (digit != true || lowercase != true || uppercase != true || length != true) {
			restart = 'y';
			cout << "\n\t\t***Error!***\n\n";
			if (lowercase != true)
				cout << "The password must have at least one lowercase letter\n";
			if (uppercase != true)
				cout << "The password must have at least one uppercase letter\n";
			if (digit != true)
				cout << "The password must have at least one digit\n";
			if (length != true)
				cout << "The Password must be at least six characters long\n";
		}
		//If all values are true, do loop is broken.
		else
			restart = 'n';

		//Loop requirments.
	} while (restart == 'y');
}