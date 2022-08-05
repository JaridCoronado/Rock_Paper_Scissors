#pragma once
#include <iostream>
#include <random>
#include <string>

using namespace std;

namespace RPS_Game
{
	class GameObjects
	{
	public:
		//Getters, cause I'm a noob like that
		int Rock() const { return *ptrRock; }

		int Paper() const { return *ptrPaper; }

		int Scissors() const { return *ptrScissors; }

		int GetPlayerChoice() const { return *ptrPlayerChoice; }

		int GerPlayerPoints() const { return *ptrPlayerPoints; }
		int GetComputerPoints() const { return *ptrComputerPoints; }

		//Some Setters, I guess.
		int SetPlayerPoints(int p) {
			*ptrPlayerPoints += p;
			return *ptrPlayerPoints;
		}

		int SetComputerPoints(int c) {
			*ptrComputerPoints += c;
			return *ptrComputerPoints;
		}

		void PlayerChoice(int p) { *ptrPlayerChoice = p; }

		//Other game functions
		int CPU_Choice();
		void GameStart();
		void GameData();
		void PlayerChoosesRock();
		void PlayerChoosesPaper();
		void PlayerChoosesScissors();
		void GameLoop();

		//Game Messages
		void Winner_msg();
		void Loser_msg();
		void Tie_msg();

		void Print(string p) {
			*ptrMessage = p;
			cout << *ptrMessage;
		}

	private:
		int rock = 0,
			paper = 1,
			scissors = 2;

		int playerChoice,
			playerPoints = 0,
			computerPoints = 0;

		char playAgain;

		string message;

		const int* ptrRock = &rock;
		const int* ptrPaper = &paper;
		const int* ptrScissors = &scissors;

		int* ptrPlayerChoice = &playerChoice;
		int* ptrPlayerPoints = &playerPoints;
		int* ptrComputerPoints = &computerPoints;

		string* ptrMessage = &message;
	};
}