
#include <iostream>
#include <cassert>

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

void AssertAll(Player Compare, int A_Health, int A_Speed, int A_Strength, int A_Magic) {

	assert(Compare.Health == A_Health);
	assert(Compare.Speed == A_Speed);								// Running asserts with 4 really long &&'d together arguments in each felt too messy, instead i
	assert(Compare.Strength == A_Strength);							// opted to make a function that runs all the asserts so i can use just a small function call.
	assert(Compare.Magic == A_Magic);

}


int main()
{
    
	const Player Test;

	AssertAll(ApplyPotion(Test, HEALTH), 100, 10, 15, 30);
	AssertAll(ApplyPotion(Test, SPEED), 20, 50, 5, 10);
	AssertAll(ApplyPotion(Test, STRENGTH), 60, 25, 200, 30);
	AssertAll(ApplyPotion(Test, MAGIC), 30, 10, 10, 100);

}
