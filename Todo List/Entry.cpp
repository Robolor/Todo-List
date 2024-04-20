#include "Entry.h"
#include <iostream>
using namespace std;

	Entry::Entry() {

		//Creating a title/shortdescription
		string choice;
		cout << "Enter the Title for the entry: " << flush;
		//used to clear input buffer as cin was used previously and does not play well with getline
		cin >> ws;
		getline(cin, shortDescription);
		cout << endl;

		//asking the user if they would like to enter the long description now or later
		cout << "Would you like to enter a description now? y/n  " << flush;
		getline(cin, choice);
		cout << endl;

		//if they decide to enter it now then pull the long description into a string
		if (choice[0] == 'y') {
			cout << "Enter the description: " << endl;
			getline(cin, longDescription);
			cout << endl;
		}

		//this may need redone, originally the thought was to use a string and then convert the entered data to individual integers for the month day and year
		//current iteration is to just have them enter as numbers and separate their entries with a /
		cout << "Enter the date this needs to be completed by in the form of MM/DD/YYYY: " << endl;

		//First attempt at verifying input for date as well as making date tracked as a set of ints
		bool goodInput = false;
		do {
			cin >> month; cout << "/"; cin >> day; cout << "/"; cin >> year; cout << endl;
			
			if ((month < 1 || month > 12) || (day < 1 || day > 31) || (year < 0 || year > 9999)) {
				cout << endl << "Please re-enter the date with appropriate values in the form of MM/DD/YYYY: " << endl;
			}
			else {
				goodInput = true;
				//fixing input stream for getline usage
				cin >> ws;
			}
		} while (goodInput != true);
	}

	//destroys object
	Entry::~Entry() {}


	//prints out the data held in each entry since the values are private
	void Entry::DisplayData() {
		cout << shortDescription << endl;
		cout << "this is due by: " << month << "/" << day << "/" << year << endl;
		cout << longDescription;
		cout << endl;
		if (complete == true) {
			cout << "This entry is completed" << endl;
		}
		else {
			cout << "This entry is not complete yet" << endl;
		};
		cout << endl;
	}
	//returns whether or not the entry is complete (usable for adding to the display menu as to whether or not the entry is completed later gui implementation could add a checkbox)
	bool Entry::IsComplete() const {
		return complete;
	}
	//marks the entry as complete
	void Entry::NowComplete() {
		complete = true;
	}
	//marks the entry as incomplete
	void Entry::NotComplete() {
		complete = false;
	}
