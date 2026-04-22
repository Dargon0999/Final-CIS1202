#ifndef GaslightDatabase
#define GaslightDatabase

#include <string>


using namespace std;

enum AngerLevel {BASE = 1, MILD = 3, MODERATE = 5, VERY = 7, HORROR = 10};

// Used for the anger system in program
struct Anger {
	//initializes the system
	bool angered;

	//increases the level of the system as they do stuff wrong
	float angerValue;
	AngerLevel angerLevel;
	
};

//for the dataset I realized I should probably make it remember the oder when sorting so I added this
struct Data {
	float data;
	int week;
};

void checkLevel(Anger&);

// There would be some functions that handle the anger system but my util file was conflicting with the struct file

#endif // !GaslightDatabase

