#pragma once
#include "Anger.h"
#include <vector>

struct Data {
	float data;
	int week;
};

class Account : public Anger
{
private:
	vector<Data> history;
	float cheese;
	int accountNumber;

public:
	Account();
	Account(int);




};

