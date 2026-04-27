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

Account logIn();
bool checkName(string);
bool checkNumber(string);
void createAccount();
void deposit(Account&);
void withdraw(Account&);
void saveAccount(Account);

// gotta love the power of google
void writeString(ofstream&, const string&);
void readString(ifstream&, string&);



int main(){

	int choice;
	Account account;
	vector<string> menu{"Withdraw", "Deposit"};
	cout << fixed << setprecision(2);

	do {

		cout << "Cheese Bank\n" << endl;
		cout << "1). LogIn\n2). Create Account" << endl;
		cout << "Choice: ";
		while (!(cin >> choice) || cin.fail() || choice < 1 || choice > 2) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input";
			cout << "Press enter to continue:";
			cin.get();

			cout << "Cheese Bank\n" << endl;
			cout << "1). LogIn\n2). Create Account" << endl;
			cout << "Choice: ";
		}

		if (choice == 1) {
			try { account = logIn(); }
			catch (string exception) {
				cout << exception;
				choice = 0;
			}
		}
		else if (choice == 2) {
			try { createAccount(); }
			catch (string exception) {
				cout << exception;
				choice = 0;
			}
		}

	} while (choice != 1);

	do {

		cout << "Cheese Bank" << endl;

		cout << "Hello " << account.getName() << ", you have " << account.getCheese() << "lbs of cheese\n" << endl;
		choice = makeMenu(menu);
		cout << endl;

		switch (choice) {

		//withdraw
		case 1:

			if (account.getCheese() == 0) {
				cout << "You have no cheese" << endl;
			}
			else {
				withdraw(account);
			}
			break;
			//Deposit
		case 2:
			
			deposit(account);
			
			break;
			//exit
		case 3:

			if (getRes("Are you sure (y/n): ", 'y', 'n') == 'n') {
				choice = 0;
			}
			break;
		}
		
		if (choice < menu.size() + 1) {
			cout << "Press enter to return to menu";
			cin.ignore(100, '\n');
			cin.get();
		}


	} while (choice != menu.size() + 1);
	
}

Account logIn()
{
	string firstName;
	string lastName;
	string number;
	string check;
	bool valid;

	cout << "\nEnter first name: ";
	cin >> firstName;
	cin.ignore(100, '\n');
	while (!checkName(firstName)) {
		cout << "Name Invalid" << endl;
		cout << "Press enter to continue";
		cin.get();
		cin.ignore(100, '\n');
		cout << endl;

		cout << "\nEnter first name: ";
		cin >> firstName;
		cin.ignore(100, '\n');
	}

	cout << "\nEnter last name: ";
	cin >> lastName;
	cin.ignore(100, '\n');
	while (!checkName(lastName)) {
		cout << "Name Invalid" << endl;
		cout << "Press enter to continue";
		cin.get();
		cin.ignore(100, '\n');
		cout << endl;

		cout << "\nEnter last name: ";
		cin >> lastName;
		cin.ignore(100, '\n');
	}

	cout << "\nEnter account number: ";
	cin >> number;
	cin.ignore(100, '\n');
	while (!checkNumber(number)) {
		cout << "Name Invalid" << endl;
		cout << "Press enter to continue";
		cin.get();
		cin.ignore(100, '\n');
		cout << endl;

		cout << "\nEnter account number: ";
		cin >> number;
		cin.ignore(100, '\n');
	}

	ifstream checkAccount("accounts.dat", ios::binary);
	if (!checkAccount) {
		throw "File Error";
	}
	checkAccount.seekg(0L, ios::beg);
	while (checkAccount.peek() != EOF) {
		readString(checkAccount, check);
		valid = true;
		if (check != firstName) valid = false;
		readString(checkAccount, check);
		if (check != lastName) valid = false;
		readString(checkAccount, check);
		if (check != number) valid = false;

		if (checkAccount.fail()) break;

		if (valid == true) break;
	}
	if (!valid) {
		throw "Invalid LogIn";
	}

	Account account(firstName, lastName, number);

	return account;
}

bool checkName(string name)
{
	bool valid = true;

	if (name.size() > 100) valid = false;
	else {
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name.at(i))) valid = false;
		}
	}

	return valid;
}

bool checkNumber(string number)
{
	bool valid = true;

	if (number.size() < 8 || number.size() > 8) valid = false;
	else {
		for (int i = 0; i < number.size(); i++) {
			if (!isdigit(number.at(i))) valid = false;
		}
	}

	return valid;
}

void createAccount()
{
	string firstName;
	string lastName;
	int num;
	string number;
	string check;
	float startVal = 0.00f;
	bool valid;


	cout << "\nEnter first name: ";
	cin >> firstName;
	cin.ignore(100, '\n');
	while (!checkName(firstName)) {
		cout << "Name Invalid" << endl;
		cout << "Press enter to continue";
		cin.get();
		cin.ignore(100, '\n');
		cout << endl;

		cout << "\nEnter first name: ";
		cin >> firstName;
		cin.ignore(100, '\n');
	}

	cout << "\nEnter last name: ";
	cin >> lastName;
	cin.ignore(100, '\n');
	while (!checkName(lastName)) {
		cout << "Name Invalid" << endl;
		cout << "Press enter to continue";
		cin.get();
		cin.ignore(100, '\n');
		cout << endl;

		cout << "\nEnter last name: ";
		cin >> lastName;
		cin.ignore(100, '\n');
	}

	num = getRand(0, 99999999);
	number = to_string(num);
	while (number.size() < 8) number += "0";

	cout << "\nYour account number is " << number << endl;
	cout << "Press enter to continue";
	cin.get();
	cin.ignore(100, '\n');

	ofstream createAccount("accounts.dat", ios::binary | ios::app);
	if (!createAccount) throw "File Error";
	createAccount.seekp(ios::ate);
	writeString(createAccount, firstName);
	writeString(createAccount, lastName);
	writeString(createAccount, number);
	createAccount.close();

	createAccount.open(number + ".dat", ios::binary);
	createAccount.write(reinterpret_cast<char*> (&startVal), sizeof(float));
	createAccount.write(reinterpret_cast<char*> (&startVal), sizeof(float));
	createAccount.close();
}

void deposit(Account& account)
{
	float cheese;
	cout << "How much cheese do you want to deposit: ";
	while (!(cin >> cheese) || cin.fail() || cheese < 0 || cheese > 1000000000) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nInvalid Input" << endl;
		cout << "How much cheese do you want to deposit: ";
	}
	account.depositCheese(cheese);
}

void withdraw(Account& account)
{
	float cheese;
	cout << "How much cheese do you want to withdraw: ";
	while (!(cin >> cheese) || cin.fail() || cheese < 0 || cheese > account.getCheese()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nInvalid Input" << endl;
		cout << "How much cheese do you want to withdraw: ";
	}
	account.withdrawCheese(cheese);

}
void writeString(ofstream& out, const string& str) {
	size_t len = str.size();
	out.write(reinterpret_cast<char*>(&len), sizeof(len));
	out.write(str.c_str(), len);
}

void readString(ifstream& in, string& str) {
	size_t len;
	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	str.resize(len);
	in.read(&str[0], len);
}
