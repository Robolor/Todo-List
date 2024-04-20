#include "RoboFunctions.h"
#include "Entry.h"
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

void ClearScreen() {
	system("CLS");
}


void WaitForUser() {
	system("PAUSE");
}

//prints main menu, also checks to see if there are 0 entries and adjusts options accordingly
void MenuText(int i) {
	cout << "What would you like to do today?" << endl << endl;

	if (i == 0) {
		cout << "1. No current items to be displayed. do not select option one" << endl;
	}
	else { cout << "1. Display my TODO list" << endl; }

	cout << "2. Add to my TODO list" << endl;
	cout << "3. I'd like to mark an entry as complete" << endl;
	cout << "4. I'd like to mark an entry as incomplete" << endl;
	cout << "5. I'm done for now" << endl;
}


//passes vector by reference and then passes down to each subsequent function rather than using a global vector
void Mainmenu(vector <Entry>& i) {
	ClearScreen();
	int selection = 0;
	int option = 0;
	int vectorsize = i.size();
	
	MenuText(vectorsize);

	cin >> selection;

	ClearScreen();

	switch (selection) {


		//displays list
	case 1:
		if (vectorsize == 0) {
			cout << "You cannot currently display a list as it is empty." << endl;
		}
		else {
			DisplayTODO(i);
		}
		break;


		//adds an entry (need to test for functionality as i may need to look into how to create new objects without explicitly defining them
	case 2:
		int numEntries;
		ClearScreen();
		cout << "How many entries would you like to add?: ";
		cin >> numEntries;
		AddEntries(numEntries, i);
		break;


		//marks a specific entry as completed and pulls the todo list without clearing the screen first
	case 3:

		cout << "Which entry would you like to mark completed?:" << endl;
		DisplayTODOnoclear(i);
		cout << endl;
		cin >> option;
		i[option - 1].NowComplete();
		break;


		//marks a specific entry as incopmlete and pulls the todo list without clearing the screen first
	case 4:

		cout << "Which entry would you like to mark completed?:" << endl;
		DisplayTODOnoclear(i);
		cout << endl;
		cin >> option;
		i[option - 1].NotComplete();
		break;


		//exits main menu
	case 5:
		return;


		//error checking
	default:
		cout << "invalid choice, please re-enter: " << endl;
		cin >> selection;
		break;

	}

	
	//recursive to keep the user in the menu
	Mainmenu(i);
}






void AddEntries(int i, vector <Entry> &j) {

	ClearScreen();


	for (i; i > 0; i--) {
		Entry newEntry;
		j.push_back(newEntry);
		newEntry.~Entry();
	}
}

//This parses through the entire list and displays the data for each entry
void DisplayTODO(vector <Entry> &j) {
	ClearScreen();
	int numComplete = 0;
	int totalListed = 0;
	int vectorsize = j.size();
	cout << "TODO LIST: " << endl << endl;
	for (int i = 0; i < vectorsize; i++) {

		cout << (i + 1) << ". ";
		//creates a temporary object to store the values of the entries in the array
		//this may not work without pointers BE AWARE IF THE PROGRAM DOES NOT WORK!!!!!!
		Entry temp = j[i];

		//displays the data for the current entry in the array
		temp.DisplayData();

		//tracks whether or not the entry is completed
		if (temp.IsComplete()) {
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
}

//does not clear the screen before diplaying the list, this should be used whenever the user wants to interact with the list rather than just read it
void DisplayTODOnoclear(vector <Entry> &j) {
	int numComplete = 0;
	int totalListed = 0;
	int vectorsize = j.size();
	cout << "TODO LIST: " << endl << endl;
	for (int i = 0; i < vectorsize; i++) {

		cout << (i + 1) << ". ";
		//creates a temporary object to store the values of the entries in the array
		//this may not work without pointers BE AWARE IF THE PROGRAM DOES NOT WORK!!!!!!
		Entry temp = j[i];

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
}