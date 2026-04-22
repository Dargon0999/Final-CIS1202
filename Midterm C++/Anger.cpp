#pragma once

#include "GaslightDatabase.h"


void checkLevel(Anger& anger) {
	
	if (anger.angerValue == BASE) {
		anger.angerLevel = BASE;
	}
	else if (anger.angerValue >= MILD) {
		anger.angerLevel = MILD;
	}
	else if (anger.angerValue >= MODERATE) {
		anger.angerLevel = MODERATE;
	}
	else if (anger.angerValue >= VERY) {
		anger.angerLevel = VERY;
	}
	else if (anger.angerValue >= HORROR) {
		anger.angerLevel = HORROR;
	}
}