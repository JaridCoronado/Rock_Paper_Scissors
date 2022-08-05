#include "GameObjects.h";

using namespace RPS_Game;

GameObjects g;

random_device rd;  //Will be used to obtain a seed for the random number engine
mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
uniform_int_distribution<> distrib(0, 2);

//this function will allow he player to loop the game.
void GameObjects::GameLoop()
{
	char c;
	cout << "Do you want to play Rock, Paper, Scissors?\nEnter y or n: ";
	cin >> c;

	switch (c) {
	case 'y':
		GameStart();
		break;

	case 'Y':
		GameStart();
		break;

	case 'n':
		Print("Goodbye!");
		break;
	case 'N':
		Print("Goodbye!");
		break;

	default:
		Print("\nLooks like someone didn't read the instructions...\nWell fuck off then asshat!\n\n");
		break;
	}
}

void GameObjects::GameStart() {
	int pc;

	cout << "\nEnter " << g.Rock() << " to choose rock.\nEnter " 
								<< g.Paper() << " to choose paper.\nEnter "
								<< g.Scissors() << " to choose scissors.\n\n" 
								<<"Enter here: ";

	cin >> pc;
	cout << endl;

	g.PlayerChoice(pc);
	GameData();
}

//Where the game fucking happens
void GameObjects::GameData() {
	switch (g.GetPlayerChoice()) {
	case 0: //Player chooses rock
		PlayerChoosesRock();
		GameLoop();
		break;

	case 1: //Player chooses paper
		PlayerChoosesPaper();
		GameLoop();
		break;

	case 2: //Player chooses scissors
		PlayerChoosesScissors();
		GameLoop();
		break;

	default: //If the player chooses any number that is not rock, paper, or scissors.
		cout << "Welp, I dont know what to say...\nYou can't seem to follow directions.\n\nSo here, do it again you dumb shit!\n\n";
		GameLoop();
		break;
	}
}

//The stuff behind player choosing rock
void GameObjects::PlayerChoosesRock() {
	switch (CPU_Choice()) {
	case 0:
		Print("Player chooses: Rock.\nCPU Chooses: Paper.\n");
		Tie_msg();
		break;

		//Player looses because Paper > Rock
	case 1:
		Print("Player chooses: Rock.\nCPU Chooses: Paper.\n");
		Loser_msg();
		break;

		//Player wins cause Rock > Scissors
	case 2:
		Print("Player chooses: Rock.\nCPU Chooses: Scissors.\n");
		Winner_msg();
		break;

	default:
		Print("Welp, I don't know how the computer would of chosen this...\nOh well might as well crash!\n");
		break;
	}
}

//The fucntion where if player chooses paper
void GameObjects::PlayerChoosesPaper() {
	switch (CPU_Choice()) {
	case 0: //Player wins
		Print("Player chooses: Paper.\nCPU Chooses: Rock.\n");
		Winner_msg();
		break;
	case 1: //Tie breaker
		Print("Player chooses: Paper..\nCPU Chooses: Paper.\n");
		Tie_msg();
		break;

	case 2://Player loses
		Print("Player chooses: Paper.\nCPU Chooses:Scissors.\n");
		Loser_msg();
		break;

	default:
		Print("Welp, I don't know how the computer would of chosen this...\nOh well might as well crash!\n");
		break;
	}
}

void GameObjects::PlayerChoosesScissors() {

	switch (CPU_Choice()) {
	case 0: //Losing condition
		Print("Player chooses: Scissors.\nCPU Chooses: Rock.\n");
		Loser_msg();
		break;

	case 1: //Winning for player choosing scissors
		Print("Player chooses: Scissors.\nCPU Chooses: Paper.\n");
		Winner_msg();
		break;

	case 2:// Tie Breaker
		Print("Player chooses: Scissors.\nCPU Chooses: Scissors.\n");
		Tie_msg();
		break;

	default:
		Print("Welp, I don't know how the computer would of chosen this...\nOh well might as well crash!\n");
		break;
	}
}

void GameObjects::Winner_msg() {
	g.SetPlayerPoints(1); //Player gets a point
	Print("Congrats! You've won!\n\n");
	cout << "Player Score: " << g.GerPlayerPoints() << ".\nComputer Score: " << g.GetComputerPoints() << ".\n\n";
}

void GameObjects::Loser_msg() {
	g.SetComputerPoints(1);//Computer gets a point
	Print("Welp, look who sucks now looser!\n\n");
	cout << "Player Score: " << g.GerPlayerPoints() << ".\nComputer Score: " << g.GetComputerPoints() << ".\n\n";
}

void GameObjects::Tie_msg() {
	Print("You've tied!\n\n");
	cout << "Player Score: " << g.GerPlayerPoints() <<".\nComputer Score: " << g.GetComputerPoints()<<".\n\n";
}

int GameObjects::CPU_Choice() {
	int i = distrib(gen);
	return i;
}