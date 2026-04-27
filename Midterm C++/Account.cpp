#include "Account.h"

Account::Account() : Anger()
{
	cheese = 0;
}

Account::Account(string fName, string lName, string number)
{
	firstName = fName;
	lastName = lName;
	accountNumber = number;
	float angerVal;
	ifstream accessAccount(accountNumber + ".dat", ios::binary);
	accessAccount.seekg(0L, ios::beg);
	accessAccount.read(reinterpret_cast<char*>(&cheese), sizeof(float));
	accessAccount.read(reinterpret_cast<char*>(&angerVal), sizeof(float));
	accessAccount.close();
	setAngerValue(angerVal);
}

Account::~Account()
{
	float angerValue = getAngerValue();
	ofstream createAccount(accountNumber + ".dat", ios::binary | ios::out);
	createAccount.seekp(0L, ios::beg);
	createAccount.write(reinterpret_cast<char*>(&cheese), sizeof(float));
	createAccount.write(reinterpret_cast<char*>(&angerValue), sizeof(float));
	createAccount.close();
}

float Account::getCheese()
{
	return cheese;
}

string Account::getAccountNumber()
{
	return accountNumber;
}

string Account::getName()
{
	string name;

	name = firstName + " " + lastName;

	return name;
}

void Account::depositCheese(float& value)
{
	cheese += value;
}

void Account::withdrawCheese(float& value)
{
	cheese -= value;
}

