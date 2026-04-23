/*
* 
* Rylan Peets Cheek
* 
* CIS 1202 101
* 3/3/26
*
*/
#include "peetsCUtil.h"
#include "Anger.h"
#include "Account.h"

// used for anger status



// ask user for personal info then get angry
Anger enterPersonal();

//actual database
void enterData(vector<Data>&, Anger&);
void displayData(vector<Data>&, Anger&);
void sortData(vector<Data>&, Anger&);
void searchData(vector<Data>&, float, Anger&, bool);

int main(){

	// major thresholds of anger 
	
	Anger anger;
	int choice;
	float search = 0;
	bool sorted = false;

	vector<Data> dataSet;
	vector<string> menu{"Enter Data", "Display Data", "Sort Data", "Search Data"};


	//ask for personal info only happens first ime you enter program
	if (anger == HAPPY) {


	}

	do {

		cout << "Doge Coin Tracker";

		//visible show of anger in the title by the system
		if (anger > MODERATE) {
			cout << "!";
			if (anger > VERY) {
				for (int i = anger.getAngerValue(); i > VERY; i--) {
					cout << "!!";
				}
			}
		}
		cout << "\n\n";


		choice = makeMenu(menu);

		switch(choice) {

			//enter data
		case 1:

			enterData(dataSet, anger);
			break;
			//display data
		case 2:

			displayData(dataSet, anger);
			break;
			//sort data
		case 3:

			sortData(dataSet, anger);
			break;
			//search data
		case 4:

			cout << "What are you looking for?" << endl;
			while (!(cin >> search) || cin.fail() || (search < 0 || search >= 10000)) {
				
				if (anger < MODERATE) {
					if (search < 0 || search >= 10000) {
						cout << "We don't work with those numbers" << endl;
					}
					else {
						cout << "Thats not exactly a number persay" << endl;
					}
					anger += .3;
				}
				else {
					anger += .1;
				}

				cin.clear();
				cin.ignore(100, '\n');

				

				cout << "What are you looking for?" << endl;
			}
			searchData(dataSet, search, anger, sorted);
			break;
			//exit gaslight
		case 5:

			if (getRes("Are you sure (y/n)", 'y', 'n') == 'n') {
				choice = 0;
			}
			if (anger > VERY) {
				if (getRand(1, 30) == 1) {
					while (choice != 0) {
						if (getRes("Are you sure (y/n)", 'y', 'n') == 'n') {
							choice = 0;
						}
					}
				}
			}
			break;

		}

	} while (choice != menu.size() + 1);

	if (anger < MODERATE) {
		endProgram();
	}
	else if (anger == HORROR) {
		for (int i = 0; i < 2000; i++) {
			cout << getRand(0, 1);
			Sleep(20);
		}
	}
}



//file processing for anger retention


// handles the begining section that initiates the anger system



void enterData(vector<Data>& dataSet, Anger& anger)
{
	float input;
	string num;
	bool valid;
	bool dec;
	const char* value = nullptr;
	Data data;

	do {
		valid = true;
		dec = false;


		cout << "How much Doge Coin did you get this week";

		//space for anger related stuff

		if (anger < MODERATE) {
			cout << "(####.##)";
		}
		else {
			if (getRand(1, 20) == 1) {
				cout << "(";
				for (int i = 0; i < 100; i++) {
					cout << "*";
				}
				cout << ")";
			}
		}

		cout << ": ";

		cin.ignore(100, '\n');
		getline(cin, num);

		//too big
		if (num.size() > 7) {
			valid = false;
		}
		else if (num.size() == 0) {
			valid = false;
		}
		else {

			value = num.c_str();


			for (int i = 0; i < num.size(); i++) {
				if (value[i] == '.') {
					if (i == num.size() - 1 || i == 0) {
						valid = false;
					}
					else if (dec) {
						valid = false;
					}
					else {
						dec = true;
					}
				}
				else if (!isdigit(value[i])) {
					valid = false;
				}

			}

			value = nullptr;

			//If invalid for incorrect forating
			if (!valid) {
				//normal incorrect validation output
				if (anger < MODERATE) {
					cout << "No thats not a number" << endl;
					anger += .5;
				}
				//silent treatment then just being down right upset
				else {
					if (anger == HORROR) {
						cout << ":(" << endl;
					}
					anger += .2;
				}
			}
		}


	} while (!valid);

	input = stof(num);

	data.data = input;
	data.week = dataSet.size() + 1;

	dataSet.push_back(data);
}




void displayData(vector<Data>& dataSet, Anger& anger)
{
	if (anger > VERY) {

		cout << "\n\n\nLoading";
		for (int i = anger.getAngerLevel(); i > MODERATE; i--) {
			Sleep(30000);
			cout << ".";
		}
		cout << endl;
	}
	if (anger > HORROR) {
		cout << "Oo ps I droppe d your d ata com e ba ck later" << endl;
	}
	else {
		cout << setprecision(2) << fixed;
		for (int i = 0; i < dataSet.size(); i++) {
			cout << "Week " << right << setw(3) << dataSet[i].week;
			cout << "\t" << setw(7) << dataSet[i].data << endl;
		}
	}
}

void sortData(vector<Data>& dataSet, Anger& anger)
{
	int i;
	int j;
	int position;

	
	for (i = 0; i < dataSet.size() - 1; i++) {

		position = i;

		for (j = i + 1; j < dataSet.size(); j++) {

			if (dataSet[position].data > dataSet[j].data) {
				position = j;
			}
			swap(dataSet[i], dataSet[position]);
		}
	}
}

void searchData(vector<Data>& dataSet, float search, Anger& anger, bool sorted)
{


	int first = 0;
	int middle;
	int last = dataSet.size() - 1;
	int position = -1;
	bool found = false;

	if (sorted) {
		while (!found && first <= last) {

			middle = (first + last) / 2;

			if (dataSet[middle].data == search) {

				position = middle;
				found = true;
			}

			else if (dataSet[middle].data < search) {

				first = middle + 1;
			}

			else {

				last = middle - 1;
			}

		}
	}
	else {
		for (int i = 0; i < dataSet.size(); i++) {

			if (dataSet[i].data == search) {
				position = i;
				found = true;
			}
		}
	}
	
	if (found) {
		cout << search << " is located in week " << dataSet[position].week << endl;
	}
}
