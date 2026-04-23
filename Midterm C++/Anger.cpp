#pragma once

#include "Anger.h"


// constructors
Anger::Anger() {
	angerValue = 0;
	angerLevel = HAPPY;
}
Anger::Anger(float value) {
	angerValue = value;
	setAngerLevel();
}

//mutators
void Anger::setAngerLevel() {

	if (angerValue == HAPPY) {
		angerLevel = HAPPY;
	}
	else if (angerValue == BASE) {
		angerLevel = BASE;
	}
	else if (angerValue >= MILD) {
		angerLevel = MILD;
	}
	else if (angerValue >= MODERATE) {
		angerLevel = MODERATE;
	}
	else if (angerValue >= VERY) {
		angerLevel = VERY;
	}
	else if (angerValue >= HORROR) {
		angerLevel = HORROR;
	}
}
void Anger::setAngerValue(float value) {
	angerValue = value;
	setAngerLevel();
}

float Anger::getAngerValue() {
	return angerValue;
}

AngerLevel Anger::getAngerLevel() {
	return angerLevel;
}

// operator overloads
Anger& Anger::operator+=(float value) {
	angerValue = angerValue + value;
	setAngerLevel();
	return *this;
}

Anger& Anger::operator-=(float value) {
	angerValue = angerValue - value;
	setAngerLevel();
	return *this;
}

bool Anger::operator==(AngerLevel level) const{
	return (angerLevel == level);
}
bool Anger::operator<=(AngerLevel level) const{
	return (angerLevel <= level);
}
bool Anger::operator>=(AngerLevel level) const{
	return (angerLevel >= level);
}
bool Anger::operator<(AngerLevel level) const{
	return (angerLevel < level);
}
bool Anger::operator>(AngerLevel level) const{
	return (angerLevel > level);
}
// other

