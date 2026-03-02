
#include <iostream>

using namespace std;


enum PotionType {				// These are the potion types for easier feed into switches
	HEALTH,
	SPEED,
	STRENGTH,
	MAGIC
};


struct Player {					// These are the variables that make up the custom data type "Player" and their default values.
	int Health = 30;
	int Speed = 10;
	int Strength = 15;
	int Magic = 30;
};


Player ApplyPotion(Player NewStats, PotionType Type) {

	switch (Type) {											// This switch handles stat changes from potions, the changes in each cases are ordered in the same
		case HEALTH:										// way that they are in the enum they come from, for reading convenience.
			NewStats.Health = 100;
			break;
		case SPEED:
			NewStats.Health -= 10;
			NewStats.Speed = 50;
			NewStats.Strength -= 10;
			NewStats.Magic = 10;
			break;
		case STRENGTH:
			NewStats.Health *= 2;
			NewStats.Speed = 25;
			NewStats.Strength = 200;
			break;
		case MAGIC:
			NewStats.Strength = 10;
			NewStats.Magic = 100;
			break;
	}

	return NewStats;
}


int main()
{
    


}
