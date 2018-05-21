// Skynet-Part_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h> // allows me to clear the screen so the screen doesnt become filled up with stuff so it is easier to read

using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0))); //seeds the randon number generator
	int Hostile = rand() % 64 + 1; // Chooses a randon number between 1 and 64
	char again = 'y'; //Variable that controls the loop

	cout << "Generating random enemy location on 8x8 Grid...\n";
	cout << "The enemy is located somewhere between 1 and 64\n";
	

	do
	{
		
		int HK_Tries = 1;
		int SearchHighNumber = 64;
		int SearchLowNumber = 1;
		int HK_Guess = ((SearchHighNumber - SearchLowNumber) / 2) + SearchLowNumber;
		do
		{

			HK_Guess = ((SearchHighNumber - SearchLowNumber) / 2) + SearchLowNumber;
			cout << HK_Guess;
			if (HK_Guess < Hostile)
			{
				SearchLowNumber = HK_Guess;
				HK_Tries++;
			}
			else if (HK_Guess > Hostile)
			{
				SearchHighNumber = HK_Guess;
				HK_Tries++;
			}
			else if (HK_Guess == Hostile)
			{
				break;
			}
		} while (HK_Guess != Hostile);
		 
		int Linear_ai_Tries = 1;
		SearchHighNumber = 64;
		SearchLowNumber = 1;
		int Linear_ai_Guess = 0;
		do
		{
			if (Linear_ai_Guess < Hostile)
			{
				Linear_ai_Tries++;
			}
			else if (Linear_ai_Tries > Hostile)
			{
				Linear_ai_Tries++;
			}
			else if (Linear_ai_Guess == Hostile)
			{
				break;
			}
		} while (Linear_ai_Guess != Hostile);
		
		int Human_Tries = 1;
		SearchHighNumber = 64;
		SearchLowNumber = 1;
		int Human_Guess;

		cout << "Where do you think the target is?\n";
		do
		{
			cin >> Human_Guess; //This makes the human guess again everytime it loops
			cout << "=================================================================================\n";
			cout << "Guess #" << Human_Tries << ".\n";
			if (Human_Guess > Hostile)
			{
				cout << "The target location Prediction of " << Human_Guess << " Was higher than the actual enemy location.\n";
				cout << "=================================================================================\n";
				Human_Tries++;

			}
			else if (Human_Guess < Hostile)
			{
				cout << "The target location prediction of " << Human_Guess << " was lower than the actual enemy location.\n";
				cout << "=================================================================================\n";
				Human_Tries++;
			}
			else if (Human_Guess == Hostile)
			{
				break;
			}
		} while (Human_Guess != Hostile);
		cout << "************************************************************************************************\n";
		cout << "All drones have now found the enemy.\n";
		cout << "The enemy was hiding at " << Hostile << "\n\n";
		cout << "The Human Player using huan search took " << Human_Tries << " to find the enemy location\n";
		cout << "The AI Player using Linear search took " << Linear_ai_Tries << " to find the enemy locaion\n";
		cout << "The AI Player using Random search took " << HK_Tries << "to find the enemy location\n";
		cout << "************************************************************************************************\n\n";
		cout << "Would you like to play again?\n y = Yes \n n = no";
		cin >> again;
	} while (again != 'n');
	cout << "Goodbye.\n";

    return 0;
}

