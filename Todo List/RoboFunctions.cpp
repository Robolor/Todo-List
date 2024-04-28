#include "RoboFunctions.h"
#include "Entry.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <Windows.h>


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

	//altered menu for when there are no entries
	if (i < 1) {
		cout << "1. No current items to be displayed. do not select option one" << endl;
		cout << "2. Add to my TODO list" << endl;
		cout << "3. I'm done for now" << endl;
	}
	else if (i >= 1) {
		cout << "1. Display my TODO list" << endl;
		cout << "2. Add to my TODO list" << endl;
		cout << "3. I'd like to mark an entry as complete" << endl;
		cout << "4. I'd like to mark an entry as incomplete" << endl;
		cout << "5. I'd like to sort my entries by due date" << endl;
		cout << "6. I'm done for now" << endl;
	}


}


//passes vector by reference and then passes down to each subsequent function rather than using a global vector
void Mainmenu(vector <Entry>& i) {
	ClearScreen();
	int selection = 0;
	int option = 0;
	int vectorsize = i.size();
	
	MenuText(vectorsize);

	cin >> selection;

	//verifies that user has selected an option that is valid
	while (vectorsize == 0 && (selection != 1 && selection != 2 && selection != 3)) {
		ClearScreen();

		cout << endl << "Please enter a valid option: " << endl;
		MenuText(vectorsize);
		cin >> selection;
	}

	//corrects input for current logic
	if (vectorsize == 0 && selection == 3) {
		selection = 6;
	}

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


		//adds selected number of entries to the list
	case 2:
		int numEntries;
		ClearScreen();
		cout << "How many entries would you like to add?: ";
		cin >> numEntries;
		AddEntries(numEntries, i);
		break;


		//marks a specified entry as completed and pulls the todo list without clearing the screen first
	case 3:

		cout << "Which entry would you like to mark completed?:" << endl;
		DisplayTODOnoclear(i);
		cout << endl;
		cin >> option;
		i[option - 1].NowComplete();
		break;


		//marks a specified entry as incopmlete and pulls the todo list without clearing the screen first
	case 4:

		cout << "Which entry would you like to mark completed?:" << endl;
		DisplayTODOnoclear(i);
		cout << endl;
		cin >> option;
		i[option - 1].NotComplete();
		break;

	case 5:

		ClearScreen();
		SortByDate(i);
		cout << "Entries sorted. " << endl;
		Sleep(1500);
		break;

		//exits main menu
	case 6:
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

//creates a temporary entry and then adds it to the back of the vector storing all entries
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

//not tested yet, but this should sort the entire list of entries by due date
void SortByDate(vector <Entry>& i) {
	int numEntries = i.size();
	int counter = 0;
	bool sorted = false;

	while (sorted == false) {
		counter = 0;

		//iterates through the whole list and compares each entry to the next one
		for (int j = 1; j < numEntries; j++) {
			//checks to make sure that we aren't comparing to an erroneous entry
			if (counter < numEntries) {
				//creates a temp entry to use to compare against the next entry
				Entry temp = i[counter];
				//creates a temp entry at the next location to compare against the temp
				Entry replace = i[j];

				//compares the years, if the "first" entry has a later year than the "next" entry then we need to swap the two and we can't confirm that list is sorted
				if (temp.ReturnYear() > replace.ReturnYear()) {

					sorted = false;
				
					i[counter] = replace;
					i[j] = temp;
					
					counter++;
					continue;
				}

				//if the year of the "first" entry is earlier than the "next" entry then we can move to the next iteration
				if (temp.ReturnYear() < replace.ReturnYear()) {
					sorted = true;
					counter++;
					continue;
				}

				//if the years are the same then we have to check months
				if (temp.ReturnYear() == replace.ReturnYear()) {

					//compares the months, if the "first" entry has a later month than the "next" entry then we need to swap the two and we can't confirm that the list is sorted
					if (temp.ReturnMonth() > replace.ReturnMonth()) {

						sorted = false;

						i[counter] = replace;
						i[j] = temp;
						counter++;
						continue;
					}

					//if the months are the same then we have to check days
					if (temp.ReturnMonth() == replace.ReturnMonth()) {

						//compares the days, if the "first" entry has a later day than the "next" entry then we need to swap the two and we can't confirm that the list is sorted
						if (temp.ReturnDay() > replace.ReturnDay()) {
							sorted = false;



							i[counter] = replace;
							i[j] = temp;
							counter++;
							continue;
						}

						//if the days are the same OR if the "first" entry has a earlier day than the "next" entry then we can keep them in the same spot and move to the next iteration
						if ((temp.ReturnDay() == replace.ReturnDay()) || (temp.ReturnDay() < replace.ReturnDay())) {
							sorted = true;
							counter++;
							continue;
						}

					}

					//if the years are the same and the month is earlier than the "next" entry then we dont need to swap and can move to the next iteration
					if (temp.ReturnMonth() < replace.ReturnMonth()) {
						sorted = true;
						counter++;
						continue;
					}
				}
			}
				
			
		}



		//if the first pass succeeds then this pass confirms that list is sorted by rechecking each value
		if (sorted == true) {

			//resets counter for the confirmation pass
			counter = 0;

			//iterates through the whole list and compares each entry to the next one
			for (int j = 1; j < numEntries; j++) {

				//checks to make sure that we aren't comparing to an erroneous entry
				if (counter < numEntries) {

					//creates a temp entry to use to compare against the next entry
					Entry temp = i[counter];

					//creates a temp entry at the next location to compare against the temp
					Entry replace = i[j];

					//compares the years, if the list is found to be not sorted then we break from the confirmation loop and set sorted to false. this also will swap the two entries found to be out of order
					if (temp.ReturnYear() > replace.ReturnYear()) {

						sorted = false;

						i[counter] = replace;
						i[j] = temp;

						break;
					}

					//if the year of the "first" entry is earlier than the "next" entry then we can move to the next iteration
					if (temp.ReturnYear() < replace.ReturnYear()) {
						sorted = true;
						counter++;
						continue;
					}

					//if the years are the same then we have to check months
					if (temp.ReturnYear() == replace.ReturnYear()) {

						//compares the months, if the list is found to be not sorted then we break from the confirmation loop and set sorted to false. this also will swap the two entries found to be out of order
						if (temp.ReturnMonth() > replace.ReturnMonth()) {

							sorted = false;

							i[counter] = replace;
							i[j] = temp;

							break;
						}

						//if the months are the same then we have to check days
						if (temp.ReturnMonth() == replace.ReturnMonth()) {

							//compares the days, if the list is found to be not sorted then we break from the confirmation loop and set sorted to false. this also will swap the two entries found to be out of order
							if (temp.ReturnDay() > replace.ReturnDay()) {
								sorted = false;

								i[counter] = replace;
								i[j] = temp;

								break;
							}

							//if the days are the same OR if the "first" entry has a earlier day than the "next" entry then we can keep them in the same spot and move to the next iteration
							if ((temp.ReturnDay() == replace.ReturnDay()) || (temp.ReturnDay() < replace.ReturnDay())) {
								sorted = true;
								counter++;
								continue;
							}
						}

						//if the years are the same and the month is earlier than the "next" entry then we dont need to swap and can move to the next iteration
						if (temp.ReturnMonth() < replace.ReturnMonth()) {
							sorted = true;
							counter++;
							continue;
						}
					}
				}
			}
		}
	}
}

