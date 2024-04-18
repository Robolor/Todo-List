//TODO List
//Blake Robolor N. 
//Started on 4/6/2024
//Completed on unknown
//This is my first solo/unguided project I expect there to be many challenges and an overarching feeling of reinventing the wheel. I need to share this project in its entirety in different communities upon initial completion and/or after/during major upgrades in functionality
//Hours worked: ~2

/*CHECK NOTES AT BOTTOM OF PAGE*/



#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include "RoboFunctions.h"
#include "Entry.h"


using namespace std;

/*class Entry {
private:
	//tracks data for each entry, can add or subtract data from here to potentially add functionality later (will require new functions being created to parse new data being tracked)
	string shortDescription = "";
	string longDescription = "";
	string month = "";
	string day = "";
	string year = "";
	bool complete = false;

public:

	Entry() {

		//Creating a title/shortdescription
		string choice;
		cout << "Enter the Title for the entry: " << flush;
		//used to clear input buffer as cin was used previously and does not play well with getline
		cin >> ws;
		getline(cin, shortDescription);  
		cout << endl;

		//asking the user if they would like to enter the long description now or later
		cout << "Would you like to enter a description now? y/n" << flush;
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
		cout << "Enter the date this needs to be completed by in the form of MM/DD/YYYY: " << flush;
		getline(cin, month); cout << "/"; getline(cin, day); cout << "/"; getline(cin, year); cout << endl;
	
	}
	//destroys object
	~Entry(){}


	//prints out the data held in each entry since the values are private
	void DisplayData() {
		cout << shortDescription << endl;
		cout << "this is due by: " << month << "/" << day << "/" << year << endl;
		if (complete == true) {
			cout << "This entry is completed" << endl;
		}
		else {
			cout << "This entry is not complete yet" << endl;
		};
		cout << longDescription;
		cout << endl;
	}
	//returns whether or not the entry is complete (usable for adding to the display menu as to whether or not the entry is completed later gui implementation could add a checkbox)
	bool IsComplete() const {
		return complete;
	}
	//marks the entry as complete
	void NowComplete() {
		complete = true;
	}
	//marks the entry as incomplete
	void NotComplete() {
		complete = false;
	}



};*/






//global variable to hold the list of entries, need to look into a way to do this more securely, potentially pass the entire vector down the string of functions?








/*
void DisplayTODOnoclear();
void Mainmenu();
void DisplayTODO();
void AddEntries(int i);
void WaitForUser();
void ClearScreen();
*/







int main() {
	vector <Entry> Entries;
	//sends user to the main menu/loop for the program
	Mainmenu(Entries);


	//rudimentary way of implementing an exit check, potentially will only work once per runtime
	ClearScreen();
	string confirm = "";
	
	cout << "are you sure you want to exit?: y/n";
	
	getline(cin, confirm);
	
	if (confirm[0] == 'n') {
		Mainmenu(Entries);
	}
	
	return 0;
}







/*void Mainmenu() {
	ClearScreen();
	int selection = 0;
	int option = 0;
	int vectorsize = Entries.size();
	cout << "What would you like to do today?" << endl << endl;

	if (vectorsize == 0) {
		cout << "1. No current items to be displayed. do not select option one" << endl;
	}
	else { cout << "1. Display my TODO list" << endl; }

	cout << "2. Add to my TODO list" << endl;
	cout << "3. I'd like to mark an entry as complete" << endl;
	cout << "4. I'd like to mark an entry as incomplete" << endl;
	cout << "5. I'm done for now" << endl;

	cin>>selection;

	ClearScreen();

	switch (selection) {


			//displays list
		case 1:
			if (vectorsize == 0) {
				cout << "You cannot currently display a list as it is empty." << endl;
			}
			else {
				DisplayTODO();
			}
			break;
			
			
			//adds an entry (need to test for functionality as i may need to look into how to create new objects without explicitly defining them
		case 2:
			int numEntries;
			ClearScreen();
			cout << "How many entries would you like to add?: ";
			cin >> numEntries;
			AddEntries(numEntries);
			break;
			
			
			//marks a specific entry as completed and pulls the todo list without clearing the screen first
		case 3:
			
			cout << "Which entry would you like to mark completed?:" << endl;
			DisplayTODOnoclear();
			cout << endl;
			cin >> option;
			Entries[option-1].NowComplete();
			break;
			
			
			//marks a specific entry as incopmlete and pulls the todo list without clearing the screen first
		case 4:
			
			cout << "Which entry would you like to mark completed?:" << endl;
			DisplayTODOnoclear();
			cout << endl;
			cin >> option;
			Entries[option-1].NotComplete();
			break;
			
			
			//exits
		case 5:
			return;
			
			
			//error checking
		default:
			cout << "invalid choice, please re-enter: " << endl;
			cin >> selection;
			break;

		}






		Mainmenu();
}*/







/*void ClearScreen() {
	system("CLS");
}


void WaitForUser() {
	system("PAUSE");
}*/






//does not clear the screen before diplaying the list, this should be used whenever the user wants to interact with the list rather than just read it
/*void DisplayTODOnoclear() {
	int numComplete = 0;
	int totalListed = 0;
	int vectorsize = Entries.size();
	cout << "TODO LIST: " << endl << endl;
	for (int i = 0; i < vectorsize; i++) {

		cout << (i + 1) << ". ";
		//creates a temporary object to store the values of the entries in the array
		//this may not work without pointers BE AWARE IF THE PROGRAM DOES NOT WORK!!!!!!
		Entry temp = Entries[i];

		//displays the data for the current entry in the array
		temp.DisplayData();

		//tracks whether or not the entry is completed
		if (temp.IsComplete()) {
			numComplete++;
		}

		cout << endl << endl;
		//tallies the total number of entries
		totalListed++;
	}

	cout << endl << endl;
	cout << numComplete << " out of " << totalListed << " tasks are complete.";
	cout << endl;
	WaitForUser();
}*/




//This parses through the entire list and displays the data for each entry
/*void DisplayTODO() {
	ClearScreen();
	int numComplete = 0;
	int totalListed = 0;
	int vectorsize = Entries.size();
	cout << "TODO LIST: " << endl << endl;
	for (int i = 0; i < vectorsize; i++) {

		cout << (i + 1) << ". ";
		//creates a temporary object to store the values of the entries in the array
		//this may not work without pointers BE AWARE IF THE PROGRAM DOES NOT WORK!!!!!!
		Entry temp = Entries[i];
		
		//displays the data for the current entry in the array
		temp.DisplayData();
		
		//tracks whether or not the entry is completed
		if(temp.IsComplete()){
			numComplete++;
		}

		cout << endl;
		//tallies the total number of entries
		totalListed++;
	}

	cout << endl << endl;
	cout << numComplete << " out of " << totalListed << " tasks are complete.";
	cout << endl;
	WaitForUser();
}*/







/*void AddEntries(int i) {

	ClearScreen();


	for (i; i > 0; i--) {
		Entry newEntry;
		Entries.push_back(newEntry);
		newEntry.~Entry();
	}
}*/











/*
ADD ALL FUTURE AND CURRENTLY WORKED ON FUNCTIONALITY TO THIS LIST
 
 
TODO LIST (for the TODO list)




in development:

-Create new entries									done
-Name entry upon creation							done
-Entries will have a title(name/short description) 	done
-full description									done	
Date need to be completed by						in progress, initial implementation is not pretty and easily misused
-check for complete or not (bool)					done
List out entries									in progress, needs beutified for output
dynamic number of entries							"done" (through vector, not finalized need to further test and look into ways to clean this up because global variables are not good practice)







future functionality:


ability to add a description to an empty entry		incomplete
ability to edit a description for an entry			incomplete (this may pair into the functionality listed above)
priority sort										incomplete
{able to set a priority								incomplete
perhaps using a number system 1 for top priority}	incomplete
make long description hidden until selected			incomplete (might require a complete overhaul of the display list function, might also require creating a gui, otherwise will require clearing screen and reprinting)
add a countdown until task is overdue				incomplete
pull current time information from system			incomplete
convert string form of date into int				incomplete
add time of day that task needs completed by		incomplete
*/