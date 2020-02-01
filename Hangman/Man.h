#pragma once
#include <string>
#include <vector>
//TO BE REMOVED/////////////////////
#include <iostream>
///////////////////////////////////


class Man
{
public:
	Man(int nbrLimbs);

	void addLimb();
	int getLimbsLeft();
	std::vector<std::string> getMan();

private: 
	int limbsLeft;
	std::vector<std::string> vectorMan {
		"   ____     ",
		"  |    |    ",
		"  |    o    ",
		"  |   /|\\  ",
		"  |    |    ",
		"  |   / \\  ",
		" _|_        ",
		"|   |______ ",
		"|          |",
		"|__________|"
	};

	char* head = &vectorMan[2][7];
	char* upperBody = &vectorMan[3][7];
	char* lowerBody = &vectorMan[4][7];
	char* leftArm = &vectorMan[3][6];
	char* rightArm = &vectorMan[3][8];
	char* leftLeg = &vectorMan[5][6];
	char* rightLeg = &vectorMan[5][8];
	std::vector<char*> bodyParts{
		 rightLeg, leftLeg, lowerBody, upperBody, rightArm, leftArm, head
	};
};

