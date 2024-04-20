//TODO List
//Blake Robolor N. 
//Started on 4/6/2024
//Completed on unknown
//This is my first solo/unguided project I expect there to be many challenges and an overarching feeling of reinventing the wheel. I need to share this project in its entirety in different communities upon initial completion and/or after/during major upgrades in functionality
//Hours worked: ~4

/*CHECK NOTES AT BOTTOM OF PAGE*/



#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include "RoboFunctions.h"
#include "Entry.h"


using namespace std;



int main() {
	vector <Entry> Entries;
	//sends user to the main menu/loop for the program
	Mainmenu(Entries);


	//rudimentary way of implementing an exit check, potentially will only work once per runtime
	ClearScreen();
	string confirm = "";
	
	cout << "are you sure you want to exit?: y/n";
	cin >> ws;
	getline(cin, confirm);
	
	WaitForUser();

	if (confirm[0] == 'n') {
		Mainmenu(Entries);
	}
	
	return 0;
}




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