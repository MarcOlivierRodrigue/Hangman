#include "SecretWord.h"

SecretWord::SecretWord() {
	while (true)
	{
		char temp = _getch();

		if (temp >= 'a' && temp <= 'z') {
			word.push_back(temp);
			std::cout << '*';
		}
		else if (temp == '\r' || temp == 0x0d) {
			break;
		}
		else if (temp == 8 || temp == 0x08) {
			word = word.substr(0, word.size() - 1);
			std::cout << "\b \b";
		}
		else {
			continue;
		}
	}

	for (std::size_t i = 0; i < word.size(); i++) {
		hiddenWord += '-';
	}
}

std::string SecretWord::getSecretWord() {
	return word;
}

std::string SecretWord::getHiddenSecretWord() {
	return hiddenWord;
}

std::string SecretWord::getTriedLetters() {
	return triedLetter;
}

//Check if the guessed character is part of the secret word///////////////
bool SecretWord::guessLetter(char pLetter) {
	for (std::size_t i = 0; i < this->word.size(); i++) {
		if (pLetter == this->word[i]) {
			triedLetter += pLetter;
			return true;
		}
	}
	triedLetter += pLetter;
	return false;
}

//Reveal the letter of a the hidden secret word /////////////////////////
void SecretWord::revealLetter(char pLetter) {
	for (std::size_t i = 0; i < word.size(); i++) {
		if (pLetter == word[i]) {
			hiddenWord[i] = word[i];
		}
	}
}


bool SecretWord::hasItBeenTried(char pLetter) {
	for (std::size_t i = 0; i < triedLetter.size(); i++) {
		if (pLetter == triedLetter[i]) {
			return true;
		}
	}
	return false;
}




