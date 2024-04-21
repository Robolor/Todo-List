#pragma once
#include <string>

using namespace std;

class Entry 
{
private:
	//tracks data for each entry, can add or subtract data from here to potentially add functionality later (will require new functions being created to parse new data being tracked)
	string shortDescription;
	string longDescription;
	int month;
	int day;
	int year;
	bool complete = false;

public:

	//Contructor
	Entry();

	//destructor
	~Entry();

	int ReturnYear() const;
	int ReturnMonth() const;
	int ReturnDay() const;
	//prints out the data held in each entry since the values are private
	void DisplayData();
	//returns whether or not the entry is complete (usable for adding to the display menu as to whether or not the entry is completed later gui implementation could add a checkbox)
	bool IsComplete() const;
	//marks the entry as complete
	void NowComplete();
	//marks the entry as incomplete
	void NotComplete();
};