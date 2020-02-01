#include <iostream>
#include <conio.h> 
#include <windows.h>
#include <string>

#pragma once
class SecretWord
{
public:
	SecretWord();
	std::string getSecretWord();
	std::string getHiddenSecretWord();
	std::string getTriedLetters();
	bool guessLetter(char pLetter);
	void revealLetter(char pLetter);
	bool hasItBeenTried(char pLetter);
	


private:
	std::string word;
	std::string hiddenWord;
	std::string triedLetter;
};

