// Skynet-Part_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h> // allows me to clear the screen so the screen doesnt become filled up with stuff so it is easier to read


using namespace std;

//allows multiple function to acces these variables
//Binary Search Tries variable
int HK_Tries = 1;
//Linear Search Tries
int Linear_ai_Guess = 0;
//Random Search Tries Variables
int randomSearch_tries = 1;
//Human Tries Variable
int Human_Tries = 1;

//Declares the winner
void winner()
{
	if (Human_Tries < HK_Tries && Linear_ai_Guess && randomSearch_tries)
	{
		cout << "Congratulations! Human player, You win!" << endl;
	}
	else if (HK_Tries < Linear_ai_Guess && randomSearch_tries && Human_Tries)
	{
		cout << "Congratulations! Binary AI, You win!" << endl;
	}
	else if (Linear_ai_Guess < HK_Tries && randomSearch_tries && Human_Tries)
	{
		cout << "Congratulations! Linear AI, You win!" << endl;
	}
	else if (randomSearch_tries < HK_Tries && Linear_ai_Guess && Human_Tries)
	{
		cout << "Congratulations! Random AI, You win!" << endl;
	}
	return;
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); //seeds the randon number generator
	char again = 'y'; //Variable that controls the loop

	//Displays the start of the program
	cout << "Generating random enemy location on 8x8 Grid...\n";
	cout << "The enemy is located somewhere between 1 and 64\n";
	cout << "=================================================================================\n";
	
	//start of the loop of the program
	do
	{
		//Initializes Variables
		int Hostile = rand() % 64 + 1; // Chooses a randon number between 1 and 64
		int SearchHighNumber = 64;
		int SearchLowNumber = 1;

		//Guess Variables
		int HK_Guess = NULL;
		int randomSearch = NULL;
		int Human_Guess = NULL;

		//Resets the Tries Variables if it loops
		HK_Tries = 1;
		Linear_ai_Guess = 1;
		randomSearch_tries = 1;
		Human_Tries = 1;

		//Binary Search Method
		do
		{
			//Makes HK use Binary Search
			HK_Guess = ((SearchHighNumber - SearchLowNumber) / 2) + SearchLowNumber;
			if (HK_Guess < Hostile)
			{
				SearchLowNumber = HK_Guess++;
				HK_Tries++;
			}
			else if (HK_Guess > Hostile)
			{
				SearchHighNumber = --HK_Guess;
				HK_Tries++;
			}
		} while (HK_Guess != Hostile);
		
		//Linear Search Method
		while (Linear_ai_Guess != Hostile)
		{
			Linear_ai_Guess++;
		} 
		
		//Random Search Method
		while (randomSearch != Hostile)
		{
			randomSearch = rand() % 64 + 1;
			if (randomSearch > Hostile)
			{
				randomSearch_tries++;
			}
			else if (randomSearch != Hostile)
			{
				randomSearch_tries++;
			}
		}
		
		//Human Search Method
		while (Human_Guess != Hostile)
		{
			cout << "Where do you think the enemy is?" << endl;
			cin >> Human_Guess; //This makes the human guess again everytime it loops
			system("cls");
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
				cout << "=================================================================================\n" << endl;
				Human_Tries++;
			}
		}
		
		//keeps screen clear
		system("cls");

		//Displays High Scores
		cout << "************************************************************************************************\n" << endl;
		cout << "All drones have now found the enemy.\n";
		cout << "The enemy was hiding at " << Hostile << "\n\n";
		cout << "The Human Player using human search took " << Human_Tries << " to find the enemy location\n";
		cout << "The AI Player using Linear search took " << Linear_ai_Guess << " to find the enemy locaion\n";
		cout << "The AI Player using Random search took " << randomSearch_tries << " to find the enemy location\n";
		cout << "The AI Player using Binary Search took " << HK_Tries << " to find the enemy location\n\n";
		winner(); //Declares winner
		cout << "************************************************************************************************\n\n";
		cout << "Would you like to play again?\n y = Yes \n n = no" << endl;
		cin >> again;

		//clears the screen so old run doesnt stay on
		system("cls");

	} while (again != 'n');
	cout << "Goodbye.\n";

    return 0;
}

