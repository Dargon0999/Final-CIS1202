#ifndef ANGER_H
#define ANGER_H

#include <string>

//yeah so I did not have the time to actually use this
using namespace std;

enum AngerLevel {HAPPY = 0, BASE = 1, MILD = 3, MODERATE = 5, VERY = 7, HORROR = 10};


class Anger {
private:
	float angerValue;
	AngerLevel angerLevel;
	
public:
	//constructors
	Anger();
	Anger(float);

	//mutators
	void setAngerLevel();
	void setAngerValue(float);
	float getAngerValue();
	AngerLevel getAngerLevel();
	
	//operator overloads
	Anger& operator+=(float);
	Anger& operator-=(float);

	bool operator==(AngerLevel) const;
	bool operator<=(AngerLevel) const;
	bool operator>=(AngerLevel) const;
	bool operator<(AngerLevel) const;
	bool operator>(AngerLevel) const;

};


#endif

