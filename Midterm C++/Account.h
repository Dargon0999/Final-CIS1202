#pragma once
#include "Anger.h"
#include "fstream"
#include <vector>

using namespace std;

class Account : public Anger
{
private:
	string firstName;
	string lastName;
	float cheese;
	string accountNumber;

public:

	Account();
	Account(string, string, string);

	~Account();

	float getCheese();
	string getAccountNumber();
	string getName();

	void depositCheese(float&);
	void withdrawCheese(float&);

};

