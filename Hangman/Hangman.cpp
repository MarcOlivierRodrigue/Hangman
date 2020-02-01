// Hangman.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit
#include <iostream>
#include <windows.h>
#include <ctype.h>
#include <vector>
#include <string>
#include "Man.h"
#include "SecretWord.h"

SecretWord* secretWord;
Man* man;
int lifes;
bool won = false;
std::string hiddenWord;
std::string triedLetter;

void seperator() {
	std::cout << "=======================================================================================" << std::endl;
}

bool playAgain() {
	std::cout << std::endl;
	std::cout << "Wanna play again?(y/n): ";
	std::string yesNo;
	bool responce; 
	while (true) {
		std::cin >> yesNo;
		if (std::cin.good() && isalpha(yesNo[0]) && (yesNo[0] == 'y' || yesNo[0] == 'n') && yesNo.size() == 1) {
			if (yesNo[0]== 'y') {
				responce = true;
				break;
			}
			else {
				responce = false;
				break;
			}
		
		}
		else {
			std::cin.clear();
			std::cout << "ERROR: INVALID INPUT" << std::endl;
			continue;
		}
	}

	return responce;

}

char chooseLetter() {
	std::string chosenLetter;
	std::cout << "Choose a letter(No caps): ";
	while (true) {
		std::cin >> chosenLetter;
		if (std::cin.good() && isalpha(chosenLetter[0]) && chosenLetter[0] >= 'a' && chosenLetter[0] <= 'z' && chosenLetter.size()  == 1) {
			if (secretWord->hasItBeenTried(chosenLetter[0])) {
				std::cout << "ERROR: You already tried that one! Try again" << std::endl;
				continue;
			}
			else {
				return chosenLetter[0];
			}
		}
		else {
			std::cin.clear();
			std::cout << "ERROR: INVALID INPUT" << std::endl;
			continue;
		}
	}

}


void displayUI(std::vector<std::string> phangman, int pLife, std::string pHiddenWord, std::string pTriedLetters) {
	for (std::size_t i = 0; i < phangman.size(); i++) {
		std::cout << phangman[i] << std::endl;
	}
	seperator();
	std::cout << "Secret word: ";
	for (size_t i = 0; i < pHiddenWord.size(); i++) {
		std::cout << pHiddenWord[i] << " ";
	}
	std::cout << std::endl;
	seperator();
	std::cout << "Letters that you've already tried: ";
	for (size_t i = 0; i < pTriedLetters.size(); i++) {
		std::cout << pTriedLetters[i] << "-";
	}
	std::cout << std::endl;

	seperator();
	char chosenLetter = chooseLetter();
	bool isGood = secretWord->guessLetter(chosenLetter);
	if (isGood) {
		secretWord->revealLetter(chosenLetter);
		std::cout << "GOOD JOB!" << std::endl;
	}
	else {
		man->addLimb();
		std::cout << "WRONG!" << std::endl;
		lifes = man->getLimbsLeft();
	}
	seperator();
}


void startGame() {
	//Ask for the secret word//////////////////////////////////////
	std::cout << "Choose a secret word: ";
	secretWord = new SecretWord();
	std::cout << std::endl;
	seperator();

	//Ask for how many lifes they want//////////////////////////////
	int lifeErrorCounter = 0;
	while (true) {
		if (lifeErrorCounter > 0) {
			seperator();
			std::cout << "ERROR: INVALID INPUT*" << std::endl;
		}
		std::cout << "How many chances do you get?(Max 7): ";
		std::cin >> lifes;
		if (!std::cin.good() || !(lifes > 0) || !(lifes <= 7)) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			lifeErrorCounter += 1;
			lifes = 0;
			continue;
		}
		else {
			seperator();
			break;
		}
	}
}

void loseGame(std::vector<std::string> phangman) {
	std::cout << std::endl;
	std::cout << "YOU LOST!!!" << std::endl;
	for (std::size_t i = 0; i < phangman.size(); i++) {
		std::cout << phangman[i] << std::endl;
	}
	std::cout << std::endl;
	seperator();
}

void winGame(std::string pHiddenWord) {
	std::cout << std::endl;
	std::cout << "Secret word: ";
	for (size_t i = 0; i < pHiddenWord.size(); i++) {
		std::cout << pHiddenWord[i];
	}
	std::cout << std::endl << "YOU WON!!!" << std::endl;
	std::cout << std::endl;
	seperator();
}

int main()
{
	startGame();
	man = new Man(lifes);
	while ((lifes != 0) && (won != true)) {
		displayUI(man->getMan(), man->getLimbsLeft(), secretWord->getHiddenSecretWord(), secretWord->getTriedLetters());
		int hiddenCounter = 0;
		for (std::size_t i = 0; i < secretWord->getHiddenSecretWord().size(); i++) {
			if (secretWord->getHiddenSecretWord()[i] == '-') {
				hiddenCounter += 1;
				continue;
			}
			if ((i == (secretWord->getHiddenSecretWord().size() - 1)) && hiddenCounter == 0) {
				won = true;
			}
		}
	}
	if (won == true) {
		winGame(secretWord->getHiddenSecretWord());
		delete man;
		delete secretWord;
	}
	else {
		loseGame(man->getMan());
		delete man;
		delete secretWord;
	}

	if (playAgain()) {
		main();
	}
	else {
		std::cout << "Thank you for playing <3" << std::endl;
		return 0;
	}
}//main 
